//
//  ArrayTest.h
//  ruanjiankaifa
//  数组测试
//  Created by chance on 2018/11/8.
//  Copyright © 2018 chance. All rights reserved.
//
/*
 1)数组:是一段连续的内存空间;
   数组的访问.对数组元素,采用数组下标的方式
 2)数组名是一个地址常量 a, &a[0],&a 地址是一样的
 3）二维数组
   int a[5][10]
   二维数组看成一位数组造成的数组,由5个一维数组组成的数组;该一位数组由10个int类型组成的一维数组
   二维数组在内存空间也是连续的.a[0][9]于a[1][0]的地址相差4
 */

#ifndef ArrayTest_h
#define ArrayTest_h

#include <stdio.h>

void initXYArray(void);

/*
 *杨辉三角
 1
 1   1
 1   2   1
 1   3   3   1
 1   4   6   4   1
 1   5  10  10   5   1
 1   6  15  20  15   6   1
 1   7  21  35  35  21   7   1
 */
void YangHuiSanjiao(void);


/*
 *等腰三角杨辉三角(未完待续)
              1
            1   1
          1   2   1
        1   3   3   1
      1   4   6   4   1
    1   5  10  10   5   1
  1   6  15  20  15   6   1
1   7  21  35  35  21   7   1
 */
void DengYaoYangHuiSanjiao(void);

/**
 定义一个字符数组c[10]，并初始化数组，将字符数组内容倒序输出。。注意输入使用scanf输入
 比如：
 输入 asdf输出为
 fdsa
 
 输入 WgwdGE 输出为
 EGdwgW
 */
void reverseString(void);


#endif/* ArrayTest_h */


