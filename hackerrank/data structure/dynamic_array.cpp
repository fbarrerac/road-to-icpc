/*
 * Problem: Dynamic Array
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/dynamic-array/problem
 * Difficulty: Easy
 */

/*
 * Note: This file contains the 'dynamicArray' function developed for the challenge.
 * The original HackerRank boilerplate (I/O logic, split/trim functions) was
 * removed to provide a clean, standalone implementation.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// Logic developed for the HackerRank challenge
vector<int> dynamicArray(int n, const vector<vector<int>>& queries) {
    vector<int> results;
    results.reserve(queries.size());
    int last_answer = 0;

    vector<vector<int>> arr(n);

    for (const auto& i : queries) {
        int idx = (i[1] ^ last_answer) % n;
        switch (i[0]) {
            case 1:
                arr[idx].push_back(i[2]);
                break;

            case 2:
                last_answer = arr[idx][i[2] % arr[idx].size()];
                results.push_back(last_answer);
                break;

            default:
                break;
        }
    }

    return results;
}

int main() {
    // Input values from HackerRank Sample Input
    int n = 2;
    vector<vector<int>> test_queries = {
        {1, 0, 5},
        {1, 1, 7},
        {1, 0, 3},
        {2, 1, 0},
        {2, 1, 1}};

    vector<int> result = dynamicArray(n, test_queries);

    // Output results
    cout << "Type 2 Query Results:\n";
    for (int val : result) {
        cout << val << "\n";
    }

    return 0;
}