/*************************************************************************
	> File Name: insert_sort.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月11日 星期一 08时40分48秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_step_i = 0;

void insert_sort(int *data, int length) {
    for(int i = 0; i < length; i++) {
        for(int j = i - 1; j >= 0; j--) {
            time_step_i++;
            if(data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
            }
            else {
                break;
            }
        }
    }
    cout << "本次插入排序用时：" << time_step_i << endl;
    return;
}
