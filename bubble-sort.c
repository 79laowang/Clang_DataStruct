/*------------------------------------------------------------------------------
* File Name:   bubble-sort.c
* Purpose:     冒泡排序 
*
* Author:      Ke Wang
*
* Created:     2019-10-28
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

/* 冒泡排序法 */
void bubble(char *arr,int count)
{
    int i,j;
    char temp;
    for(j=count;j>1;j--)
    {
        for(i=0;i<j-1;i++)
            if(arr[i+1]<arr[i])
            {
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
    }
    printf("Sorted output:[%s]\n",arr);
}

int main()
{
    char array[MAX];
    int count;
    printf("Input string to be sorted:\n");
    gets(array);
    /* fgets(array, sizeof(array), stdin); */
    count=strlen(array);
    bubble(array,count);
    return (0);
}
