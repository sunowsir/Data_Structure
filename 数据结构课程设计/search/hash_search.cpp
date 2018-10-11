/*************************************************************************
	> File Name: hash_search.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月13日 星期三 10时17分34秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_hash = 0;

typedef struct HashTable {
    int **elem;
    int size;
} Hashtable;

bool search(Hashtable *, int, int *, int *);
void recreate(Hashtable *);

void init(Hashtable *h, int size) {
    h->size = size;
    h->elem = (int **)malloc(sizeof(int *) * h->size);
    for(int i = 0; i < h->size; i++) {
        h->elem[i] = NULL;
    }
    return;
}

int hash(Hashtable *h, int value) {
    int code = 0;
    code = (~code) + (code << 21);
    code = code ^ (code >> 24); 
    code = (code + (code << 3)) + (code << 8);
    code = code ^ (code >> 14); 
    code = (code + (code << 2)) + (code << 4);
    code = code ^ (code >> 28); 
    code = code + (code << 31); 
    return code;
}

bool search(Hashtable *h, int search_value, int *pos, int *time) {
    *pos = hash(h, search_value);
    *time = 0;
    while(h->elem[*pos] != NULL && *(h->elem[*pos]) != search_value) {
        (*time)++;
        time_hash += (time_hash++);
        if(*time < h->size) {
            *pos = (*pos + 1) % h->size;
        }
        else {
            return false;
        }
    }
    if(h->elem[*pos] != NULL && *(h->elem[*pos]) == search_value) {
        time_hash++;
        return true;
    }
    else {
        return false;
    }
}

int insert(Hashtable *h, int value) {
    int pos, time;
    if(search(h, value, &pos, &time)) {
        return 2;
    }
    else if(time < h->size / 2) {
        h->elem[pos] = (int *)malloc(sizeof(int));
        *(h->elem[pos]) = value;
        return 1;
    }
    else {
        recreate(h);
        insert(h, value);
        return 0;
    }
}

void recreate(Hashtable *h) {
    int **temp_elem = (int **)malloc(sizeof(int *) * h->size);
    for(int i = 0; i < h->size; i++) {
        if(h->elem[i] != NULL) {
            temp_elem[i] = (int *)malloc(sizeof(int));
            *(temp_elem[i]) = *(h->elem[i]);
        }
        else {
            temp_elem[i] = NULL;
        }
    }
    for(int i = 0; i < h->size; i++) {
        if(h->elem[i] != NULL) {
            h->elem[i] = NULL;
        }
    }
    free(h->elem);
    int copy_size = h->size;
    init(h, h->size * 2);
    for(int i = 0; i < copy_size; i++) {
        if(temp_elem[i] != NULL) {
            insert(h, *(temp_elem[i]));
            free(temp_elem[i]);
        }
    }
    free(temp_elem);
}

void clear(Hashtable *h) {
    for(int i = 0; i < h->size; i++) {
        if(h->elem[i] != NULL) {
            free(h->elem[i]);
        }
    }
    free(h->elem);
    free(h);
}

return_information hash_search(int *data, int n) {
    Hashtable *hash = (Hashtable *)malloc(sizeof(Hashtable));
    init(hash, 31000);
    return_information ri_hash;
    for(int i = 0; i < n; i++) {
        insert(hash, data[i]);
    }
    int temp_pos, temp_time;
    time_hash = 0;
    if(search(hash, n / 2, &temp_pos, &temp_time)) {
        ri_hash.loc = temp_pos;
        ri_hash.ASL = (double)time_hash / (double)n;
        cout << "search success!\n";
    }
    else {
        ri_hash.loc = -1;
        ri_hash.ASL = (double)time_hash / (double)n;
        cout << "search false!\n";
    }
    clear(hash);
    return ri_hash;
}
