#include <iostream>

using std::cin;
using std::cout;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long saltos = (k - 1) / (n - 1);

        long long ans = k + saltos;

        cout << ans << "\n";
    }

    return 0;
}
