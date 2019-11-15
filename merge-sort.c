/*------------------------------------------------------------------------------
* File Name:   merge-sort.c
* Purpose:     Merge sort with non-recursive  
*
* Author:      Ke Wang
*
* Created:     2019-11-14
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

/* 相邻有序段合并
 * a[]  待排序数组
 * dest[] 保存合并后数据 
 * start 数组序列的起始序号
 * end 第一个数组序列的结束序号
 * n 有序列的长度
 */
void merge_step(int a[], int dest[], int start, int end, int n)
{
    int i, j, k;
    i = k = start;
    j =  end + 1;
    while (i <= end && j <= n) { //当两个有序段都还有数据，没有结束时，循环比较
        if (a[i] <= a[j])  //将较小的元素复制到dest数组中
            dest[k++] = a[i++];
        else
            dest[k++] = a[j++];
    }
    while (i <= end)  //将第一个未合并的部分复制到dest数组中
        dest[k++] = a[i++];
    while (j <= n)  //将第二个未合并的部分复制到dest数组中
        dest[k++] = a[j++];
}

/* 完成一次二路归并
 * a[]  待排序数组
 * dest[] 保存合并后数据 
 * n 待排序数组中进行排序的元素总数
 * len 有序列表的长度
 */
void merge_pass(int a[], int dest[], int n, int len)
{
    int start = 0, end; //start:第一个序列的起始序号,end:第一个序列的结束序号
    while (start + len < n) {
        end = start + 2 * len - 1;
        if (end >= n) //若最后一个数据段少于len, 重新计算结束序号
            end = n - 1;
        merge_step(a, dest, start, start+len-1, end);  //合并相邻有序段
        start = end + 1;  //重新计算下一对有序段中左段的开始序号
    }
    if (start < n)  //若还剩下一个有序段，从a中复制到dest数组
        for (; start < n; start++)
            dest[start] = a[start];
}

/*
 * 完成二路归并排序
 * a[]: 待排序数组
 * n: 待排序数组长度
 */
void merge_sort(int a[], int n)
{
    int *temp; //排序额外使用的临时存储空间
    int len = 1; //有序序列的长度
    int flag = 0; //发生排序标志位
    if (! (temp = (int*) malloc(sizeof(int) * n))) { //申请与数组a[]大小的存储空间
        printf("Failed to assign memory!");
        exit(0);
    }
    while (len < n) {  //交替在a[],temp之间来回进行合并
        if (flag)
            merge_pass(temp, a, n, len);  //把temp合并到a[]
        else
            merge_pass(a, temp, n, len);  //把a[]合并到temp
        len *= 2; //有序序列长度增加一倍
        flag = 1 - flag;  //使flag值在0和1之间进行切换
    }
    if (flag) //若进行了排序
        for (flag = 0; flag < n; flag++)  //将临时存储空间temp里的数据复制到数组a[]
            a[flag] = temp[flag];
    free(temp);  //释放临时存储空间
}

int main()
{
    // 非递归实现, 归并排序
    int a[N] = {22,18,45,98,66,34,25,11,72,9}; 
    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    merge_sort(a, N); 
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    return (0);
}
