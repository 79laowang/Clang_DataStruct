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

void merge_step(int a[], int r[], int start, int mid, int end)
{
    int i, j, k;
    i = k = start;
    j = mid + 1;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j])
            r[k++] = a[i++];
        else
            r[k++] = a[j++];
    }
    while (i <= mid)
        r[k++] = a[i++];
    while (j <= end)
        r[k++] = a[j++];
}

void merge_pass(int a[], int r[], int n, int len)
{
    int s, e;
    s = 0;
    while (s + len < n) {
        e = s + 2 * len - 1;
        if (e >= n)
            e = n - 1;
        merge_step(a, r, s, s+len-1, e);
        s = e + 1;
    }
    if (s < n)
        for (; s < n; s++)
            r[s] = a[s];
}

void merge_sort(int a[], int n)
{
    int *p;
    int len = 1;
    int f = 0;
    if (! (p = (int*)malloc(sizeof(int) *n))) {
        printf("Failed to assign memory!");
        exit(0);
    }
    while (len < n) {
        if (f)
            merge_pass(p, a, n, len);
        else
            merge_pass(a, p, n, len);
        len *= 2;
        f = 1 - f;
    }
    if (f)
        for (f = 0; f < n; f++)
            a[f] = p[f];
    free(p);
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
