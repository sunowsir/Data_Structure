/*
* File Name: stable_sort.cpp
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月04日 星期日 19时45分47秒
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

#define swap(a, b){ \
    a ^= b; b ^= a; a ^= b; \
}

/* 插入排序 
 * 这里，前面是已排序区，后面是待排序区*/
void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        /* j是待排序区的第一个元素，
         * 在这里，需要让j与j前面的元素不停的比较，
         * 一直到给j找到了一个合适的位置，
         * 这个循环可以用二分有花掉 
         */
        for (int j = i; j > 0 && num[j] < num[j - 1]; --j) {
            /* j的位置不合适，将其与其前面的元素进行交换 */
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

/* 冒泡排序 */
void bubble_sort(int *num, int n) {
    /* time，优化标记：
     * 由于冒泡排序会往后判断是否判断若干趟，
     * 因此若有某一次一次交换都没发生，
     * 说明已经达到有序，则直接可以结束排序
     */
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        /* 从`n - i` ~ `n - 1` 
         * 这个部分是已经有序的冒上来的泡泡
         */
        for (int j = 0; j < n - i; j++) {
            /* 符合要求顺序则跳过*/
            if (num[j] <= num[j + 1]) continue;
            times++;
            swap(num[j], num[j + 1]);
        }
    }
    return ;
}

/* 归并排序 */
void merge_sort(int *num, int l, int r) {
    /*递归到头，区间内小于等于2个元素
     * 也就是将数组中相邻的两个元素进行两两的处理*/
    if (r - l <= 1) {
        /* 若只剩两个元素，还不符合要求顺序则交换*/
        if (r - l == 1 && num[l] > num[r]) 
            swap(num[l], num[r]);
        return ;
    }

    /* 递归的不断进行分割 */
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);

    /* 开辟临时存储空间，来存储合并后的数据*/
    int *temp = (int *)malloc(sizeof(int) * (r - l) + 1);

    /* p1、p2：被分割的两个区间的开头下标
     * k：存储临时空间的有效数据长度
     */
    int p1 = l, p2 = mid + 1, k = 0;

    /* p1、p2只要有一个区间没有元素了，循环结束*/
    while (p1 <= mid || p2 <= r) {
        /* p1更符合序列顺序要求，或者p2没了*/
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) 
            temp[k++] = num[p1++];
        /* p2更符合序列顺序要求*/
        else 
            temp[k++] = num[p2++];
    }
    /* 把临时存储空间内的数据拷贝回num中 */
    memcpy(num + l, temp, sizeof(int) * (r - l) + 1);
    free(temp);
    return ;
}

void randint(int *num, int n) {
    while (n--) {
        num[n] = rand() % 100;
    }
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
    TEST(arr, MAX_OP, insert_sort, num, MAX_OP);
    TEST(arr, MAX_OP, bubble_sort, num, MAX_OP);
    TEST(arr, MAX_OP, merge_sort, num, 0, MAX_OP - 1);
    return 0;
}
