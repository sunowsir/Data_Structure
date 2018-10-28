/*
 *	 File Name:    Stack.cpp
 *	 Author:       sunowsir
 *	 Mail:         sunowsir@protonmail.com
 *	 Created Time: 2018年10月22日 星期一 16时53分08秒
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

bool empty(Stack *s) {
    return s->top == -1;
}

bool push(Stack *s, int value) {
    if (s->top + 1 >= s->size) {
        return false;
    }
    s->top += 1;
    s->data[s->top] = value;
    return true;
}

bool pop(Stack *s) {
    if (empty(s)) {
        return false;
    }
    s->top -= 1;
    return true;
}

int top(Stack *s) {
    if (empty(s)) {
        return -1;
    }
    return s->data[s->top];
}

void clear(Stack *s) {
    if (s == NULL) {
        return ;
    }
    free(s->data);
    free(s);
    return ;
}

int main() {
    return 0;
}
