/*------------------------------------------------------------------------------
* File Name:   linearlist.c
* Purpose:     Linear list implementation
*
* Author:      Ke Wang
*
* Created:     2019-10-28
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLISTSIZE 1024

typedef struct
{
    int data[MAXLISTSIZE];
    int last;
}linearlist;

void ListList(linearlist * list)
{
    int i;
    printf("Current linear list status:\n");
    if (list->last ==0) printf("Empty linear list!");
    else
        for(i = 0;i < (list->last); i++)
            printf("[%4d]", list->data[i]);
    printf("\n");
}

int main()
{
    return (0);
}
