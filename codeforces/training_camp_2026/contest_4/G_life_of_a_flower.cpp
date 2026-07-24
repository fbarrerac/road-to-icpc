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

        int tall = 1;
        int yesterday = -1;
        bool dead = false;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if (dead) {
                continue;
            }

            if (a == 0 && yesterday == 0) {
                tall = -1;
                dead = true;
            } else if (a == 1) {
                if (yesterday == 1) {
                    tall += 5;
                } else {
                    tall += 1;
                }
            }

            yesterday = a;
        }

        cout << tall << "\n";
    }

    return 0;
}
