#pragma once

#include <algorithm>
#include <cassert>
#include <string>

// Simple iterator that iterates over words in a string. Delimiter can be
// customized.
class WordIter {
  public:
	WordIter() {}

	explicit WordIter(std::string_view input, char delimiter = ' ') : m_input(input), m_delimiter(delimiter)
	{
		const auto firstEnd = std::find(m_input.begin(), m_input.end(), m_delimiter);
		const auto firstSize = std::distance(m_input.begin(), firstEnd);
		m_current = std::string_view(m_input.begin(), firstSize);

		assert(m_current.begin() >= m_input.begin());
		assert(m_current.end() <= m_input.end());
	}

	const std::string_view& operator*() const { return m_current; }

	const std::string_view* operator->() const { return &m_current; }

	WordIter& operator++()
	{
		next();
		return *this;
	}

	WordIter operator++(int)
	{
		const auto old = *this;
		next();
		return old;
	}

  private:
	void next()
	{
		if (m_current.end() == m_input.end()) {
			m_current = {};
			return;
		}

		const auto nextBegin = m_current.end() + 1;
		const auto nextEnd = std::find(nextBegin, m_input.end(), m_delimiter);
		const auto nextSize = std::distance(nextBegin, nextEnd);
		m_current = std::string_view(nextBegin, nextSize);

		assert(m_current.begin() >= m_input.begin());
		assert(m_current.end() <= m_input.end());
	}

	const std::string_view m_input;
	const char m_delimiter = '\0';

	std::string_view m_current;

	friend bool operator==(const WordIter& a, const WordIter& b)
	{
		return a.m_current.begin() == b.m_current.begin() && a.m_current.size() == b.m_current.size();
	}
	friend bool operator!=(const WordIter& a, const WordIter& b) { return !(a == b); }
};
