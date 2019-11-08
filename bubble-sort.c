/*------------------------------------------------------------------------------
* File Name:   bubble-sort.c
* Purpose:     冒泡排序,交换排序之一
*
* Author:      Ke Wang
*
* Created:     2019-10-28
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

/*
Worst time complexity: O(n^2)
Optimal time complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

/* 冒泡排序法 */
void bubble(char *arr, int n)
{
    int i,j;
    char temp;
    for (j= n; j > 0; j--) {
        int exchange = 0;
        for (i = 0; i < j-1; i++)
            if(arr[i+1] < arr[i]) { 
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                exchange = 1;
            }
        /* 如果没有发生交换，退出进入下一轮比较 */
        if (exchange == 0) break;
    }
    printf("Sorted output:[%s]\n",arr);
}

int main()
{
    char array[MAX];
    int count;
    printf("Input string to be sorted:\n");
    /* gets(array); */
    /* Obsleted function gets, using following handle the newline of end from fgets function */
	int i;
	while (fgets(array, MAX, stdin)!=NULL && array[0]!='\n')
	{
		i = 0;
	    while(array[i]!='\n' && array[i]!='\0')
			i++;
		if(array[i]=='\n') array[i]='\0';
		else
			while(getchar()!='\n')
				continue;
        count=strlen(array);
        bubble(array, count);
	}
    return (0);
}
