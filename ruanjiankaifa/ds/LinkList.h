//
//  LinkList.h
//  C数据结构
//
//  Created by chance on 2017/9/10.
//  Copyright © 2017年  All rights reserved.
//

//链表的实现

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
typedef int DataType ;

typedef struct Node {
    DataType data;//数据域
    struct Node * next;//指针域
}Node,*LinkList;


//带头结点的初始化
LinkList InitLinkList();
//求表长(利用头结点的偏移来计算,)
int LengthLinkList(LinkList head);
//根据索引读表的元素(i==3 就代表第三个元素)
Node * GetLinkList(LinkList head,int i);
//给定元素,找位置
int LocationByData(LinkList head,DataType data);
//指定位置插入数据 x
void InsertLinkList(LinkList head,DataType data,int i);
//指定位置删除元素
void DeleteLinkList(LinkList head,int i);

//表的遍历
void printLinkList(LinkList head);

//表的逆置
Node* ReverseList(Node* pHead);


//带头结点的建表方式一,将元素插到表尾(利用insertLinkList)
LinkList createLinkList1();

//带头结点的建表方式二,声明尾指针
LinkList createLinkList2();

//带头结点的建表方式三,前插法
LinkList createLinkList3();

//删除链表的重复元素,始终保持结点号最小的那个(4,7,2,5,2,4)====>(4,7,2,5)
void PurgeLinkList(LinkList head);

//假设两个按照元素值两个递增有序排列的且带头结点的单链表A,B,
//编写算法,将A,B合成一个按照元素值递减的有序排列的单链表C,
//要求利用原表(A,B)的结点存放C
void merge_AB_C(LinkList A,LinkList B,LinkList C);




#endif /* LinkList_h */
