/*
* Problem: Reverse a linked list
* Platform: HackerRank
* Link: https://www.hackerrank.com/challenges/reverse-a-linked-list/problem
* Difficulty: Easy
*/

/*
* INPUT STRUCTURE:
* 1. 't' (Test Cases): Number of independent lists to reverse.
* 2. 'n' (List Size): Number of elements for the current list.
* 3. 'data': The actual integers to be stored in the nodes.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/**
 * Reverses the list by shifting pointers.
 * It uses three pointers to keep track of the Previous, Current, and Next nodes.
 */
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  // 1. Save the rest of the list
        curr->next = prev;  // 2. Reverse the link (point backwards)
        prev = curr;        // 3. Move the 'previous' window forward
        curr = next;        // 4. Move the 'current' window forward
    }

    return prev;  // 'prev' ends up as the new head of the reversed list
}

void printList(Node* node) {
    while (node) {
        cout << node->data << (node->next ? " " : "");
        node = node->next;
    }
    cout << "\n";
}

int main() {
    // Optimize I/O performance
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Node* head = nullptr;
        Node* tail = nullptr;

        // Stage 1: Build the list from input
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            Node* newNode = new Node(data);

            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        // Stage 2: Reverse the list in-place
        head = reverse(head);

        // Stage 3: Output the results
        printList(head);

        // Stage 4: Memory Cleanup
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}