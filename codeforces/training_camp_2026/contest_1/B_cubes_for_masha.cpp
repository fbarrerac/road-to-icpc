#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::iota;
using std::next_permutation;
using std::string;
using std::to_string;
using std::vector;

bool can_form(int x, int n, const vector<int>& cube_masks) {
    string s = to_string(x);
    int len = s.length();

    if (len > n) return false;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    do {
        bool ok = true;
        for (int i = 0; i < len; ++i) {
            int digit = s[i] - '0';
            int cube_idx = p[i];

            if (!(cube_masks[cube_idx] & (1 << digit))) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    } while (next_permutation(p.begin(), p.end()));

    return false;
}

int solve(int n, const vector<vector<int>>& cubes) {
    vector<int> cube_masks(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cube_masks[i] |= (1 << cubes[i][j]);
        }
    }

    int x = 1;
    while (can_form(x, n, cube_masks)) {
        x++;
    }

    return x - 1;
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> cubes(n, vector<int>(6));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> cubes[i][j];
        }
    }

    cout << solve(n, cubes) << "\n";

    return 0;
}
