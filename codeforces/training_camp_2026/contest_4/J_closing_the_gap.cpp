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
        int n;
        cin >> n;

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int n;
            cin >> n;
            sum += n;
        }

        if (sum % n == 0) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }

    return 0;
}
