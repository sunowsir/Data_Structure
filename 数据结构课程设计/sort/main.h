/*************************************************************************
	> File Name: /home/sunowsir/文档/数据结构课程设计/main.h
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice: 
	> Created Time: 2017年12月12日 星期二 16时07分01秒
 ************************************************************************/


//替换初始化函数
#define cls(x, y) memset(x, y, sizeof(x))
//替换数据
const int max_n = 3e4 + 10;
//交换函数
void swap(int *,int *);
//输出函数
void output(int *, int);
//选择函数
bool selection(int *, int);
//插入排序
void insert_sort(int *, int);
//冒泡排序
void bubble_sort(int *, int);
//归并排序
int merge_sort(int *, int, int);
//选择排序
void selection_sort(int *data, int);
//快速排序
int quick_sort(int *, int, int);
//堆排序
void heap_sort(int *, int);
//希尔排序
void shell_sort(int *, int);

