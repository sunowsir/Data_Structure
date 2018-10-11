/*************************************************************************
	> File Name: /home/sunowsir/文档/数据结构课程设计/merge_sort.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月11日 星期一 09时51分41秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_step_m = 0;

int merge_sort(int *data, int l, int r) {
    if(l == r) {
        return time_step_m;
    }
    int mid = (l + r) / 2;
    merge_sort(data, l, mid);
    merge_sort(data, mid + 1, r);
    int x = l, y = mid + 1, loc = 0;
    int temp[r - l + 1];
    cls(temp, 0);
    while(x <= mid || y <= r) {
        time_step_m++;
        if(x <= mid && (y > r || data[x] <= data[y])) {
            temp[loc] = data[x];
            x++;
        }
        else {
            temp[loc] = data[y];
            y++;
        }
        loc++;
    }
    for(int i = l; i <= r; i++) {
        time_step_m++;
        data[i] = temp[i - l];
    }
    return time_step_m;
}
