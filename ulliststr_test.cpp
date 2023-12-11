/* Write your test code for the ULListStr in this file */

// #include <iostream>
// using namespace std;


// int main(int argc, char* argv[])
// {

//   return 0;
// }


#include "ulliststr.h"
#include <iostream>
#include <cassert>

// test for adding elements to both the front and back of the list
void testPushBackAndFront() {
    ULListStr dat;
    dat.push_back("A");  // adds A to the back of the list
    dat.push_front("B"); // adds'B to the front of the list
    // asserts to check the order of elements and size of the list
    assert(dat.get(0) == "B" && dat.get(1) == "A");
    assert(dat.size() == 2);
    std::cout << "testPushBackAndFront passed." << std::endl;
}

// test for removing elements from both the front and back of the list
void testPopBackAndFront() {
    ULListStr dat;
    dat.push_back("A");
    dat.push_back("B");
    dat.pop_back();  // removes element from the back of the list
    // checks if the last element is A after popping the back
    assert(dat.back() == "A");
    dat.pop_front(); // removes element from the front of the list
    // checks if the list is empty after popping the front
    assert(dat.empty());
    std::cout << "testPopBackAndFront passed." << std::endl;
}

// tests the behavior of the list when it is empty
void testEmptyList() {
    ULListStr dat;
    // asserts to verify that 1) a new list is empty and 2) of size 0
    assert(dat.empty() && dat.size() == 0);
    std::cout << "testEmptyList passed." << std::endl;
}

// tests the list's behavior with a single element
void testSingleElement() {
    ULListStr dat;
    dat.push_back("A");  // adds a single element A
    // asserts to check if the front and back elements are the same
    assert(dat.front() == "A" && dat.back() == "A");
    dat.pop_front(); // removes the single element
    // assert to check if the list is empty after removal
    assert(dat.empty());
    std::cout << "testSingleElement passed." << std::endl;
}

// tests for adding and removing multiple elements from the list
void testMultipleElements() {
    ULListStr dat;
    // adds multiple elements to the list
    for (int i = 0; i < 20; i++) {
        dat.push_back(std::to_string(i));
    }
    // checks if the size of the list is as expected
    assert(dat.size() == 20);
    // removes elements from the back and checks their order
    for (int i = 19; i >= 0; i--) {
        assert(dat.back() == std::to_string(i));
        dat.pop_back();
    }
    // assert to verify if the list is empty after removals
    assert(dat.empty());
    std::cout << "testMultipleElements passed." << std::endl;
}

// tests the list's memory management, especially when adding and removing elements
void testMemoryManagement() {
    ULListStr dat;
    for (int i = 0; i < 100; i++) {
        dat.push_back(std::to_string(i));
        if (i % 10 == 9) {
            // remove 10 elements from the front every 10 additions
            for (int j = 0; j < 10; j++) {
                dat.pop_front();
            }
        }
    }
    // assert to check if the list is empty after the operations
    assert(dat.empty());
    std::cout << "testMemoryManagement passed." << std::endl;
}

// Main function to run all the tests.
int main() {
    testPushBackAndFront();
    testPopBackAndFront();
    testEmptyList();
    testSingleElement();
    testMultipleElements();
    testMemoryManagement();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
