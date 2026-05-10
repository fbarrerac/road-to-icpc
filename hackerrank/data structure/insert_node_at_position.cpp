/*
 * Problem: Insert a node at a specific position in a linked list
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
 * Difficulty: Easy
 */

#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

/**
 * Inserts a node at a specific zero-indexed position.
 * Time Complexity: O(position) - in worst case O(n)
 * Space Complexity: O(1)
 */
Node* insertNodeAtPosition(Node* head, int data, int position) {
    Node* newNode = new Node(data);
    Node* current = head;

    // Traverse to the node immediately before the target position
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    // Wiring the new node into the sequence
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << (current->next ? " -> " : " -> NULL\n");
        current = current->next;
    }
}

int main() {
    // Initializing list: 1 -> 2 -> 3 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printLinkedList(head);

    // Goal: Insert 99 at position 2 (between 2 and 3)
    // Result: 1 -> 2 -> 99 -> 3 -> NULL
    head = insertNodeAtPosition(head, 99, 2);

    cout << "After insertion: ";
    printLinkedList(head);

    // Memory cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}