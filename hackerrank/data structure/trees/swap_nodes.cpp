/*
 * Problem: Swap Nodes [Algo]
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/swap-nodes-algo/problem
 * Difficulty: Medium
 */

#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::queue;
using std::vector;

struct Node {
    int data;
    int depth;
    Node* left;
    Node* right;
};

vector<vector<int>> swap_nodes(vector<vector<int>> indexes, vector<int> queries) {
    Node* root = new Node{1, 1, nullptr, nullptr};
    queue<Node*> q;
    q.push(root);

    vector<vector<int>> result;

    /* Build the binary tree including depth information */
    for (const auto& index : indexes) {
        Node* current = q.front();
        q.pop();

        if (index[0] != -1) {  // Left child
            current->left = new Node{index[0], current->depth + 1, nullptr, nullptr};
            q.push(current->left);
        }
        if (index[1] != -1) {  // Right child
            current->right = new Node{index[1], current->depth + 1, nullptr, nullptr};
            q.push(current->right);
        }
    }

    /* Perform swaps based on queries */
    for (const auto& query : queries) {
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->depth % query == 0) {
                Node* temp = current->left;
                current->left = current->right;
                current->right = temp;
            }
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        result.push_back(vector<int>());
        get_inorder(result, root);  // Get the inorder traversal after each swap
    }

    return result;
}

void get_inorder(vector<vector<int>>& result, Node* root) {
    if (root == nullptr) {
        return;
    }

    get_inorder(result, root->left);
    result.back().push_back(root->data);
    get_inorder(result, root->right);
}
