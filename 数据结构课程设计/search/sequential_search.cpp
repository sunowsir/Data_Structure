/*************************************************************************
	> File Name: sequential_search.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月13日 星期三 08时42分26秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

return_information sequential_search(int *data, int n) {
    return_information ri_se;
    int time_se = 0;
    sort(data, data + n);
    for(int i = 0; i < n; i++) {
        time_se += i;
        if(data[i] == n / 2) {
            ri_se.loc = i + 1;
            ri_se.ASL = (double)time_se / (double)n;
            cout << "search success!\n";
            return ri_se;
        }
    }
    ri_se.loc = 0;
    ri_se.ASL = (double)time_se / (double)n;
    cout << "search false!\n";
    return ri_se;
}
