#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<long long> candies(3);
        cin >> candies[0] >> candies[1] >> candies[2];

        sort(candies.begin(), candies.end());

        if (candies[0] + candies[1] < candies[2]) {
            cout << candies[0] + candies[1] << "\n";
        } else {
            cout << (candies[0] + candies[1] + candies[2]) / 2 << "\n";
        }
    }

    return 0;
}
