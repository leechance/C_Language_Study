//
//  PointerTest.h
//  指针练习
//
//  Created by chance on 2018/11/6.
//  Copyright © 2018 chance. All rights reserved.
//

/*

 1.指针变量:就是保存内存地址的变量空间;
 2.变量占内存大小：64位系统指针变量,在内存占用8个字节;
 3.分析指针指向数据类型int a[6];int(*(&a))[6] int(*)6;
 4.指针注意事项
    1）*和&是互逆的
    2）NULL 空指针 ((void*)0); 地址为0x0
    3）(void*) 泛型指针;什么样的类型都可以 void *p p++只能跳过一个字节;
    4）没有赋初值的指针是野指针;指针必须赋初值;int *p;*p=40;是有可能造成系统崩溃;是很危险的！
       定义指针变量一定要赋初值,int *p=NULL初始化;
 */

#ifndef PointerTest_h
#define PointerTest_h

#include <stdio.h>
void pointerBasicTest(void);
#endif /* PointerTest_h */
