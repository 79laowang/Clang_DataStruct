/*------------------------------------------------------------------------------
* File Name:   linklist.c
* Purpose:     link list operations 
*
* Author:      Ke Wang
*
* Created:     2019-12-02
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include "common.h"

/* Define the NULL in /usr/include/linux/stddef.h */

Node head; //链表头

/* 插入节点 */
int insert(int val)
{
    Node p, q;
    p = head;
    if (p != NULL) { /* 寻找适当的插入位置 */
        while (p->next != NULL) {
            p = p->next;
        }
    }
    q = (Node)malloc(sizeof(struct node)); // 创建一个新的节点
    if (q == NULL)
        return -1;
    q->next = NULL;  //　新节点赋值
    q->val = val;
    if (p == NULL){  // 如果是空链表，头结点直接链接新节点
        head = q;
        return 1;
    }
    p->next = q; // 插入新节点
    return 1;
}

/* 删除节点操作 */
int del(int val, Node * res)
{
    Node p, q;
    p = head;
    if (p == NULL) // 空链表，返回
        return -1;
    if (p->val == val) { // 第一个节点就是要删除的节点
        *res = p;
        head = p->next;  // 删除这个节点
        return 1;
    } else if (p->next == NULL) { // 只有一个节点，而且是不是要删除的节点
        return 1;
    }
    q = p;  //当前节点
    p = p->next;  //后继节点
    while(p != NULL) {  //遍历链表
        if (p->val != val) {  //找到删除节点
            q = p;
            p = p->next;
        } else {  // 删除节点
            q->next = p->next;
            p->next = NULL;
            *res = p;
            return 1; // 成功删除节点，返回1
        }
    }
    return -1;
}

/* 打印链表节点的值 */
void print()
{
    Node p = head;
    while (p != NULL) {  // 遍历输出
        printf("%d\n", p->val);
        p = p->next;
    }
}

void destroy()
{
    Node p = head;  //从头开始
    while (p != NULL) {
        Node q;
        q = p;
        p = p->next;  // 释放每一个节点
        free(q);
    }
    head = NULL;  // 头节点置空
}
