#include <iostream>

using std::abs;
using std::cin;
using std::cout;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << "\n";
            continue;
        }

        int diff = abs(a - b);

        int steps = diff / 5;
        diff %= 5;

        steps += diff / 2;
        diff %= 2;

        steps += diff;

        cout << steps << "\n";
    }

    return 0;
}
