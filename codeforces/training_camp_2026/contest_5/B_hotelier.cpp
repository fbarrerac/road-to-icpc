#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_events;
    cin >> total_events;

    vector<int> rooms(10, 0);

    while (total_events--) {
        char event;
        cin >> event;

        if (event == 'L') {
            for (int i = 0; i < 10; i++) {
                if (rooms[i] == 0) {
                    rooms[i] = 1;
                    break;
                }
            }
        } else if (event == 'R') {
            for (int i = 9; i >= 0; --i) {
                if (rooms[i] == 0) {
                    rooms[i] = 1;
                    break;
                }
            }
        } else {
            int room_number = event - '0';
            rooms[room_number] = 0;
        }
    }

    cout << rooms[0] << rooms[1] << rooms[2] << rooms[3] << rooms[4] << rooms[5] << rooms[6] << rooms[7] << rooms[8] << rooms[9];

    return 0;
}
