/*
 * Problem: Print in Reverse
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem
 * Difficulty: Easy
 */

/*
 * INPUT STRUCTURE EXPLANATION:
 * The input follows a nested hierarchy that dictates our loop structure:
 * 1. 't' (Test Cases): The first integer defines how many independent lists we will process.
 * 2. 'n' (List Size): For each test case, the first value tells us how many nodes the list has.
 * 3. 'data' (Elements): The subsequent 'n' values are the actual data for each node.
 *
 * IMPLEMENTATION STRATEGY:
 * - Outer Loop: Handles each independent test case.
 * - Inner Loop: Reads 'n' elements to reconstruct the linked list in memory.
 * - Recursion: Used in reversePrint() to leverage the Call Stack for reversing
 *   the output without allocating additional arrays or manual stacks.
 */

#include <iostream>

using std::cin;
using std::cout;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void reversePrint(Node* head) {
    if (head == nullptr) return;

    // Recursive call to the next node
    reversePrint(head->next);

    // Print the current node's data after the recursive call
    cout << head->data << "\n";
}

int main() {
    // Speed up I/O operations for competitive programming
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases, list_size, data;
    cin >> test_cases;

    while (test_cases--) {
        cin >> list_size;

        Node* head = nullptr;
        Node* tail = nullptr;

        while (list_size--) {
            cin >> data;
            Node* newNode = new Node(data);

            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        reversePrint(head);

        // Memory cleanup to prevent leaks between test cases
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}
