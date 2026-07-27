#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

bool is_subsequence(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            j++;
        }
        i++;
    }
    return j == t.size();
}

string process(const string& s, const string& t) {
    vector<int> s_hash(26, 0);
    for (char c : s) {
        s_hash[c - 'a']++;
    }

    vector<int> t_hash(26, 0);
    for (char c : t) {
        t_hash[c - 'a']++;
    }

    bool has_enough_chars = true;

    for (int i = 0; i < 26; i++) {
        if (s_hash[i] < t_hash[i]) {
            has_enough_chars = false;
            break;
        }
    }

    if (!has_enough_chars) {
        return "need tree";
    }

    if (s.size() == t.size()) {
        return "array";
    }

    if (is_subsequence(s, t)) {
        return "automaton";
    }

    return "both";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string s, t;
    if (cin >> s >> t) {
        cout << process(s, t) << "\n";
    }

    return 0;
}
