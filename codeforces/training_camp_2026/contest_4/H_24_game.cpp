#include <iostream>

using std::cin;
using std::cout;

int main() {
    // Optimización de I/O
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n <= 3) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    if (n % 2 == 0) {
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";

        for (int i = n; i > 4; i -= 2) {
            cout << i << " - " << (i - 1) << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    } else {
        cout << "5 * 4 = 20\n";
        cout << "20 + 3 = 23\n";
        cout << "23 + 2 = 25\n";
        cout << "25 - 1 = 24\n";

        for (int i = n; i > 5; i -= 2) {
            cout << i << " - " << (i - 1) << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    }

    return 0;
}
