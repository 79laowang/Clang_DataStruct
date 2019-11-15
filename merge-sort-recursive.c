/*------------------------------------------------------------------------------
* File Name:   merge-sort.c
* Purpose:     Merge sort 
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

void MergeSort_UptoDown(int *num, int start, int end);
void Merge(int *num, int start, int mid, int end);

/* 将序列对半拆分直到序列长度为1*/
void MergeSort_UptoDown(int *num, int start, int end)
{
    int mid = start + (end - start) / 2;

    if (start >= end)
    {
        return;
    }
    
    MergeSort_UptoDown(num, start, mid);
    MergeSort_UptoDown(num, mid + 1, end);

    Merge(num, start, mid, end);
}

void Merge(int *num, int start, int mid, int end)
{
    int *temp = (int *)malloc((end-start+1) * sizeof(int));    //申请空间来存放两个有序区归并后的临时区域
    int i = start;  // 第一个合并序列的数组索引
    int j = mid + 1;  //第二个合并序列的数组索引
    int k = 0;        //临时存储数组索引

    while (i <= mid && j <= end) {
        if (num[i] <= num[j])
        {
            temp[k++] = num[i++];
        }
        else
        {
            temp[k++] = num[j++];
        }
    }

    while (i <= mid) {  // 将第一个合并序列的剩余数据，添加到临时存储
        temp[k++] = num[i++];
    }
    while (j <= end) {  // 第二个合并序列的剩余数据，添加到临时区域
        temp[k++] = num[j++];
    }

    //将临时区域中排序后的元素，整合到原数组中
    for (i = 0; i < k; i++) {
        num[start + i] = temp[i];
    }

    free(temp);
}

int main()
{
     /* 归并排序（升序） */
   int num[N] = {22,18,45,98,66,34,25,11,72,9}; 
    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    printf("\n");
    MergeSort_UptoDown(num, 0, N - 1);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    return (0);
}
