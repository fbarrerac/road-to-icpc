#include <iostream>

using std::cin;
using std::cout;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y, z;
    cin >> x >> y >> z;

    if (x > y + z) {
        cout << "+\n";
    } else if (y > x + z) {
        cout << "-\n";
    } else if (x == y && z == 0) {
        cout << "0\n";
    } else {
        cout << "?\n";
    }
}
