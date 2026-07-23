/* There are n students in a school class, the rating of the i-th student on Codehorses is ai.
You have to form a team consisting of k students (1≤k≤n) such that the ratings of all team members are distinct.

If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k
 distinct numbers which should be the indices of students in the team you form.
 If there are multiple answers, print any of them.

Input
The first line contains two integers n
 and k
 (1≤k≤n≤100
) — the number of students and the size of the team you have to form.

The second line contains n integers a1,a2,…,an (1≤ai≤100), where ai is the rating of i-th student.

Output
If it is impossible to form a suitable team, print "NO" (without quotes).
Otherwise print "YES", and then print k distinct integers from 1 to n which should be the indices of students in the team you form.
 All the ratings of the students in the team should be distinct. You may print the indices in any order.
 If there are multiple answers, print any of them.

Assume that the students are numbered from 1 to n. */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void process(int k, vector<int> ratings) {
    vector<int> students;
    int i= 0;

    students.push_back(ratings[i]);
    while (students.size() < k && i < ratings.size()) {
        i++;
    }
}

int main() {
    // Desync from stdio to accelerate heavy I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> ratings(n);
    for (int i = 0; i < n; ++i) {
        cin >> ratings[i];
    }

    process(k, ratings);
}