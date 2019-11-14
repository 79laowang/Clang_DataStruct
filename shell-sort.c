/*------------------------------------------------------------------------------
* File Name:   select-sort.c
* Purpose:     Shell insert sort 
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

void shell_sort(int a[], int n)
{
    int d, i, j, x;
    d = n / 2;  // 计算第一次增量值
    while (d >= 1){  //直到增量为1,退出排序
        for (i = d; i < n; i++) {
            x = a[i];  //暂存排序数列值
            j = i -d;  //计算增量对应的比较值
            while (j >= 0 && x < a[j]) { //比较两值，若后一个值小，进行交换
                a[j+d] = a[j];  // 把大数后移
                j = j -d;  //继续比较下一组
            }
            a[j+d] = x;  // 找到x合适位置，保存
        }
        d /= 2; //缩小增量
    }
}

int main()
{
    int num[N] = {22,18,45,98,66,34,25,11,72,9}; 
    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    printf("\n");
    shell_sort(num, N);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    return (0);
}
