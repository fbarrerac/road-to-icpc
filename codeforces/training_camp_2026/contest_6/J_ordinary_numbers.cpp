#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::to_string;

void solve() {
    long long n;
    cin >> n;

    if (n < 10) {
        cout << n << "\n";
        return;
    }

    string s = to_string(n);
    int L = s.length();

    long long mask = 0;
    for (int i = 0; i < L; i++) {
        mask = mask * 10 + 1;
    }

    long long ans = 9 * (L - 1) + (n / mask);
    cout << ans << "\n";
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
