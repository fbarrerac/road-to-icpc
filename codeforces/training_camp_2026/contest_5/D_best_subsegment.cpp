#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    int max = 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
        }
    }

    pair<int, int> ans = {0, 0};
    int longest = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            int j = i;
            while (j < n && a[j] == max) {
                j++;
            }
            if (j - i > longest) {
                longest = j - i;
                ans = {i + 1, j};
            }
            i = j - 1;
        }
    }

    cout << longest << "\n";

    return 0;
}
