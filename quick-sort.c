/*------------------------------------------------------------------------------
* File Name:   quick-sort.c
* Purpose:     quick sort
*
* Author:      Ke Wang
*
* Created:     2019-11-07
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

/*
Worst time complexity: O(n^2)
Optimal time complexity: O(nlogn)
*/

#include <stdio.h>

#define N 10

int qsort(int arr[],int low,int high)
{
    /* 设置left and right两个索引，分别指向分段数据头尾,sort_key:数据分段排序基准值 */
    int left, right, sort_key;
    if (low >= high) return low;
    left = low;
    right = high;
    /* 设置分段数据的最左的值为分段排序基准值 */
    sort_key = arr[left];
    while (left < right) {  /* 左右两路包夹 */
        /* 数据索引从右边->左边于基准值比较 */
        while (right > left && arr[right] >= sort_key)
            --right;
        /* 直到发现小于基准值的数据，交换到数列左边 */
        arr[left] = arr[right];
        /* 数据索引从左边->右边于基准值比较 */
        while (left < right && arr[left] < sort_key)
            ++left;
        /* 直到发现大于基准值的数据，交换到数列右边 */
        arr[right] = arr[left];
    }
    /* After done, Find the sort_key correct position:left = right */
    arr[left] = sort_key;
    qsort(arr, low, left-1);   /* 对数组从低到以分界点-1进行排序 */
    qsort(arr, left+1, high);   /* 对数组从分界点+1到结尾进行排序 */
}

int main()
{
    int a[N] = {2, 32, 43, 23, 45, 36, 77, 13, 72, 29};
    int i;
    for (i =0; i < N; i++)
        printf("%3d",a[i]);
    printf("\n");
    qsort(a, 0, N -1);
    for (i =0; i < N; i++)
        printf("%3d",a[i]);
    return (0);
}
