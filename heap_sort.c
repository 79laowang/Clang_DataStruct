/*------------------------------------------------------------------------------
* File Name:   heap_sort.c
* Purpose:     堆排序
*
* Author:      Ke Wang
*
* Created:     2019-11-14
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#define N 10

void heap_adjust(int a[], int s, int n)
{
    int j, t;
    while (2 * s + 1 < n) {  //当第s个根节点有右子树
        j = 2 * s + 1;
        if ((j + 1 < n)) {
            if (a[j] < a[j+1])  // 左子树(j)小于右子树(j+1)，则需要比较右子树
                j++;  // 指向右子树
        }
        if (a[s] < a[j]) { // 如果父节点小于右节点,根和右子树交换
            t = a[s];
            a[s] = a[j];
            a[j] = t;
            s = j;  //交换后，新父节点，重新调整堆
        } else 
            break;
    }
}

void heap_sort(int a[], int n)
{
    int t, i;
    for (i = n/2 - 1; i >= 0; i--)  //i指向父节点，将a[0]到a[n-1]构成堆
        heap_adjust(a, i, n);
    for (i = n - 1; i > 0; i--) {  // 取根节点和末节点交换
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        heap_adjust(a ,0 ,i); // 将a[0]至a[i]重新调整为堆
    }
}

int main()
{
    int a[N] = {22,18,45,98,66,34,25,11,72,9};
    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    heap_sort(a, N);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    return (0);
}
