//
// Created by 18657 on 2021/9/5.
// example 12.3 用深度优先搜索解迷宫问题
// https://intellij-support.jetbrains.com/hc/en-us/community/posts/115000740490/comments/115000615644
//

#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point {
    int row, col;
} stack[512];
int top = 0;

int maze[MAX_ROW][MAX_COL] = {
        0, 1, 0, 0, 0,
        0, 1, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
};

struct point predecessor[MAX_ROW][MAX_COL] = {
        {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
        {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
        {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
        {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
        {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
};

void push(struct point p) {
    stack[top++] = p;
    printf("执行出栈操作, push stack[%d]=(%d-%d) => top=%d\n", top - 1, p.row, p.col, top);
}

struct point pop(void) {
    struct point p = stack[--top];
    printf("执行入栈操作, pop stack[%d]=(%d-%d) => top=%d\n", top, p.row, p.col, top);
    return p;
}

int is_empty(void) {
    return top == 0;
}

void print_predecessor(struct point p) {
    printf("(%d, %d)\n", p.row, p.col);
    while (predecessor[p.row][p.col].row != -1) {
        p = predecessor[p.row][p.col];
        printf("(%d, %d)\n", p.row, p.col);
    }
}

void print_maze(void) {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}

void visit(int row, int col, struct point pre) {
    printf("visit (%d-%d) => ", row, col);
    struct point visit_point = {row, col};
    push(visit_point);              // stack压栈
    maze[row][col] = 2;             // 迷宫路线保存
    predecessor[row][col] = pre;    // 前任位置保存
}

void print_stack() {
    printf("循环开始\n-- stack打印开始\n");
    for (int i = 0; i < 512; ++i) {
        struct point point = stack[i];
        if (point.row != 0 || point.col != 0) {
            printf("stack[%d] is (%d, %d)\n", i, point.row, point.col);
        }
    }
    printf("-- stack打印完毕\n");
}

int main(void) {

    setbuf(stdout, 0);

    struct point p = {0, 0};
    push(p);
    maze[p.row][p.col] = 2;

    while (!is_empty()) {
//        print_stack();
        p = pop();
        /* goal */
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)break;
        /* right */
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0)visit(p.row, p.col + 1, p);
        /* down */
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)visit(p.row + 1, p.col, p);
        /* left */
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)visit(p.row, p.col - 1, p);
        /* up */
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)visit(p.row - 1, p.col, p);

//        print_predecessor(p);
        print_maze();

    }
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
        print_predecessor(p);
    else
        printf("No path!\n");

    return 0;
}