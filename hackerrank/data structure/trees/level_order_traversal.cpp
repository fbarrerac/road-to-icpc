/*
 * Problem: Level Order Traversal
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
 * Difficulty: Easy
 */

#include <iostream>
#include <queue>

using std::cout;
using std::queue;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void level_order(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Example usage:
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};

    level_order(root);  // Output: 1 2 3 4 5

    return 0;
}
