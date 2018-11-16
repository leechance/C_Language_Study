//
//  SqStack.h
//  ruanjiankaifa
//
//  Created by chance on 2018/11/16.
//  Copyright © 2018 chance. All rights reserved.
//

#ifndef SqStack_h
#define SqStack_h

#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct
{
    SElemType data[MAXSIZE];
    int top; /* 用于栈顶指针 */
}SqStack;

Status visit(SElemType c);

/*  构造一个空栈S */
Status InitStack(SqStack *S);
/* 把S置为空栈 */
Status ClearStack(SqStack *S);
/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S);
/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S);
/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S,SElemType *e);
/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *S,SElemType e);
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack *S,SElemType *e);
/* 从栈底到栈顶依次对栈中每个元素显示 */
Status StackTraverse(SqStack S);


#endif /* SqStack_h */
