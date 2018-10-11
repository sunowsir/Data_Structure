/*************************************************************************
	> File Name:    Linklist.cpp
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年10月11日 星期四 21时48分09秒
 ************************************************************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->length = 0;
    return p;
}

LinkNode *getNewNode(int value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = value;
    p->next = NULL;
    return p;
}

void insert(LinkList *l, int value, int ind) {
    // 创建虚拟节点
    LinkNode *p = &(l->head);

    // 找到需要插入的位置的前一个节点
    while (ind--) {
        p = p->next;
        if (p == NULL) {
            return ;
        }
    }

    // 创建一个新的节点；
    LinkNode *insert_node = getNewNode(value);
    
    // 让新节点的next指向虚拟节点的下一个节点，更新头结点，让头结点的next指向链表头
    insert_node->next = p->next;
    p->next = insert_node;
    
    //链表长度加1
    l->length += 1;

    return ;
}

// delete
void erase(LinkList *l, int ind) {
    LinkNode *p = &(l->head);
    while(ind--) {
        p = p->next;
        if (p == NULL) {
            return ;
        }
    }
    if (p->next == NULL) {
        return ;
    }
    LinkNode *delete_node = p->next;
    p->next = p->next->next;
    free(delete_node);
    l->length -= 1;
    return ;
}

void clear(LinkList *l) {
    if (l->head.next == NULL) {
        return ;
    }
    LinkNode *now_node = l->head.next, *free_node;
    while (now_node) {
        free_node = now_node;
        now_node = now_node->next;
        free(free_node);
    }
    free(l);
    return ;
}

void output(LinkList *l) {
    printf("[%.2d] ", l->length);
    LinkNode *output_node = l->head.next;
    while (output_node) {
        printf(" %d -> ", output_node->data);
        output_node = output_node->next;
    }
    printf(" NULL\n");
    return ;
}

int main() {

    srand(time(0));
    LinkList *l = init();

    #define MAX_OP 20

    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value, ind;

        switch (op) {
            case 0 : 
            case 1 : 
            case 2 : {
                ind = rand() % (l->length + 1);
                value = rand() % 100;
                printf("insert(%d, %d) to LinkList\n", value, ind);
                insert(l, value, ind);
                output(l);
            } break;
            case 3 : {
                if (l->length == 0) {
                    break;
                }
                ind = rand() % l->length;
                printf("erase(%d) from LinkList\n", ind);
                erase(l, ind);
                output(l);
            } break;
        }

    }

    #undef MAX_OP

    clear(l);

    return 0;
}
