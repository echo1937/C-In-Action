//
// Created by 18657 on 2021/9/16.
// example 22.1 指针参数和返回值

#include <stdio.h>

int *swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
    return px;
}

int main(void) {
    int i = 10, j = 20;
    int *p = swap(&i, &j);
    printf("now\n i=%d\n j=%d\n *p=%d\n", i, j, *p);
    return 0;
}