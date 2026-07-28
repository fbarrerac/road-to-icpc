#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::min_element;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> candies(n);
        for (int i = 0; i < n; i++) {
            cin >> candies[i];
        }

        vector<int> oranges(n);
        for (int i = 0; i < n; i++) {
            cin >> oranges[i];
        }

        long long min_candies = *min_element(candies.begin(), candies.end());
        long long min_oranges = *min_element(oranges.begin(), oranges.end());

        long long total_moves = 0;
        for (int i = 0; i < n; i++) {
            long long diff_candies = candies[i] - min_candies;
            long long diff_oranges = oranges[i] - min_oranges;

            total_moves += max(diff_candies, diff_oranges);
        }

        cout << total_moves << "\n";
    }

    return 0;
}
