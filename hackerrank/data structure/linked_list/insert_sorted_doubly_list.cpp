#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

/**
 * Inserts a new node into a sorted doubly linked list while maintaining order.
 *
 * Strategy:
 * 1. Handle empty list or insertion at the head.
 * 2. Traverse until we find a node with a larger value.
 * 3. Update 4 pointers (prev/next of surrounding nodes) to bridge the new node.
 */
Node* insert_node(Node* head, int new_data) {
    Node* new_node = new Node(new_data);

    // Case 1: Empty list
    if (head == nullptr) return new_node;

    // Case 2: Insert before the current head (new smallest element)
    if (new_data <= head->data) {
        new_node->next = head;
        head->prev = new_node;
        return new_node;  // New node is now the head
    }

    Node* current = head;

    // Traverse to find the correct insertion point
    // We stop when we find a node larger than 'new_data' or reach the end
    while (current->next != nullptr && current->data < new_data) {
        current = current->next;
    }

    // Case 3: Insert at the very end (if new_data is larger than the last element)
    if (current->next == nullptr && current->data < new_data) {
        current->next = new_node;
        new_node->prev = current;
    }
    // Case 4: Insert in the middle (before 'current')
    else {
        new_node->prev = current->prev;
        new_node->next = current;

        if (current->prev) {
            current->prev->next = new_node;
        }
        current->prev = new_node;
    }

    return head;
}

int main() {
    // Example usage:
    Node* head = nullptr;

    head = insert_node(head, 5);
    head = insert_node(head, 3);
    head = insert_node(head, 7);
    head = insert_node(head, 6);

    // Print the list to verify correct insertion
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";

    // Memory cleanup (not shown for brevity)

    return 0;
}