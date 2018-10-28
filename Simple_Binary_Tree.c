/* 
 * File Name:    Simple_Binary_Tree.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月28日 星期日 15时31分34秒
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *init(int data) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

Node *build(/* String, interger, or other data used to create a binary tree. */) {
    Node *root = NULL;
    /* Call init() to add a node according to requirements. */
    return root;
}

void preorder(Node *root) {
    if (root == NULL) {
        return ;
    }
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
    return ;
}

void inorder(Node *root) {
    if (root == NULL) {
        return ;
    }
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
    return ;
}

void postorder(Node *root) {
    if (root == NULL) {
        return ;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
    return ;
}

int clear(Node *root) {
    if (root == NULL) {
        return 0;
    }
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return 1;
}

int main () {
    return 0;
}
