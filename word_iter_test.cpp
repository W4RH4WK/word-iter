#include <cassert>
#include <iostream>
#include <string>

#include "word_iter.hpp"

int main()
{
	const auto end = WordIter();

	{
		const std::string input = "a b";
		auto it = WordIter(input);
		assert(it != end);
		assert(*it == "a");
		it++;
		assert(it != end);
		assert(*it == "b");
		it++;
		assert(it == end);
	}

	{
		const std::string input = "";
		auto it = WordIter(input);
		assert(it != end);
		assert(it->empty());
		it++;
		assert(it == end);
	}

	{
		const std::string input = "a";
		auto it = WordIter(input);
		assert(it != end);
		assert(*it == "a");
		it++;
		assert(it == end);
	}

	{
		const std::string input = " ";
		auto it = WordIter(input);
		assert(it != end);
		assert(it->empty());
		it++;
		assert(it != end);
		assert(it->empty());
		it++;
		assert(it == end);
	}

	{
		const std::string input = "a ";
		auto it = WordIter(input);
		assert(it != end);
		assert(*it == "a");
		it++;
		assert(it != end);
		assert(it->empty());
		it++;
		assert(it == end);
	}
}
