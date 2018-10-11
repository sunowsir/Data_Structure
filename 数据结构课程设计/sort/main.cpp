/*************************************************************************
	> File Name: main.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月12日 星期二 14时30分18秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int main() {
    while(true) {
        int data[max_n], temp, data_num;
        cls(data, 0);
        cout << "输入0结束程序" << endl;
        cout << "输入1继续程序" << endl;
        cin >> temp;
        if(!temp) {
            break;
        }
        cout << "请输入要排序的数以空格隔开" << endl;
        cout << "输入任意的负数即可结束本组数据的输入结束" << endl;
        int i;
        for(i = 0;data[i] >= 0;i++) {
            int data_temp;
            cin >> data_temp;
            if(data_temp < 0) {
                cout << "本组数据输入结束" << endl;
                break;
            }
            else if(data_temp >= 0 && data_temp <= 30000) {
                data[i] = data_temp;
            }
            else if(data_temp > 30000) {
                cout << "输入数据超出范围" << endl;
                i--;
            }
        }
        data_num = i;
        while(true) {
            int data_temp[max_n];
            cls(data_temp, 0);
            for(int i = 0; i < data_num; i++) {
                data_temp[i] = data[i];
            }
            if(selection(data_temp, data_num)) {
                cout << "输入1查看本次排序后的数据" << endl;
                cout << "输入2继续选择排序方式" << endl;
                cout << "输入0结束本组数据排序" << endl;
                int temp = 0;
                cin >> temp;
                if(temp == 1) {
                    output(data_temp, data_num);
                    cout << "输入0结束本组数据排序" << endl;
                    cout << "输入其他整型数继续" << endl;
                    int temp = 1;
                    cin >> temp;
                    if(!temp) {
                        break;
                    }
                }
                else if(temp == 2) {
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

