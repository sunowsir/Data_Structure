/*************************************************************************
	> File Name: main.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月13日 星期三 22时19分14秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int main() {
    int data[31000], n;
    memset(data, 0, sizeof(data));
    while(true) {
        cout << "输入0结束程序" << endl;
        cout << "输入1继续程序" << endl;
        int temp = 1;
        cin >> temp;
        if(!temp) {
            break;
        }
        cout << "请输入本组数据个数" << endl;
        cin >> n;
        cout << "请输入本组数据" << endl;
        for(int i = 0; i < n; i++) {
            cin >> data[i];
        }
        while(true) {
            int data_temp[31000];
            memset(data_temp, 0, sizeof(data_temp));
            for(int i = 0; i < n; i++) {
                data_temp[i] = data[i];
            }
            if(selection(data_temp, n)) {
                cout << "输入0结束本次查找" << endl;
                cout << "输入1继续选择查找方式" << endl;
                int temp = 0;
                cin >> temp;
                if(temp) {
                    continue;
                }
                else {
                    break;
                }
            }
            
        }
    }
    return 0;
}
