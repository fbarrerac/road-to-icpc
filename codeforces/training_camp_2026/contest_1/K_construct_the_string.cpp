#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        size_t n, a, b;
        cin >> n >> a >> b;

        string s, letters;

        for (size_t i = 0; i < b; i++) {
            letters += (i + 'a');
        }

        int j = 0;
        while (s.size() < n) {
            s += letters[j];
            j = (j + 1) % b;
        }

        cout << s << "\n";
    }

    return 0;
}
