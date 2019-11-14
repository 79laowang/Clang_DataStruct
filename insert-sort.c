/*------------------------------------------------------------------------------
* File Name:   select-sort.c
* Purpose:     Insert sort 
*
* Author:      Ke Wang
*
* Created:     2019-11-13
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

/* Worst time complexity: O(n^2) */
/* Optimal time complexity: O(n) */

#include <stdio.h>
#define N 10

void insert_sort(int a[], int n)
{
    int i, j, t;
    for (i = 1; i < n; i++) { //i遍历过的为有序区，剩下为无序区，有序区逐渐增长0->n-1,无序区n-1->0
        t = a[i];  // 保存要插入排序的数
        for (j = i - 1; j >= 0 && t < a[j]; --j) //在有序区查找位置
            a[j+1] = a[j]; //向后移动
        a[j+1] = t;  // 插入数据到找到的位置
    }
}

int main()
{
    int num[N] = {22,18,45,98,66,34,25,11,72,9}; 
    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    printf("\n");
    insert_sort(num, N);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    return (0);
}
