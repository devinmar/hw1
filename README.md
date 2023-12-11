ULListStr README

Files
1. ulliststr.h: Header for ULListStr
2. ulliststr.cpp: Implements ULListStr
3. ulliststr_test.cpp: Tests for ULListStr

Compile:
g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o ulliststr_test

Run:
./ulliststr_test

Valgrind - Check for memory issues:
valgrind ./ulliststr_test

Functions
1. Add/remove elements: push_back, push_front, pop_back, pop_front.
2. Access elements: back, front, get.
3. List status: size, empty.
4. Clear list: clear.