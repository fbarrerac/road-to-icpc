#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    bool pass = false;

    for (int i = 0; i < n; i++) {
        if (s[i] != '*') continue;

        for (int d = 1; i + 4 * d < n; d++) {
            if (s[i + d] == '*' &&
                s[i + 2 * d] == '*' &&
                s[i + 3 * d] == '*' &&
                s[i + 4 * d] == '*') {
                pass = true;
                break;
            }
        }

        if (pass) break;
    }

    if (pass) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
