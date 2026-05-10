/*
 * Problem: Print the Elements of a Linked List
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
 * Difficulty: Easy
 */

#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void printLinkedList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << "\n";
        current = current->next;
    }
}

int main() {
    Node* nodo1 = new Node(16);
    Node* nodo2 = new Node(13);
    Node* nodo3 = new Node(20);

    nodo1->next = nodo2;
    nodo2->next = nodo3;

    printLinkedList(nodo1);

    delete nodo1;
    delete nodo2;
    delete nodo3;

    return 0;
}