/*
 * Problem: Foor Loop
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
 * Difficulty: Easy
 */

#include <iostream>
using namespace std;

int main() {
    string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (i <= 9) {
            cout << numbers[i-1] << "\n";
        } 
        else {
            cout << (i % 2 == 0 ? "even" : "odd") << "\n";
        }

    }

    return 0;
}
