/*
 * Problem: Delete duplicate-value nodes from a sorted linked list
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem
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
 * Removes duplicate nodes from a sorted linked list.
 *
 * Strategy: Since the list is sorted, duplicates are guaranteed to be adjacent.
 * We compare each node with its next neighbor and bypass it if they match.
 */
Node* remove_duplicates(Node* head) {
    if (head == nullptr) return head;

    Node* current = head;

    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;  // Free memory of the removed node
        } else {
            current = current->next;
        }
    }

    return head;
}

void print_list(Node* head) {
    while (head != nullptr) {
        cout << head->data << (head->next ? " -> " : " -> NULL\n");
        head = head->next;
    }
}

int main() {
    // Creating a sorted list with duplicates: 1 -> 2 -> 2 -> 2 -> 3 -> 3 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);

    head = remove_duplicates(head);

    print_list(head);

    // Memory cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}