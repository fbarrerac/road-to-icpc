/*
 * Problem: Top View
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/tree-top-view/problem
 * Difficulty: Easy
 */

#include <iostream>
#include <map>
#include <queue>

using std::cout;
using std::map;
using std::pair;
using std::queue;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void top_view(Node* root) {
    if (root == nullptr) return;

    // Map to store the first node at each horizontal distance
    map<int, int> node_map;
    // Queue for level order traversal
    queue<pair<Node*, int>> q;

    // Start with the root node at horizontal distance 0
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // If this is the first node at this horizontal distance, add it to the map
        if (node_map.find(hd) == node_map.end()) {
            node_map[hd] = node->data;
        }

        // Enqueue left and right children with their respective horizontal distances
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Print the top view from leftmost to rightmost horizontal distance
    for (const auto& [hd, data] : node_map) {
        cout << data << " ";
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

    top_view(root);  // Output: 4 2 1 3

    return 0;
}
