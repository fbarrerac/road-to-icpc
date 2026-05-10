/*
 * Problem: Array Manipulation
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/crush/problem
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

/*
 * DESIGN DECISIONS:
 * 1. 1-Indexed Handling: The problem uses 1-based indexing. We allocate (n + 2)
 *    to align with this, avoiding constant "-1" offsets and providing a safety
 *    buffer for the (b + 1) index.
 * 2. Efficiency: Instead of an O(n*m) brute force, we use a Difference Array
 *    combined with Prefix Sums to achieve O(n + m) time complexity.
 */
long arrayManipulation(int n, vector<vector<int>> queries) {
    // n+2: [0] is ignored, [1...n] is the data, [n+1] is for the 'b+1' boundary.
    // Initialized to 0 to ensure a clean slate for accumulation.
    vector<long> arr(n + 2, 0);

    /*
     * TECHNIQUE 1: Difference Array (O(m))
     * Instead of updating every element in the range [a, b], we only mark the
     * boundaries. Adding 'k' at 'a' starts the increment, and subtracting 'k'
     * at 'b + 1' cancels it out for the rest of the array.
     */
    for (const vector<int>& query : queries) {
        int a = query[0];
        int b = query[1];
        int k = query[2];

        arr[a] += k;
        arr[b + 1] -= k;
    }

    /*
     * TECHNIQUE 2: Prefix Sum (O(n))
     * We sweep through the marks. By accumulating values (running sum),
     * the initial '+k' propagates through the range until it hits '-k'.
     */
    long max_val = 0;
    long current_sum = 0;

    for (size_t i = 1; i < arr.size(); i++) {
        current_sum += arr[i];
        if (current_sum > max_val) {
            max_val = current_sum;
        }
    }

    return max_val;
}

int main() {
    // Local example for testing functionality
    int n = 5;

    vector<vector<int>> queries;
    queries = {{1, 2, 100}, {2, 5, 100}, {3, 4, 100}};

    long result = arrayManipulation(n, queries);

    cout << result << "\n";

    return 0;
}
