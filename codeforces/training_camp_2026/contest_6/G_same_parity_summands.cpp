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

        long long rem_odd = n - (k - 1);
        if (rem_odd > 0 && rem_odd % 2 != 0) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) {
                cout << 1 << " ";
            }
            cout << rem_odd << "\n";
            continue;
        }

        // OPCIÓN B: Pares
        long long rem_even = n - 2 * (k - 1);
        if (rem_even > 0 && rem_even % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) {
                cout << 2 << " ";
            }
            cout << rem_even << "\n";
            continue;
        }

        cout << "NO\n";
    }

    return 0;
}
