/*
 * Problem: Find Merge Point of Two Lists
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem
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
 * Finds the intersection node of two linked lists.
 *
 * Strategy: Two-pointer path switching.
 * By switching heads after the first pass, both pointers travel
 * the same total distance (LengthA + LengthB).
 */
int find_merge_node(Node* head_a, Node* head_b) {
    Node* current_a = head_a;
    Node* current_b = head_b;

    while (current_a != current_b) {
        // Switch to the other list's head when reaching the end
        current_a = (current_a == nullptr) ? head_b : current_a->next;
        current_b = (current_b == nullptr) ? head_a : current_b->next;
    }

    // Return -1 if no merge point is found
    return (current_a != nullptr) ? current_a->data : -1;
}

int main() {
    // Creating first linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head_a = new Node(1);
    head_a->next = new Node(2);
    head_a->next->next = new Node(3);
    head_a->next->next->next = new Node(4);

    // Creating second linked list: 6 -> 7 -> 3 -> 4 -> NULL (merges at node with value 3)
    Node* head_b = new Node(6);
    head_b->next = new Node(7);
    head_b->next->next = head_a->next->next;  // Merge point at node with value 3

    int merge_data = find_merge_node(head_a, head_b);
    if (merge_data != -1) {
        cout << "Merge point data: " << merge_data << "\n";
    } else {
        cout << "No merge point found.\n";
    }

    return 0;
}
