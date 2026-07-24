#include <iostream>

using std::cin;
using std::cout;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    int max_coders = (n * n + 1) / 2;

    cout << max_coders << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                cout << "C";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }

    return 0;
}
