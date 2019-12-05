/*------------------------------------------------------------------------------
* File Name:   main.c
* Purpose:    
*
* Author:      Ke Wang
*
* Created:     2019-12-05
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include "common.h"

int main()
{
    Node p;
    int i;
    printf("Insert node:\n");
    for (i = 1; i < 8; i++)  // 插入链表节点
        insert(i);
    print();  // 遍历链表，打印节点
    printf("Destroy link list!\n");
    destroy();  // 销毁链表
    return (0);
}
