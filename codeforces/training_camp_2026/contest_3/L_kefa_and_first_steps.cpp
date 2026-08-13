#include <iostream>

using std::cin;
using std::cout;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, count = 0, prev_num = 0, max = 0;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        if (num >= prev_num) {
            count += 1;
        } else {
            if (max < count) max = count;
            count = 1;
        }
        prev_num = num;
    }

    if (count > max) max = count;

    cout << max << "\n";

    return 0;
}
