//
// Created by 18657 on 2021/9/12.
// example 12.4 用广度优先搜索解迷宫问题
//

#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point {
    int row, col, predecessor;
} queue[512];
int head = 0, tail = 0;


void enqueue(struct point p) {
    queue[tail++] = p;
//    printf("执行入队操作, enqueue queue[%d]=(%d,%d,%d) => tail=%d\n", tail - 1, p.row, p.col, p.predecessor, tail);
}

struct point dequeue(void) {
    struct point p = queue[head++];
//    printf("执行出队操作, dequeue queue[%d]=(%d,%d,%d) => head=%d\n", head - 1, p.row, p.col, p.predecessor, head);
    return p;
}

int is_empty(void) {
    return head == tail;
}

int maze[MAX_ROW][MAX_COL] = {
        0, 1, 0, 0, 0,
        0, 1, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
};

void print_predecessor(struct point p) {
    printf("(%d, %d)\n", p.row, p.col);
    while (p.predecessor != -1) {
        p = queue[p.predecessor];
        printf("(%d, %d)\n", p.row, p.col);
    }
}

void print_maze(void) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}

void visit(int row, int col) {
//    printf("visit (%d,%d,%d) => ", row, col, head - 1);
    struct point visit_point = {row, col, head - 1};
    maze[row][col] = 2;
    enqueue(visit_point);
}

void print_queue() {
    printf("循环开始\n-- queue打印开始\n");
    for (int i = 0; i < 512; ++i) {
        struct point point = queue[i];
        if (point.row != 0 || point.col != 0) {
            printf("queue[%d] is (%d, %d, %d)", i, point.row, point.col, point.predecessor);
            if (head == i)printf(" <= head is here");
            if (tail == i)printf(" <= tail is here");
            printf("\n");
        }
    }
    printf("-- queue打印完毕\n");

}

int main(void) {

    setbuf(stdout, 0);

    struct point p = {0, 0, -1};
    enqueue(p);
    maze[p.row][p.col] = 2;

    while (!is_empty()) {
//        print_queue();
        p = dequeue();
        /* goal */
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)break;
        /* right */
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0)visit(p.row, p.col + 1);
        /* down */
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)visit(p.row + 1, p.col);
        /* left */
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)visit(p.row, p.col - 1);
        /* up */
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)visit(p.row - 1, p.col);

//        print_predecessor(p);
        print_maze();
    }
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
        print_predecessor(p);
    else
        printf("No path!\n");

    return 0;
}
