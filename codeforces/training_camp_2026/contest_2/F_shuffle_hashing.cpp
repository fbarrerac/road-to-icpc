#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    string p, h;

    while (t--) {
        cin >> p >> h;

        int p_size = p.size();
        int h_size = h.size();

        if (p_size > h_size) {
            cout << "NO" << "\n";
            continue;
        }

        vector<int> p_hash(26, 0);
        for (char c : p) {
            p_hash[c - 'a']++;
        }

        vector<int> window_hash(26, 0);
        for (int i = 0; i < p_size; i++) {
            window_hash[h[i] - 'a']++;
        }

        bool found = (p_hash == window_hash);

        if (!found) {
            for (int i = p_size; i < h_size; i++) {
                window_hash[h[i - p_size] - 'a']--;
                window_hash[h[i] - 'a']++;

                if (p_hash == window_hash) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
