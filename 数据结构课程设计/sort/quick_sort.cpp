/*************************************************************************
	> File Name: /home/sunowsir/文档/数据结构课程设计/quick_sort.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月11日 星期一 10时16分15秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_step_q = 0;

int quick_sort(int *data, int left, int right) {
    if(left >right) {
        return time_step_q;
    }
    int pivot = data[left], low = left, high = right;
    while(low < high) {
        time_step_q++;
        while(low < high && data[high] >= pivot) {
            high--;
            time_step_q++;
        }
        data[low] = data[high];
        while(low < high && data[low] <= pivot) {
            low++;
            time_step_q++;
        }
        data[high] = data[low];
    }
    data[low] = pivot;
    quick_sort(data, left, low - 1);
    quick_sort(data, low + 1, right);
    return time_step_q;
}

 
