/*
 * Problem: Variable Sized Arrays
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/variable-sized-arrays/problem
 * Difficulty: Easy
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int cant_arr, cant_query;
    if (!(cin >> cant_arr >> cant_query)) return 0;  // Input validation to prevent errors on invalid data.

    vector<vector<int>> list(cant_arr);

    // Reading each row: a for-each loop is used to iterate over each row of the main vector.
    for (vector<int>& row : list) {
        int row_size;
        cin >> row_size;

        // Reserve memory in advance to avoid multiple reallocations during filling.
        row.reserve(row_size);

        for (int j = 0; j < row_size; j++) {
            int value;
            cin >> value;
            row.push_back(value);
        }
    }

    // Processing queries: direct access to the requested elements.
    for (int i = 0; i < cant_query; i++) {
        int num_row, pos;
        cin >> num_row >> pos;
        cout << list[num_row][pos] << "\n";
    }

    return 0;
}