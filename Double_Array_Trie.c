/*
 * File Name:    Double_Array_Trie.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月06日 星期日 15时15分31秒
 */

/* 双数组字典树 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int flag;
    struct Node *next[26];
} Node;

typedef struct DATNode {
    /* base : 用来计算得到当前节点的子节点
    *  check ：当前节点的父亲节点，
    *  若当前节点为独立成词的最后一个字母，那么当前节点的check为负*/
    int base, check;
} DATNode;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) {
            p->next[str[i] - 'a'] = getNewNode();
            cnt += 1;
        }
        p = p->next[str[i] - 'a'];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) {
        return ;
    }
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

/* 以上方法是原生Trie树（字典树） */

/* 获取一个新的Base值：
 * 一个有效的Base值必须得是从 base + 0 一直到base + 25这26个子节点都是空节点 
 * */
int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 0;
    while (!flag) {
        flag = 1;

        /* 计算得到一个Base值，
         * 可以用其他更高效的计算方式，一个一个递增还是很慢的
         */
        base += 1;

        /* 判断该Base值能不能用，
         * 要么通过朴素字典树判断每个子节点都是空的，
         * 要么check是无效的也成
         */
        for (int i = 0; i < 26; i++) {
            /* 通过朴素字典树判断该子节点为空可以 */
            if (node->next[i] == NULL) continue;

            /* 由于根节点是从1开始的，因此如果check为无效的0, 
             * 说明这是个空节点, 当然也也可以 */
            if (trie[base + i].check == 0) continue;

            /* 至此，
             * 说明该Base值已经有人用了，
             * flag标记为0，Base不行，跳出去再整一个Base接着判断看能能用
             */

            flag = 0;
            break;
        }
    }
    return base;
}

void Transform(Node *node, DATNode *trie, int ind) {
    if (ind == 1) trie[ind].check = 1;

    /* 独立成词check记为负 */
    if (node->flag) 
        trie[ind].check = -trie[ind].check;

    trie[ind].base = getBase(node, trie);
    /* 确定当前节点的每个非空子节点的check */
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        /* ind节点，base值 + i  */
        trie[trie[ind].base + i].check = ind;
    }
    /* 递归向下确定子树 */
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        Transform(node->next[i], trie, trie[ind].base + i);
    }
    return ;
}

int search(DATNode *trie, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        /* 当check == p，说明当前字符找到了 */
        if (check != p) return 0;
        p = trie[p].base + delta;
    }
    return (trie[p].check < 0);
}

int main() {
    int n, cnt = 1;
    char str[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    printf("Node build success.\n");
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10);
    Transform(root, trie, 1);
    printf("DATNode build success.\n\n");
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", str, search(trie, str));
    }
    
    clear(root);
    return 0;
}
