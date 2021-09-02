/*
 * File Name:    trie.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月30日 星期日 20时38分43秒
 */

/* 字典树 */

#include <stdio.h>
#include <stdlib.h>

/* 首字母 */
#define BASE 'a'

/* 每个节点的子节点的个数 */
#define BASE_CNT 26

/* 数据结构定义*/
typedef struct Node {
    /* 标记：用来标记是否是一个完整的字符串 */
    int flag;
    /* BASE_CNT 个子节点数组 */
    struct Node *next[BASE_CNT];
} Node;

/* 获取新节点 */
Node *getNewNode() {
    /* 为新节点分配空间 */
    Node *p = (Node *)malloc(sizeof(Node));
    /* 初始化子节点数组*/
    for (int i = 0;i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    /* 初始化标记 */
    p->flag = 0;
    return p;
    
}

/* 插入字符串到以node为根的字典树中 */
void insert(Node *node, const char *str) {
    Node *p = node;
    /* 遍历字符串 */
    for (int i = 0; str[i]; i++) {
        /* 当前节点p对应字符串的当前字符的那个节点如果为空
         * 说明当前没有字符串和该字符串共用这个字符，
         * 那就需要获取一个新节点
         */
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }

        /* 无论是否发生上述情况，该字符串当前字符都已经处理完
         * 顺着当前字符对应的子节点往下跑
         */
        p = p->next[str[i] - BASE];
    }
    /* 最后字符串最后一个字符也已经在该字典树中找到或者新建节点了
     * 就该在最后一个字符对应的该节点p设置一下flag 表示到这里
     * 是一个完整的字符串
     */
    p->flag = 1;
    return ;
}

/* 在以node为根节点的字典树中查找字符串str 
 * 找到返回1
 * 否则返回0
 */
int search(Node *node, const char *str) {
    Node *p = node;
    /* 遍历字符串的每一个字符*/
    for (int i = 0; str[i]; i++) {
        /* 当前节点p对应字符串的当前字符的这个节点为空
         * 说明当前没有字符串和该字符串共用这个字符，
         * 在insert中需要做的是新建节点，那么在search中
         * 就说明node为根的字典树中没有这个字符串，
         * 匹配到这里找不到了
         */
        if (p->next[str[i] - BASE] == NULL)
            return 0;
        /* 程序执行到这里说明当前字符匹配成功了，
         * 那就顺着匹配到的p的子节点往下跑
         */
        p = p->next[str[i] - BASE];
    }
    /* 整个字符串都跑完了没有直接返回0，
     * 说明匹配成功了，返回1，
     * （见insert, 字符串全部插入完成后，最后一个字符的flag会被置为1）
     */
    return p->flag;
}

/* 清空以node为根节点的字典树，
 * 这里没什么可说的，就是递归释放
 */
void clear(Node *node) {
    if (node == NULL) {
        return ;
    }
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int main() {
    Node *root = getNewNode();
    char str[100];
    int op;
    while (scanf("%d%s", &op, str) != EOF) {
        switch (op) {
            case 1 : {
                printf("insert %s to trie\n", str);
                insert(root, str);
            }break;
            case 2 : {
                printf("search %s from trie = %d\n", str, search(root, str));
            }break;
        }
    }

    clear(root);
    
    return 0;
}
