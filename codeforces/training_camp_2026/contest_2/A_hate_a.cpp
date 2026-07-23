#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

string process(const string& t) {
    string sp;

    for (int i = 0; i < t.size(); i++) {
        if (t[i] != 'a') {
            sp += t[i];
        }
    }

    int size = sp.size();

    if (size % 2 != 0) {
        return ":(";
    }

    string v1 = sp.substr(0, size / 2);
    string v2 = sp.substr(size / 2, size / 2);

    if (v1 != v2) {
        return ":(";
    }

    int m = v2.size();
    string real_suffix = t.substr(t.size() - m);
    if (real_suffix != v2) {
        return ":(";
    }
    string s = t.substr(0, t.size() - m);

    return s;
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string t;
    cin >> t;

    string result = process(t);

    cout << result << "\n";
}