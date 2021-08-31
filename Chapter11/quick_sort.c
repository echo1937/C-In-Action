#include <stdio.h>

#define LEN 8
int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

void swap(int n1, int n2) {
    int tmp = a[n1];
    a[n1] = a[n2];
    a[n2] = tmp;
}

int partition(int start, int end) {
    /**
     * pivot表示选择的基准点, 从最左侧开始
     * index表示保存点, 从(基准点+1)开始
     */
    int pivot = start, index = pivot + 1;

    for (int i = index; i <= end; ++i) {
        /**
         * 当前点如果大于基准点, 位置保持不变;
         * 当前点如果小于基准点, 当前点和保存点交换元素, 保存点前移(如果当前点就是保存点, 则实际无变化)
         */
        if (a[i] < a[pivot]) {
            swap(i, index);
            index++;
        }
    }
    swap(pivot, index - 1);
    return index - 1;
}

int partition_overload(int start, int end) {
    int pivot = start;

    while (start < end) {
        // 每次改变start/end之后, 都需要重新判定start < end
        while (a[pivot] <= a[end] && start < end)end--;
        while (a[start] <= a[pivot] && start < end)start++;
        if (start < end) swap(start, end);
    }
    swap(pivot, end);
    return end;
}

void quickSort(int start, int end) {
    if (start < end) {
        int mid = partition_overload(start, end);
        printf("partition (%d-%d, mid=%d) %d %d %d %d %d %d %d %d\n",
               start, end, mid,
               a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
        quickSort(start, mid - 1);
        quickSort(mid + 1, end);
        printf("quickSort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",
               start, mid - 1, mid + 1, end,
               a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    }
}

int main() {
    quickSort(0, LEN - 1);
}