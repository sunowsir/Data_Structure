/*************************************************************************
	> File Name: selection.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月13日 星期三 22时59分30秒
 ************************************************************************/

#include <bits/stdc++.h>
#include "main.h"
using namespace std;

bool selection(int *data, int n) {
    int selec;
    return_information ri_se;
    cout << "请选择查找方式" << endl;
    cout << "1. 顺序查找" << endl;
    cout << "2. 哈希查找" << endl;
    cout << "3. 二叉搜索树" << endl;
    cin >> selec;
    switch(selec) {
        case 1 :{
            cout << "顺序查找" << endl;
            ri_se = sequential_search(data, n);
            cout << "n / 2 元素的位置为： " << ri_se.loc << endl;
            cout << "本次查找的查找长度为：" << ri_se.ASL << endl;
            return true;
        }
        case 2 :{
            cout << "哈希查找" << endl;
            ri_se = hash_search(data, n);
            cout << "n / 2 元素的位置为：" << ri_se.loc << endl;
            cout << "本次查找的查找长度为：" << ri_se.ASL << endl;
            return true;
        }
        case 3 :{
            cout << "二叉搜索树" << endl;
            ri_se = binarytree_search(data, n);
            cout << "n / 2 元素的位置为：" << ri_se.loc << endl;
            cout << "本次查找的查找长度为：" << ri_se.ASL << endl;
            return true;
        }
        default :{
            cout << "输入不合法" << endl;
            cout << "请重新选择" << endl;
            return false;
        }
    }
}
