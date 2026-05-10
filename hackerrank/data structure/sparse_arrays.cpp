/*
 * Problem: Sparse Arrays
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/sparse-arrays/problem
 * Difficulty: Medium
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    unordered_map<string, int> frequencies;

    // Pre-process: Count frequencies of each string in the input list.
    for (const string& s : stringList) {
        frequencies[s]++;
    }

    vector<int> results;
    results.reserve(queries.size());

    // For each query, fetch the count directly from the map.
    // If the key doesn't exist, unordered_map returns the default value for int (0).
    for (const string& query : queries) {
        results.push_back(frequencies[query]);
    }

    return results;
}

int main() {
    // Local example for testing functionality
    vector<string> stringList = {"aba", "baba", "aba", "xzxb"};
    vector<string> queries = {"aba", "xzxb", "ab"};

    vector<int> results = matchingStrings(stringList, queries);

    for (int count : results) {
        cout << count << " ";
    }

    return 0;
}
