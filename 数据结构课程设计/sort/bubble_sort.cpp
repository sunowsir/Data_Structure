/*************************************************************************
	> File Name: /home/sunowsir/文档/数据结构课程设计/bubble_sort.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月11日 星期一 08时55分49秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_step_b = 0;

void bubble_sort(int *data, int length) {
    for(int i = 0; i < length - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < length - i - 1; j++) {
            if(data[j] > data[j + 1]) {
                time_step_b++;
                swap(&data[j], &data[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
    cout << "本次冒泡排序用时：" << time_step_b << endl;
    return;
}
