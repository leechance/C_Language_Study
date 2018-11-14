//
//  LinearList.h
//  LinearList
//
//  Created by H on 2017/7/26.
//  Copyright © 2017年 H. All rights reserved.
/*
 创建线性表
 1）线性表的数据存储 采用指针的形式
 优点：灵活
 注意：指针空间释放问题
 2）线性表元素的数据类型 用 typedef定义
 3）线性表的初始化，就是对线性表结构体申请空间，指针的初始化，容量的给定
 4）对线性表实质就是指针的操作
 5）线性表定义的capacity 容量是一个限制条件
 */

#ifndef LinearList_h
#define LinearList_h

#include <stdio.h>

typedef int LinearListNodeValue;

//线性表
typedef struct {
    int capacity;//容量
    int length;//长度
    LinearListNodeValue * value;//节点数据的指针
}LinearList;


/** 定义一个函数创建线性表!! */
LinearList * listCreat(int capacity);
/** 销毁线性表 */
void listReleas(LinearList * list);
/** 清空线性表 */
void listClear(LinearList * list);
/** 获取线性表的长度 */
int listLength(LinearList * list);
/** 获取index对应的数据 */
LinearListNodeValue listGet(LinearList * list,int index);
/** 插入数据 */
void listInsert(LinearList * list,int index,LinearListNodeValue value);
/** 添加数据 */
void listAdd(LinearList * list,LinearListNodeValue value);
/** 设置元素 */
void listSet(LinearList * list,int index,LinearListNodeValue value);
/** 删除元素 */
void listRemove(LinearList * list,int index);
/** 删除某个值的所有数据 */
void listRemoveValue(LinearList * list,LinearListNodeValue value);
/** 打印当前线性表 */
void listPrint(LinearList * list);


#endif /* LinearList_h */
