/*************************************************************************
	> File Name: main.h
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月13日 星期三 08时46分03秒
 ************************************************************************/
#include <bits/stdc++.h>

struct return_information {
    int loc;
    double ASL;
};

//选择函数
bool selection(int *, int);
//顺序查找
return_information sequential_search(int *, int);
//哈希
return_information hash_search(int *, int );
//二叉搜索树
return_information binarytree_search(int *, int);
