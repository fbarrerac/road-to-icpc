#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_actual = a[n - 1];
        int eversions = 0;

        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > max_actual) {
                max_actual = a[i];
                eversions++;
            }
        }

        cout << eversions << "\n";
    }

    return 0;
}
