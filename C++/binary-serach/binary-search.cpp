
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
** try: g++ cin.cpp -o cin; then execute ./cin
*/

using namespace std;

int main(int argc, char *argv[])
{
    const int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    const int len = sizeof(data) / sizeof(int);
    const int target = 3;

    int left = 0;
    int middle = len >> 1;
    int right = len - 1;
    int pos = -1;
    for (;;) {
        int v = data[middle];
        printf("L: %d, M: %d, R: %d, V: %d\n", left, middle, right, v);
        if (v == target) {
            pos = middle;
            break;
        } else if ( v < target) {
            left = middle;
        } else if ( v > target) {
            right = middle;
        }

        int d = right - left + 1;
        if ( d <= 2) {
            if (data[left] == target) {
                pos = left;
            } else if (data[right] == target) {
                pos = right;
            }

            break;
        } else {
            middle = left + (d >> 1);
        }
    }

    if (pos == -1) {
        printf("Not Found, Target: %d\n", target);
    } else {
        printf("Found Pos: %d, Target: %d, Value: %d\n", pos, target, data[pos]);
    }
    
    return 0;
}