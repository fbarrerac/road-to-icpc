#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string vowels = "aeiou";
    int count = 0;

    string s;
    cin >> s;

    for (char c : s) {
        if (isdigit(c) && ((c - '0') % 2) != 0) count += 1;

        if (vowels.find(c) != string::npos) count += 1;
    }

    cout << count << "\n";

    return 0;
}
