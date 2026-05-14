/*
 * Problem: Get Node Value
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem
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
 * Finds the node value at a specific distance from the tail.
 *
 * Strategy: Two-Pointer Technique (Fast & Slow)
 * 1. Advance the 'fast' pointer to create a gap equal to 'position_from_tail'.
 * 2. Move both pointers in sync until 'fast' hits the end of the list.
 * 3. The 'slow' pointer will then be at the target position from the tail.
 */
int get_node(Node* head, int position_from_tail) {
    Node* fast = head;
    Node* slow = head;

    // Step 1: Initialize the gap
    for (int i = 0; i < position_from_tail; i++) {
        if (fast == nullptr) return -1;  // Handle out-of-bounds cases
        fast = fast->next;
    }

    // Step 2: Slide the window of fixed size across the list
    // When fast reaches the end, slow is exactly N steps behind it
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 3: Extract the data from the synchronized slow pointer
    return slow->data;
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    int position_from_tail = 1;  // Example position from tail
    cout << get_node(head, position_from_tail) << "\n";

    // Memory cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
