//
//  MemoryTest.h
//  ruanjiankaifa
//  内存管理
//  Created by chance on 2018/11/8.
//  Copyright © 2018 chance. All rights reserved.
//

/*
 内存结构划分
 1 .text(代码段) 存放二进制可执行程序
 2 .date(数据段):初始化的全局变量及静态变量 分为只读数据段 和可读可写数据段
 3  .bss 未初始化的全局变量
 4  .heap (堆区):手动申请内存,手动释放内存 ,malloc,free
 5  .stack(栈区) :定义在函数体内或者{},函数调用完毕后,内存自动释放;不需要手动释放;栈区是线性结构,可以看成大的数组;
 
 static 作用
 1.staic修饰局部变量,变量只定义一次,变量内存开辟在数据段,作用域只在当前函数内有用
 2.staic 修饰全局变量只在当前.c文件内有用(本地的全局变量);作用域是从定义开始到本地文件结束;
 3.staic 修饰的函数,只能在当前的.c文件调用
 4.static修饰的函数或者变量不要放在头文件中,否则会有报警;只能放在当前的.c文件
 5.staic 修饰函数作用域只在当前.c文件内有效;
 
 
 堆区的内存操作
 malloc
 void    *malloc(size_t);
 内存申请失败返回空指针
 对内存申请成功与否要进行判断
 初始化  memset( pint,0,40);清零
 使用完毕后要进行释放;否组申请次数过多会导致内存不够用;
 
 
 1'申请内存空间
 2.判断是否申请成功
 3.对申请的内存空间初始化
 4,使用申请的内存空间
 5,释放内存空间
 6.把保存内存空间的指针变量赋值为null;
 
 
 内存使用注意事项
 1.内存申请成功,才能使用该空间;
 2.定义一块内存空间,其初始值不一定为0;锁以内存空间申请后必须初始化
 3.内存空间不能越界访问;
 4.堆内存释放后,指向该内存的指针一定要赋空值
 5.堆内存释放后不能继续使用
 6.malloc,跟free要成对出现;不能多free,或者只有malloc,
 7.栈空间的内存的空间=不能free,free只能在堆内存空间;
 
 
 常用的内存函数
 calloc
 void    *calloc(size_t nmem, size_t memsize);
 mem 表示申请的数据长度
 memsize 每个内存空大小
 默认在使用后把指针变量初始化为0;

 realloc
 void *relloc(void* size_t)
 修改堆内存空间的大小
 单纯的用realloc也可以开辟内存;;;;;;;;;;;;
 

 
 void    *memchr(const void *, int, size_t);//复制内存
 int     memcmp(const void *, const void *, size_t);内存比较函数
 void    *memcpy(void *, const void *, size_t);size-t一定拷贝多少个字节;;;
 void    *memmove(void *, const void *, size_t);1.内存移动函数 被拷贝的地址与拷贝的地址可以重叠;,size是一定拷贝的字节数,
 void    *memset(void *, int, size_t);
 void    *memmem(const void *, size_t, const void *, size_t) __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);
 查找内存块儿,

 
 */

#ifndef MemoryTest_h
#define MemoryTest_h

#include <stdio.h>

void memoryTest(void);

#endif /* MemoryTest_h */


