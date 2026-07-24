#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if ((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
            cout << "Infinite\n";
            return 0;
        }
    }

    int points = 0;

    for (int i = 0; i < n - 1; ++i) {
        if ((a[i] == 1 && a[i + 1] == 2) || (a[i] == 2 && a[i + 1] == 1)) {
            points += 3;
        }

        else if ((a[i] == 1 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 1)) {
            points += 4;
        }

        if (i >= 1 && a[i - 1] == 3 && a[i] == 1 && a[i + 1] == 2) {
            points--;
        }
    }

    cout << "Finite\n";
    cout << points << "\n";

    return 0;
}
