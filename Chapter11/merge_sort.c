//
// Created on 2021/8/30.
// Page 139
//
#include <stdio.h>

#define LEN 8
int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

void merge(int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    /**
     * https://www.zhihu.com/question/367672681
     * https://akaedu.github.io/book/ch08s01.html
     */
    int left[n1], right[n2];            //

    for (int i = 0; i < n1; i++)        // left holds a[start..mid]
        left[i] = a[start + i];
    for (int i = 0; i < n2; i++)        // right holds a[mid+1..end]
        right[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];

    while (i < n1)                  // left[] is not exhausted
        a[k++] = left[i++];
    while (j < n2)                  // right[] is not exhausted
        a[k++] = right[j++];
}

void sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",
               start, mid, mid + 1, end,
               a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
        sort(start, mid);
        sort(mid + 1, end);
        merge(start, mid, end);
        printf("merge (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d\n",
               start, mid, mid + 1, end,
               a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    }
}

int main(void) {
    sort(0, LEN - 1);
    return 0;
}