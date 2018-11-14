//
//  LinearList.c
//  LinearList
//
//  Created by H on 2017/7/26.
//  Copyright © 2017年 H. All rights reserved.
//

#include "LinearList.h"
#include <stdlib.h>


//定义一个函数创建线性表!!
LinearList * listCreat(int capacity){
    if (capacity < 0) {
        return NULL;
    }
    //分配线性表结构体的内存空间!!
    LinearList * list = malloc(sizeof(LinearList));
    if (list) {
        list->length = 0;
        list->capacity = capacity;
        list->value = malloc(capacity * sizeof(LinearListNodeValue));

    }
    return list;
}
/** 销毁线性表 */
void listReleas(LinearList * list){
    if (list == NULL) {
        return;
    }
    free(list->value);
    free(list);
}


/** 清空线性表 */
void listClear(LinearList * list){
    if (list == NULL) {
        return;
    }
    list->length = 0;
}

int listLength(LinearList * list){
    if (list == NULL) {
        return 0;
    }
    return list->length;
}
/** 获取index对应的数据 */
LinearListNodeValue listGet(LinearList * list,int index){
    if (list==NULL || index >= list->length || index < 0) {
        return 0;
    }
    return list->value[index];
}

/** 插入数据 */
void listInsert(LinearList * list,int index,LinearListNodeValue value){
    if (list == NULL||index < 0 || index > list->length || list->length == list->capacity) {
        return;
    }
    //从index开始后面所有的数据挪动
    for (int i = list->length - 1; i >= index; i--) {
        list->value[i+1] = list->value[i];
    }
    //设置新值到index位置
    list->value[index] = value;
    //数量增加
    list->length++;
}


/** 添加数据 */
void listAdd(LinearList * list,LinearListNodeValue value){
    if (list == NULL) {
        return;
    }
    listInsert(list,list->length, value);
}

/** 设置元素 */
void listSet(LinearList * list,int index,LinearListNodeValue value){
    if (list == NULL || index < 0 || index >= list->length) {
        return;
    }
    list->value[index] = value;
}

/** 删除元素 */
void listRemove(LinearList * list,int index){
    if (list == NULL || index < 0 || index >= list->length ) {
        return;
    }
    for (int i = index + 1; i < list->length; i++) {
        list->value[i - 1] = list->value[i];
    }
    //数量减少
    list->length--;
}

/** 删除某个值的所有数据 */
/**  效率低一点!代码简单点!
 for (int i = 0; i < list->length; i++) {
 while (list->value[i] == value && i < list->length) {
 //干掉当前数据
 listRemove(list, i);
 }
 
 }
 */

void listRemoveValue(LinearList * list,LinearListNodeValue value){
    if (list == NULL) {
        return;
    }
    //定义一个初始记录
    int removeCount = 0;
    //遍历所有的元素
    for (int i = 0; i < list->length; i++) {
        if (list->value[i]==value) {
            //让记录加1
            removeCount++;
        }else{//不删除
            list->value[i - removeCount] = list->value[i];
        }
    }
    
    //最后将长度减去删除的个数
    list->length -= removeCount;
}
/** 打印当前线性表 */

void listPrint(LinearList * list){
    if (list == NULL) {
        return;
    }
    printf("list{\n");
    printf("\tlength = %d;\n",list->length);
    printf("\tcapacity = %d;\n",list->capacity);
    printf("\tvalue = [");
    for (int i = 0; i < list->length; i++) {
        printf("%d",list->value[i]);
        if (i < list->length -1) {
            printf(",");
        }
    }
    printf("];\n\t}\n\n");
}



