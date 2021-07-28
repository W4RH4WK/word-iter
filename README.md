# Word Iterator

Simple C++ iterator that iterates over words in a string.
Delimiter can be customized.

```
$ make
$ ./word_iter_test
$ ./word_iter_benchmark
regex duration:     72us (44)
WordIter duration: 3us (44)
boost duration:   28us (44)

$ lscpu | grep 'Model name'
Model name:          Intel(R) Core(TM) i5-6300U CPU @ 2.40GHz
```
