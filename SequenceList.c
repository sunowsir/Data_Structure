/*************************************************************************
	> File Name: SequneceList.c
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月11日 星期一 09时09分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct sequence{
    int size, length;
    int *data;
}sequence;

void init_seq(sequence *seq, int size) {
    seq->size = size;
    seq->length = 0;
    seq->data = (int *)malloc(sizeof(int) * size);
}

void expand_seq(sequence *seq) {
    int *old_data = seq->data;
    seq->size *= 2;
    seq->data = (int *)malloc(sizeof(int) * seq->size);
    for(int i = 0; i < seq->length; i++) {
        seq->data[i] = old_data[i];
    }
    free(old_data);
    return;
}

void insert_seq(sequence *seq, int loc, int value) {
    if(loc < 0 || loc > seq->length){
        return;
    }
    if(seq->length >= seq->size) {
        expand_seq(seq);
    }
    for(int i = seq->length; i > loc; i--) {
        seq->data[i] = seq->data[i - 1];
    }
    seq->length++;
    seq->data[loc] = value;
    return;
}

int delete_seq(sequence *seq, int loc) {
    if(loc < 0 || loc > seq->length) {
        return 0;
    }
    for(int i = loc + 1; i < seq->length; i++) {
        seq->data[i - 1] = seq->data[i];
    }
    seq->length--;
    return 1;
}

int search_seq(sequence *seq, int value) {
    for(int i = 0; i < seq->length; i++) {
        if(seq->data[i] == value) {
            return 1;
        }
    }
    return 0;
}

void print_seq(sequence *seq) {
    for(int i = 0; i < seq->length; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", seq->data[i]);
    }
    printf("\n");
}

void clear_seq(sequence *seq) {
    free(seq->data);
    free(seq);
}

int main() {
    return 0;
}
