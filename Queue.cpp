/*
 *	 File Name:    Queue.cpp
 *	 Author:       sunowsir
 *	 Mail:         sunowsir@protonmail.com
 *	 Created Time: 2018年10月22日 星期一 16时37分34秒
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct Queue {
    int *data;
    int cnt, head, tail, length;
} Queue;

Queue *init(int length) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * length);
    q->cnt = 0;
    q->head = 0;
    q->tail = -1;
    q->length = length;
    return q;
}

bool empty(Queue *q) {
    return q->cnt == 0;
}

bool push(Queue *q, int value) {
    if (q->cnt == q->length) {
        return false;
    }
    q->cnt += 1;
    q->tail += 1;
    if (q->tail >= q->length) {
        q->tail -= 1;
    }
    q->data[q->tail] = value;
    return true;
}

bool pop(Queue *q) {
    if (empty(q)) {
        return false;
    }
    q->cnt -= 1;
    q->head += 1;
    if (q->head >= q->length) {
        q->head -= q->length;
    }
    return true;
}

int front(Queue *q) {
    if (empty(q)) {
        return -1;
    }
    return q->data[q->head];
}

void clear(Queue *q) {
    if (q == NULL) {
        return ;
    }
    free(q->data);
    free(q);
    return ;
}

int main() {
    return 0;
}
