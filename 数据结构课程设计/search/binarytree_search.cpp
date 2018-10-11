/*************************************************************************
	> File Name: binarytree_search.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月13日 星期三 19时52分16秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_bt = 0;

typedef struct Node {
    int data, loc;
    struct Node *lchild, *rchild, *father;
} Node;

Node *init(int b_data, Node *b_father, char child) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = b_data;
    node->father = b_father;
    node->lchild = NULL;
    node ->rchild = NULL;
    if(node->father == NULL) {
        node->loc = 0;
    }
    else {
        if(child == 'l') {
            node->loc = node->father->loc * 2 + 1;
        }
        if(child == 'r') {
            node->loc = node->father->loc * 2 + 2;
        }
    }
    return node;
}

Node *insert(Node *node, int value) {
    if(node == NULL) {
        node = init(value, NULL, '0');
    }
    else if(value > node->data) {
        if(node->rchild == NULL) {
            node->rchild = init(value, node, 'r');
        }
        else {
            node->rchild = insert(node->rchild, value);
        }
    }
    else if(value < node->data) {
        if(node->lchild == NULL) {
            node->lchild = init(value, node, 'l');
        }
        else {
            node->lchild = insert(node->lchild, value);
        }
    }
    return node;
}

int search(Node *node, int value) {
    time_bt += (time_bt + 1);
    if(node == NULL) {
        return -1;
    }
    else if(node->data == value) {
        return node->loc;
    }
    else if(value > node->data) {
        if(node->rchild == NULL) {
            return -1;
        }
        else {
            return search(node->rchild, value);
        }
    }
    else {
        if(node->lchild == NULL) {
            return -1;
        }
        else {
            return search(node->lchild, value);
        }
    }
}

void clear(Node *node) {
    if(node != NULL) {
        if(node->lchild != NULL) {
            clear(node->lchild);
        }
        if(node->rchild != NULL) {
            clear(node->rchild);
        }
        free(node);
    }
}

return_information binarytree_search(int *data, int n) {
    Node *binarytree = NULL;
    return_information ri_bt;
    time_bt = 0;
    sort(data, data + n);
    for(int i = 0; i < n; i++) {
        binarytree = insert(binarytree, data[i]);
    }
    int temp_loc = search(binarytree, n / 2);
    if(temp_loc != -1) {
        ri_bt.loc = temp_loc;
        ri_bt.ASL = (double)time_bt / (double)n; 
        cout << "search success!\n";
    }
    else {
        ri_bt.loc = -1;
        ri_bt.ASL = (double)time_bt / (double)n;
        cout << "search failed!\n";
    }
    clear(binarytree);
    return ri_bt;
}
