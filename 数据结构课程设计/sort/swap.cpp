/*************************************************************************
	> File Name: /home/sunowsir/文档/数据结构课程设计/swap.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月11日 星期一 09时09分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
