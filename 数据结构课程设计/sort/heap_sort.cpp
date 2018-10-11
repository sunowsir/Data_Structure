/*************************************************************************
	> File Name: /home/sunowsir/文档/数据结构课程设计/heap_sort.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月11日 星期一 14时25分03秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_step_h = 0;

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *) malloc(sizeof(int) * length_input);
    h->size = 0;
}

//插入函数
void push(Heap *h, int value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    //上滤
    while(h->data[current] > h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

//返回堆顶元素
int top(Heap *h) {
    return h->data[0];
}

//下滤函数
void update(Heap *h, int pos, int n) {
    time_step_h++;
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;
    int max_value = pos;
    if(lchild < n && h->data[lchild] > h->data[max_value]) {
        max_value = lchild;
    }
    if(rchild < n && h->data[rchild] > h->data[max_value]) {
        max_value = rchild;
    }
    if(max_value != pos) {
        swap(&h->data[max_value], &h->data[pos]);
        update(h, max_value, n);
    }
}

//弹出堆顶元素
void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

//实现函数
void heap_sort_realize(Heap *h) {
    for(int i = h->size - 1; i > 0; i--) {
        time_step_h++;
        swap(&h->data[i], &h->data[0]);
        update(h, 0, i);
    }
}

//转存函数
void unload(Heap *h, int *data) {
    for(int i = 0; i < h->size; i++) {
        data[i] = h->data[i];
    }
}

//清空函数
void clear(Heap *h) {
    free(h->data);
    free(h);
}

//堆排序的调用函数
void heap_sort(int *data, int length_data) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    init(heap, 31000);
    
    for(int i = 0; i < length_data; i++) {
        push(heap, data[i]);
    }
    heap_sort_realize(heap);
    unload(heap, data);
    cout << "本次堆排序用时：" << time_step_h << endl;
    clear(heap);
}
