#include <iostream>

using std::cin;
using std::cout;

void solve() {
    int n;
    cin >> n;

    cout << (n - 1) / 2 << "\n";
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
