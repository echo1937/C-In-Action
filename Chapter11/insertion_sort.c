//
// Created by 18657 on 2021/8/29.
// Page 134
//

#include <stdio.h>

#define LEN 5
int a[LEN] = {10, 5, 2, 4, 7};

void insertion_sort(void) {
    for (int i, j = 1, key; j < LEN; j++) {
        printf("%d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4]);
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
    printf("%d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4]);
}

int main(void) {
    insertion_sort();
    return 0;
}

