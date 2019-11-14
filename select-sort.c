/*------------------------------------------------------------------------------
* File Name:   select-sort.c
* Purpose:     Selection sort 
*
* Author:      Ke Wang
*
* Created:     2019-11-13
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

/* Worst time complexity: O(n^2) */
/* Optimal time complexity: O(n^2) */

#include <stdio.h>
#define N 10

#define exchange(a,b) {\
    int t;\
    t=a;\
    a=b;\
    b=t;\
}

void select_sort(int a[], int n)
{
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_index])
                min_index = j;
        if (i != min_index) {   /* If a[i] is not minimum number, exchange it */
            exchange(a[i],a[min_index]);
            /* int t; */
            /* t = a[i];a[i]=a[min_index];a[min_index]=t; */
        }
    }
}

int main()
{
    int num[N] = {22,18,45,98,66,34,25,11,72,9}; 
    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    printf("\n");
    select_sort(num, N);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", num[i]);
    return (0);
}
