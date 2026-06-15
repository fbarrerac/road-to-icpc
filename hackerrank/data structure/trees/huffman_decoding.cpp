/*
 * Problem: Huffman Decoding
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
 * Difficulty: Medium
 */

#include <iostream>
#include <string>
using std::cout;
using std::string;

struct Node {
    int freq;
    char data;
    Node* left;
    Node* right;
};

void decode_huff(Node* root, string code) {
    if (root == nullptr) return;

    Node* current = root;
    for (char bit : code) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        // If we reach a leaf node, print the character and reset to the root
        if (current->data != NULL) {
            cout << current->data;
            current = root;
        }
    }
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Example usage:
    Node* root = new Node(NULL, 4);
    root->left = new Node('B', 1);
    root->right = new Node('A', 3);

    string sample_code = "1011";  // This should decode to "ABA"
    decode_huff(root, sample_code);

    return 0;
}
