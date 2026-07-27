#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int process(int x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    while (x % 3 == 0) {
        x /= 3;
    }

    return x;
}

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

    int target = process(a[0]);

    for (int i = 1; i < n; i++) {
        if (process(a[i]) != target) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}
