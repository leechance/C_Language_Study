//
//  SeqList.h
//  C数据结构
//  顺序表
//  Created by chance on 2017/9/10.
//  Copyright © 2017年  All rights reserved.
//

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
