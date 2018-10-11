/*************************************************************************
	> File Name: output.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月12日 星期二 16时41分46秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void output(int *data, int n) {
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            cout << " ";
        }
        cout << data[i];
    }
    cout << endl;
}
