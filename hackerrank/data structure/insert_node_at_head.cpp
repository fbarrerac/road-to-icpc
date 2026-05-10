/*
 * Problem: Insert a Node at the Head of a Linked List
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
 * Difficulty: Easy
 */

#include <iostream>

using std::cout;

/**
 * SinglyLinkedListNode implementation with a constructor for atomic initialization.
 */
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

/**
 * Inserts a new node at the beginning of the list.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
Node* insertNodeAtHead(Node* head, int data) {
    Node* newNode = new Node(data);

    // The new node points to the current head, then becomes the new head.
    // Works correctly even if head is nullptr.
    newNode->next = head;

    return newNode;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << (current->next ? " -> " : " -> NULL\n");
        current = current->next;
    }
}

int main() {
    // Local example for testing functionality
    Node* head = nullptr;

    head = insertNodeAtHead(head, 10);
    head = insertNodeAtHead(head, 20);
    head = insertNodeAtHead(head, 30);

    printLinkedList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}