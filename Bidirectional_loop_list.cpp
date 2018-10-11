/*************************************************************************
> File Name: jisuanke_test.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年05月28日 星期一 11时01分43秒
************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

typedef struct Node {
    int data;
    struct Node *prior, *next;
}Node , *LinkedList;

void output_prior (LinkedList , int ); 
LinkedList insert (LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        head->next = head;
        head->prior = head;
        return head;
    }
    if (index == 0) {
        head->prior->next = node;
        node->prior = head->prior;
        head->prior = node;
        node->next = head;
        return head;
    }

    Node *current_node = head;
    head->prior->next = NULL;
    int count = 0;


    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    
    head->prior->next = head;

    Node *third_node = current_node->next;
    if (count == index - 1) {

        node->prior = third_node->prior;
        third_node->prior = node;

        node->next = current_node->next;
        current_node->next = node;

        return head;
    }

    return head;

}

void output_prior (LinkedList head, int start_num) {
    if (head == NULL) {
        return;
    }

    Node *start_node = head;
    while (start_node->data != start_num) {
        start_node = start_node->next;
    }

    Node *current_node = start_node;

    while (current_node->prior != start_node) {
        if (current_node != start_node) {
            cout << " ";
        }
        cout << current_node->data;
        current_node = current_node->prior;
    }
    cout << " " << current_node->data << endl;
    cout << endl;



    return;

}

void clear (LinkedList head) {
    Node *current_node = head;
    head->prior->next = NULL;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main () {

    LinkedList linkedlist = NULL;

    int n, value, start_num;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> value;

        Node *node = (Node *)malloc(sizeof(Node));
        node->data = value;
        node->prior = NULL;
        node->next = NULL;

        linkedlist = insert(linkedlist, node, i);

    }

    cin >> start_num;

    output_prior(linkedlist, start_num);

    clear(linkedlist);
 
    return 0;
}
