/*
 * Problem: Binary Search Tree : Insertion
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem
 * Difficulty: Easy
 */

#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node{data, nullptr, nullptr};
    }

    if (data == root->data) {
        // Duplicate data, do not insert
        return root;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Helper function to perform in-order traversal and print the tree
void in_order(Node* root) {
    if (root == nullptr) return;

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Example usage:
    Node* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    in_order(root);  // Output: 2 3 4 5 6 7 8

    return 0;
}
