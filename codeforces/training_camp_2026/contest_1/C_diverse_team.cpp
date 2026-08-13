#include <iostream>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::unordered_set;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> team;
    unordered_set<int> ratings;

    for (int i = 0; i < n; ++i) {
        int current_rating;
        cin >> current_rating;

        if (!ratings.contains(current_rating)) {
            ratings.insert(current_rating);
            team.push_back(i+1);
        }

        if (team.size() == k) break;
    }

    if (team.size() == k) {
        cout << "YES" << "\n";
        for (int i = 0; i < k; ++i) {
            cout << team[i] << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "NO" << "\n";
    }
}
