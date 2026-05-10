/*
 * Problem: Delete a Node
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem
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
 * Removes a node at a given zero-indexed position.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* deleteNode(Node* head, int position) {
    if (head == nullptr) return nullptr;

    // Special case: deleting the head of the list
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    // Advance to the node preceding the target for deletion
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    // Unlinking the target node and freeing its memory
    if (current->next != nullptr) {
        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main() {
    // List setup: 20 6 2 19 7 4 15 9
    Node* head = new Node(20);
    head->next = new Node(6);
    head->next->next = new Node(2);
    head->next->next->next = new Node(19);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(15);
    head->next->next->next->next->next->next->next = new Node(9);

    head = deleteNode(head, 3);  // Expected output: 20 6 2 7 4 15 9

    printLinkedList(head);

    // Final cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
