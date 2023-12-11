#include "split.h"
#include <iostream>

// Function to create a new node with the given value
Node* createNode(int value) {
    Node* newNode = new Node(value, nullptr);
    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "NULL";
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
    }
    std::cout << std::endl;
}

// Function to delete the linked list and deallocate memory
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    // Test case 1: Empty list
    Node* in1 = nullptr;
    Node* odds1 = nullptr;
    Node* evens1 = nullptr;
    split(in1, odds1, evens1);
    std::cout << "Test case 1: ";
    std::cout << "in1: ";
    printList(in1);
    std::cout << "odds1: ";
    printList(odds1);
    std::cout << "evens1: ";
    printList(evens1);
    std::cout << std::endl;

    // Test case 2: List with odd and even values
    Node* in2 = createNode(1);
    in2->next = createNode(2);
    in2->next->next = createNode(3);
    in2->next->next->next = createNode(4);
    Node* odds2 = nullptr;
    Node* evens2 = nullptr;
    split(in2, odds2, evens2);
    std::cout << "Test case 2: ";
    std::cout << "in2: ";
    printList(in2);
    std::cout << "odds2: ";
    printList(odds2);
    std::cout << "evens2: ";
    printList(evens2);
    std::cout << std::endl;

    // Test case 3: Mixed Odd and Even Values
    Node* in3 = createNode(1);
    in3->next = createNode(2);
    in3->next->next = createNode(3);
    in3->next->next->next = createNode(4);
    in3->next->next->next->next = createNode(5);
    Node* odds3 = nullptr;
    Node* evens3 = nullptr;
    split(in3, odds3, evens3);
    std::cout << "Test case 3: ";
    std::cout << "in3: ";
    printList(in3);
    std::cout << "odds3: ";
    printList(odds3);
    std::cout << "evens3: ";
    printList(evens3);
    std::cout << std::endl;

    // Test case 4: All Odd Values
    Node* in4 = createNode(1);
    in4->next = createNode(3);
    in4->next->next = createNode(5);
    in4->next->next->next = createNode(7);
    Node* odds4 = nullptr;
    Node* evens4 = nullptr;
    split(in4, odds4, evens4);
    std::cout << "Test case 4: ";
    std::cout << "in4: ";
    printList(in4);
    std::cout << "odds4: ";
    printList(odds4);
    std::cout << "evens4: ";
    printList(evens4);
    std::cout << std::endl;

    // Test case 5: All Even Values
    Node* in5 = createNode(2);
    in5->next = createNode(4);
    in5->next->next = createNode(6);
    in5->next->next->next = createNode(8);
    Node* odds5 = nullptr;
    Node* evens5 = nullptr;
    split(in5, odds5, evens5);
    std::cout << "Test case 5: ";
    std::cout << "in5: ";
    printList(in5);
    std::cout << "odds5: ";
    printList(odds5);
    std::cout << "evens5: ";
    printList(evens5);
    std::cout << std::endl;

    // Test case 6: Single Node List
    Node* in6 = createNode(42);
    Node* odds6 = nullptr;
    Node* evens6 = nullptr;
    split(in6, odds6, evens6);
    std::cout << "Test case 6: ";
    std::cout << "in6: ";
    printList(in6);
    std::cout << "odds6: ";
    printList(odds6);
    std::cout << "evens6: ";
    printList(evens6);
    std::cout << std::endl;

    // Test case 7: Reverse Sorted List
    Node* in7 = createNode(5);
    in7->next = createNode(4);
    in7->next->next = createNode(3);
    in7->next->next->next = createNode(2);
    in7->next->next->next->next = createNode(1);
    Node* odds7 = nullptr;
    Node* evens7 = nullptr;
    split(in7, odds7, evens7);
    std::cout << "Test case 7: ";
    std::cout << "in7: ";
    printList(in7);
    std::cout << "odds7: ";
    printList(odds7);
    std::cout << "evens7: ";
    printList(evens7);
    std::cout << std::endl;

    // Clean up memory
    deleteList(in1);
    deleteList(odds1);
    deleteList(evens1);
    deleteList(in2);
    deleteList(odds2);
    deleteList(evens2);
    deleteList(in3);
    deleteList(odds3);
    deleteList(evens3);
    deleteList(in4);
    deleteList(odds4);
    deleteList(evens4);
    deleteList(in5);
    deleteList(odds5);
    deleteList(evens5);
    deleteList(in6);
    deleteList(odds6);
    deleteList(evens6);
    deleteList(in7);
    deleteList(odds7);
    deleteList(evens7);

    return 0;
}
