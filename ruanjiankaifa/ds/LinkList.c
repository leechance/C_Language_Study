//
//  LinkList.c
//  C数据结构
//  链表
//  Created by chance on 2017/9/10.
//  Copyright ©  All rights reserved.
//

#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
//带头结点的初始化
LinkList InitLinkList(){
    
    LinkList head ;
    
    head= malloc(sizeof(Node));
    head->next =NULL;
    return head ;
}

//求表长(利用头结点的偏移来计算,)
int LengthLinkList(LinkList head){
    
    Node * p =head ; //p是工作指针,初始化p指向头结点
    int cnt=0;
    
    while (p->next!=NULL) {
        p=p->next;
        cnt ++ ;
    }
    return cnt;
}

//根据索引读表的元素(i==3 就代表第三个元素)
Node * GetLinkList(LinkList head,int i){
    
    Node *p;     // p是工作指针
    p=head->next;//p指向了首节点
    int c=1;
    while (p->next!=NULL && c<i) {
        p=p->next;
        c++;
    }
    if(c==i){
        return p;
    }else {
        return NULL;
    }
}

//给定元素,找位置
int LocationByData(LinkList head,DataType data){
    Node *p;     // p是工作指针
    p=head->next;//p指向了首节点
    int loction=0;
    
    while (p->next!=NULL &&p->data!=data) {
        loction++;
        p=p->next;
    }
    if(p->next!=NULL) return loction+1;
    else return 0;

}

//指定位置插入数据 x
void InsertLinkList(LinkList head,DataType data,int i){
    Node * p,*q;
    if(i==1){
        q=head;
    }else{
        q=GetLinkList(head, i-1);
    }
    if(q==NULL)
        exit("找不到插入的位置");
    else {
        p=malloc(sizeof(Node));
        p->data=data;
        p->next=q->next;
        q->next=p;
    }
}

//指定位置删除元素
void DeleteLinkList(LinkList head,int i){
    
    Node *p,*q;
    if(i==1){
        q=head;
    }else{
        q=GetLinkList(head, i-1);
    }
    if(q!=NULL&&q->next!=NULL){
        p=q->next;
        q->next=p->next;
        free(p);
    
    }else {
        exit("找不到删除的结点");
    }
    
}

//表的遍历
void printLinkList(LinkList head){
    Node * p =head ; //p是工作指针,初始化p指向头结点
    
    while (p->next!=NULL) {
        p=p->next;
        printf("%d",p->data);
        printf("\n");
        
    }

}

////表的逆置
//Node* ReverseList(Node* pHead){
//
//    if (pHead == NULL || pHead->next == NULL)
//    {
//        return pHead;
//    }
//    
//    Node* pRev = NULL;
//    Node* pCur = pHead;
//    while(pCur != NULL)
//    {
//        Node* pTemp = pCur;   // 步骤①
//        pCur = pCur->next;       // 步骤②
//        pTemp->next = pRev;      // 步骤③
//        pRev = pTemp;
//    }
//    return pRev;
//    
//}

//链表的逆置
Node *ReverseList(Node *phead)
{
    Node *p, *q, *r;
    
    p = phead;
    q=r=NULL;
    
    while(p)
    {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    return r;
}

//带头结点的建表方式一,将元素插到表尾
LinkList createLinkList1(){
    LinkList head;
    head =InitLinkList();//创建头结点
    int x,i=1;
    
    printf("请输入");
    scanf("%d",&x);
    while (x!=0) {
        InsertLinkList(head, x, i);//插入法
        i++;
        scanf("%d",&x);
    }
    return head;
}

//带头结点的建表方式二,声明尾指针
LinkList createLinkList2(){
    LinkList head;
    Node * q,*t;
    int x;
    head =malloc(sizeof(Node));//生成头结点
   
    q=head; //为指针赋初值
    
    printf("请输入");
    scanf("%d",&x);
    
    while (x!=0) {
        t=malloc(sizeof(Node));//生成新的结点
        t->data=x;             //新节点赋值
        q->next=t;             //新节点连入
        q=t;                   //修改尾指针,指向新的尾结点
        scanf("%d",&x);

 
    }
    q->next=NULL; //q指向尾节点,置尾节点的标志是置为NULL
    return head;
    
}

//带头结点的建表方式三,前插法,新增的结点始终在头结点之后,最终链表 的输出顺序与输入顺序想法
LinkList createLinkList3(){
    
    LinkList head;
    head=InitLinkList();
    Node * p;
    int x;
    printf("请输入");
    scanf("%d",&x);
    
    while (x) {
        p=malloc(sizeof(Node));//生成新的结点
        p->data=x;             //新节点赋值
        p->next=head->next  ;   //前插,插入链表的第一个结点处
        head->next=p;           //修改头结点 ,向新的结点
        scanf("%d",&x);
        
    }
    
    
    return head;

}

//删除链表的重复元素,始终保持结点号最小的那个(4,7,2,5,2,4)====>(4,7,2,5)
void PurgeLinkList(LinkList head){
    
    Node *p,*q,*r; //p是工作指针,q是当前检查点的位置,r指向待删的结点
    q=head->next; //q指示当前检查点的位置,给q赋初值,指向链表的首节点
    
    while (q->next!=NULL) {
        p=q; //工作指针指向 q
        while (p->next!=NULL) {
            if (p->next->data==q->data) { //*(p->next)是q重复的结点
                r=p->next; //r指向待删的结点
                p->next=r->next;
                //移除结点 *(p->next),p->next指向原来*(p->next的后继结点)
                free(r) ;
            } else {
                p=p->next; //否则p指向下一个结点
            }
        }
        
        q=q->next;//更新检查点
    }
}

//假设两个按照元素值两个递增有序排列的且带头结点的单链表A,B,
//编写算法,将A,B合成一个按照元素值递减的有序排列的单链表C,
//要求利用原表(A,B)的结点存放C
void merge_AB_C(LinkList A,LinkList B,LinkList C){


}


