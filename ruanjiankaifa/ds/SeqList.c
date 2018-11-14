//
//  SeqList.c
//  C数据结构
//  Created by chance on 2017/9/10.
//

#include "SeqList.h"
#include <stdlib.h>

//初始化顺序表
SeqList* InitialList(){
    SeqList*L;
    
    L =(SeqList*)malloc(sizeof(SeqList));
    L->length=0;

    return L ;
}
//求表长度
int getLength(SeqList *L){
    return L->length;
}
//读取表的元素
DataType GetList(SeqList *L,int i){
    return L->data[i];
}
//表的定位
int Location(SeqList *L, DataType x){
    int location = -1;
    for (int i=0; i<L->length; i++) {
        if(x==L->data[i]){
            location =i;
        }
    }
    if(location==-1){
        printf("未找到 \n");
    }
    return location;
}
//表的插入
void InsertList(SeqList *L ,DataType x,int index){

    if(index<0||index>L->length){
        printf("插入位置不正确 \n");
        return;
    }
    
    for (int i=L->length; i>index; i--) {
        L->data[i]=L->data[i-1];
    }
    L->data[index]=x;
    L->length ++ ;
    
}
//表的删除
void DeleteList(SeqList *L,DataType x){
    int locatin=Location(L, x);
    if(locatin==-1){
        return;
    }
    for(int i=locatin+1;i<L->length;i++){
        L->data[i-1]=L->data[i];
    }
    L->length--;
}
//表的遍历
void printL(SeqList *L){
    for (int i=0; i<L->length; i++) {
        printf(" %d",L->data[i]);
    }
    printf("\n");
}
