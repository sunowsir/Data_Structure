/*
* File Name: unstable_sort.cpp
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月04日 星期日 20时35分50秒
*/

#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TEST(arr, n, func, args...) { \
    int *num = (int *)malloc(sizeof(int) * n); \
    memcpy(num, arr, sizeof(int) * n); \
    output(num, n); \
    printf("%s = ", #func); \
    func(args); \
    output(num, n); \
    free(num); \
}
   

#define swap(a, b) { \
    __typeof(a) __temp = (a); (a) = (b); b = (__temp); \
}

/* 选择排序 */
void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        /* 用来记录待排序区找到的最小（按照需求或最大）的元素 */
        int ind = i;
        /* 从待排序区找到一个最小的元素 */
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        /* 与待排序区的第一个元素交换
         * （相当于将找到的合适的元素放到已排序区的末尾）
         */
        swap(num[i], num[ind]);
    }
    return ;
}

/* 快速排序 */
void quick_sort(int *num, int l, int r) {
    /* 右边界小于等于左边界说明区间没东西了，该结束了 */
    if (r <= l) return ;

    /* 左边界x, 右边界y，以及中间值z */
    int x = l, y = r, z = num[l];

    /* 以左边界为例：
     * 若满足左侧值小于中间值则向中心缩小做边界，
     * 右侧如此*/
    while (x < y) {
        /* 缩小右边界*/
        while (x < y && num[y] >= z) --y;
        /* 如上循环跳出说明当前右边界的值小于中间值，符合调整条件
         * （左侧值大于中间值，右侧值小于中间值，否则发生调整），
         * 把右边界值放到当前左边界的位置，左边界网右调整一位
         * （由于z保存的就是原x值，因此不必担心原x指向值会丢失）
         */
        if (x < y) num[x++] = num[y];

        /* 缩小左边界 */
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    /* 因为所有的操作都是以最开始的左边界值x作为依据进行判断的， 
     * 因此循环结束后x和y所在的位置就是中心值z也就是最初的左边界值x
     * 而这个值从第一次发生调整就被覆盖了，因此需要将这个名副其实的中间值赋值回来*/
    num[x] = z;

    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}


void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("]\n");
    return ;
}


int main () {
    srand(time(0));
    #define MAX_OP 20
    int arr[MAX_OP];
    randint(arr, MAX_OP);
    TEST(arr, MAX_OP, select_sort, num, MAX_OP);
    TEST(arr, MAX_OP, quick_sort, num, 0, MAX_OP - 1);
    return 0;
}
