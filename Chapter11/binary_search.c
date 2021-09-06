//
// Created by 18657 on 2021/9/4.
// example 11.4 二分查找
//

#define NDEBUG

#include <stdio.h>
#include <assert.h>

#define LEN 8
int a[LEN] = {1, 2, 2, 2, 5, 6, 8, 9};

int is_sorted(void) {
    int i;
    for (i = 1; i < LEN; i++)
        if (a[i - 1] > a[i])
            return 0;
    return 1;
}

int must_be(int start, int end, int number) {
    int i;
    for (i = 0; i < start; i++)
        if (a[i] == number)
            return 0;
    for (i = end + 1; i < LEN; i++)
        if (a[i] == number)
            return 0;
    return 1;
}

int contains(int n) {
    int i;
    for (i = 0; i < LEN; i++)
        if (a[i] == n)
            return 1;
    return 0;
}

int binary_search(int number) {
    int mid, start = 0, end = LEN - 1;

    assert(is_sorted());                            // Precondition
    while (start <= end) {
        assert(must_be(start, end, number));        // Maintenance
        mid = (start + end) / 2;
        if (a[mid] < number)
            start = mid + 1;
        else if (a[mid] > number)
            end = mid - 1;
        else {
            assert(mid >= start && mid <= end && a[mid] == number); // PostCondition 1
            if (start != end)
                end = mid;
            else
                return mid;
        }
    }
    assert(!contains(number));                                      // PostCondition 2
    return -1;
}

int main(void) {
    printf("%d\n", binary_search(2));
    return 0;
}
