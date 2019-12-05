/*------------------------------------------------------------------------------
* File Name:   common.h
* Purpose:     链表工程头文件 
*
* Author:      Ke Wang
*
* Created:     2019-12-02
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

/* 头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <linux/stddef.h>

/* 全局定义 */
typedef struct node * Node;

/* 链表节点结构 */
struct node{
    int val;
    Node next;
};

/* 全局变量定义 */
extern Node head;
/* 接口函数声明 */
extern int insert(int val);
extern int del(int val, Node * res);
extern void print();
extern void destroy();

