#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> table(n + 1, false);
    int max_socks = 0;
    int current = 0;

    for (int i = 0; i < n * 2; i++) {
        int sock;
        cin >> sock;

        if (table[sock]) {
            table[sock] = false;
            current--;
        } else {
            table[sock] = true;
            current++;
            max_socks = max(max_socks, current);
        }
    }
    cout << max_socks << "\n";
}
