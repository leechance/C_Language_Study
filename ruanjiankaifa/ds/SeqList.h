//
//  SeqList.h
//  C数据结构
//  顺序表
//  Created by chance on 2017/9/10.
//  Copyright © 2017年  All rights reserved.



/*
  创建线性表
  1）线性表的数据存储采用数组的形式，数组的长度，在表定义的中指定为100
     缺点：长度固定，不灵活
     优点：编程不用考虑数组空间的释放问题
  2）线性表元素的数据类型 用 typedef定义
  3）线性表的初始化，就是对线性表结构体申请空间
  4）对线性表实质就是操作数组
 */

#ifndef SeqList_h
#define SeqList_h

typedef int DataType;

//顺序表元素的形式
typedef struct {
    DataType data[100];
    int length;
}SeqList ;

#include <stdio.h>
//初始化顺序表
SeqList* InitialList();
//求表长度
int getLength(SeqList *L);
//读取表的元素
DataType GetList(SeqList *L,int i);
//表的定位
int Location(SeqList *L, DataType x);
//表的插入
void InsertList(SeqList *L ,DataType x,int index);
//表的删除
void DeleteList(SeqList *L,DataType x) ;
//表的遍历
void printL(SeqList *L);

#endif /* SeqList_h */
