CXXFLAGS = -std=c++17 -Wall -Wextra -O3
LDLIBS = -lstdc++

all: word_iter_test word_iter_benchmark

.PHONY: all

word_iter_test.o: word_iter_test.cpp word_iter.hpp

word_iter_benchmark.o: word_iter_benchmark.cpp word_iter.hpp
