/*
 * Problem: Left Rotation
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/array-left-rotation/problem
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

// Inverts elements within a specific range [start, end].
void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

/**
 * Reversal Algorithm for Array Rotation:
 * This method is highly efficient as it performs the rotation
 * in-place (O(1) extra space) and has a linear time complexity O(n).
 */
void rotateLeft(int d, vector<int>& arr) {
    int n = arr.size();
    d = d % n;  // Handle cases where d is larger than the array size
    if (d == 0) return;

    // Reverse the first d elements
    reverseArray(arr, 0, d - 1);
    // Reverse the remaining elements
    reverseArray(arr, d, n - 1);
    // Reverse the entire array
    reverseArray(arr, 0, n - 1);
}

// Local main to ensure code functionality outside the platform
int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int cant_arr, cant_rotation;
    cin >> cant_arr >> cant_rotation;

    vector<int> arr(cant_arr);

    for (int i = 0; i < cant_arr; i++) cin >> arr[i];

    rotateLeft(cant_rotation, arr);

    // Output optimized for judging plataforms: without final space
    for (int i = 0; i < cant_arr; i++) {
        cout << arr[i] << (i == cant_arr - 1 ? "" : " ");
    }
    return 0;
}
