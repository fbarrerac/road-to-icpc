#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    int diff_count = 0;
    int i = 0;

    while (i < n && diff_count < 3) {
        if (a[i] != sorted_a[i]) {
            diff_count++;
        }
        i++;
    }

    diff_count < 3 ? cout << "YES" : cout << "NO";

    return 0;
}
