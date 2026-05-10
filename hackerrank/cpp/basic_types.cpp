/*
 * Problem: Basic Data Types
 * Platform: HackerRank
 * Link: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
 * Difficulty: Easy
 */

#include <cstdio>

int main() {
    int i;
    long long l;
    char c;
    float f;
    double d;

    scanf("%d %lld %c %f %lf", &i, &l, &c, &f, &d);

    printf("%d\n%lld\n%c\n%f\n%lf", i, l, c, f, d);

    return 0;
}