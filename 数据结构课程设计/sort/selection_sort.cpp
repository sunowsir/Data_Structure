/*************************************************************************
	> File Name: /home/sunowsir/文档/数据结构课程设计/selection_sort.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月11日 星期一 10时07分29秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_step_s = 0;

void selection_sort(int *data, int length) {
    int temp;
    for(int i = 0; i < length - 1; i++) {
        temp = i;
        for(int j = i + 1; j < length; j++) {
            time_step_s++;
            if(data[temp] > data[j]) {
                temp = j;
            }
        }
        if(i != temp) {
            swap(&data[i], &data[temp]);
        }
    }
    cout << "本次选择排序用时：" << time_step_s << endl;
}
