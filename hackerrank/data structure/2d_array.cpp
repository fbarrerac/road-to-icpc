/*
 * Problem: 2D Array - DS (Hourglass Sum)
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/2d-array/problem
 * Difficulty: Easy
 */

/*
 * Note: This file contains the 'hourglassSum' function developed for the challenge.
 * The original HackerRank boilerplate (I/O logic) was removed to provide
 * a clean, standalone implementation.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// Logic developed for the HackerRank challenge
int hourglassSum(const vector<vector<int>>& arr) {  // Use of & to avoid duplicate vector.
    int max_sum = -100;
    int rows = arr.size();
    int cols = arr[0].size();

    for (int i = 0; i+2 < rows; i++) {
        for (int j = 0; j + 2 < cols; j++) {
            
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            sum += arr[i+1][j + 1];
            sum += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            if (sum > max_sum) max_sum = sum;
        }
    }

    return max_sum;
}

int main() {
    // Optimization for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Demonstration 6x6 matrix from HackerRank sample input
    vector<vector<int>> test_matrix = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}};

    int result = hourglassSum(test_matrix);

    cout << "Maximum Hourglass Sum: " << result << "\n";

    return 0;
}