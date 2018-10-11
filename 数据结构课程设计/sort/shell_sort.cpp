/*************************************************************************
	> File Name: shell_sort.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月12日 星期二 13时32分18秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int time_step_sh = 0;

void shell_sort(int *data, int n) {
    for(int i = n / 2; i > 0; i /= 2) {
        for(int j = i; j < n; j++) {
            if(data[j - i] > data[j]) {
                int data_now = data[j];
                int ip_last = j - i;
                //符合条件后，每次ip_last位置的变量都与当前位置变量比较，为了把当前变量放到一个合适的位置；
                while(ip_last >= 0 && data[ip_last] > data_now) {
                    time_step_sh++;
                    data[ip_last + i] = data[ip_last];
                    ip_last -= i;
                }
                data[ip_last + i] = data_now;
            }
        }
    }
    cout << "本次希尔排序用时：" << time_step_sh << endl;
}
