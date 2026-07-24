#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Optimización de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<pair<char, int>> events(n);
    set<int> seen_entering;
    set<int> in_room;

    for (int i = 0; i < n; ++i) {
        cin >> events[i].first >> events[i].second;
        char type = events[i].first;
        int id = events[i].second;

        if (type == '+') {
            seen_entering.insert(id);
        } else if (type == '-') {
            if (seen_entering.find(id) == seen_entering.end()) {
                in_room.insert(id);
            }
        }
    }

    int current_capacity = in_room.size();
    int max_capacity = current_capacity;

    for (int i = 0; i < n; ++i) {
        char type = events[i].first;
        int id = events[i].second;

        if (type == '+') {
            in_room.insert(id);
            current_capacity++;
        } else {
            in_room.erase(id);
            current_capacity--;
        }

        max_capacity = max(max_capacity, current_capacity);
    }

    cout << max_capacity << "\n";

    return 0;
}
