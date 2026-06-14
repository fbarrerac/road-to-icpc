#include <iostream>
using std::cout;
using std::max;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* root) {
    if (root == nullptr) return -1;

    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height, right_height) + 1;
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

    cout << height(root) << "\n";  // Output: 2

    return 0;
}
