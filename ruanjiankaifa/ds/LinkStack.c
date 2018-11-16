//
//  LinkStack.c
//  ruanjiankaifa
//  链栈
//  Created by chance on 2018/11/16.
//  Copyright © 2018 chance. All rights reserved.
//

#include "LinkStack.h"

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */


/* 链栈结构 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;


typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;

Status l_visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

/*  构造一个空栈S */
Status l_InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
        return ERROR;
    S->top=NULL;
    S->count=0;
    return OK;
}

/* 把S置为空栈 */
Status l_ClearStack(LinkStack *S)
{
    LinkStackPtr p,q;
    p=S->top;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    S->count=0;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status l_StackEmpty(LinkStack S)
{
    if (S.count==0)
        return TRUE;
    else
        return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int l_StackLength(LinkStack S)
{
    return S.count;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status l_GetTop(LinkStack S,SElemType *e)
{
    if (S.top==NULL)
        return ERROR;
    else
        *e=S.top->data;
    return OK;
}

/* 插入元素e为新的栈顶元素 */
Status l_Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;    /* 把当前的栈顶元素赋值给新结点的直接后继，见图中① */
    S->top=s;         /* 将新的结点s赋值给栈顶指针，见图中② */
    S->count++;
    return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status l_Pop(LinkStack *S,SElemType *e)
{
    LinkStackPtr p;
    if(l_StackEmpty(*S))
        return ERROR;
    *e=S->top->data;
    p=S->top;                    /* 将栈顶结点赋值给p，见图中③ */
    S->top=S->top->next;    /* 使得栈顶指针下移一位，指向后一结点，见图中④ */
    free(p);                    /* 释放结点p */
    S->count--;
    return OK;
}

Status l_StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p=S.top;
    while(p)
    {
        l_visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}


void testLinkStack(void){
    int j;
    LinkStack s;
    int e;
    if(l_InitStack(&s)==OK)
        for(j=1;j<=10;j++)
            l_Push(&s,j);
    printf("栈中元素依次为：");
    l_StackTraverse(s);
    l_Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",l_StackEmpty(s));
    l_GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,l_StackLength(s));
    l_ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",l_StackEmpty(s));
}
