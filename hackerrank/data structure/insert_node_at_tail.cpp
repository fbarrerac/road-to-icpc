/*
 * Problem: Insert a Node at the Tail of a Linked List
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
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
 * Inserts a new node at the end of the list.
 * Current implementation is O(n) because we must traverse to the end.
 * Note: Efficiency could be improved to O(1) by maintaining a 'tail' pointer,
 * but the current HackerRank interface restricts us to using only the 'head'.
 */
Node* insertNodeAtTail(Node* head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) return newNode;

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

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
    Node* head = nullptr;

    // Simulating multiple insertions
    // Total complexity: O(n^2) due to repeated O(n) tail insertions
    head = insertNodeAtTail(head, 10);
    head = insertNodeAtTail(head, 20);
    head = insertNodeAtTail(head, 30);

    printLinkedList(head);

    // Cleanup logic (simplified for the example)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}