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


//编写函数将一个n*n矩阵转置，例如：（****）
//1 2 3 4     1 5 3 4
//5 6 7 8 ->  2 6 2 7
//3 2 5 9     3 7 5 2
//4 7 2 3     4 8 9 3
void JuzhenReverse(void);


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


#pragma mark 排序
//https://blog.csdn.net/l_215851356/article/details/77659462



/**
 随机生成数组

 @param n 数组的个数
 @param range 数组元素数值的范围
 @return 数组
 */
int * initArrayWithRandFunc(int n,int range);

//打印
void just_printArray(int*arr,int n);
//打印到文件
void printArrayToFile(int*arr,int n);
//冒泡排序
void maopaoSort(int*arr,int n);
//选择排序
void selectSort(int*a,int n);
/*
 * 快速排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     l -- 数组的左边界(例如，从起始位置开始排序，则l=0)
 *     r -- 数组的右边界(例如，排序截至到数组末尾，则r=a.length-1)
 */
void quick_sort(int a[], int l, int r);

//插入排序
void insertSort(int a[], int len);

/*
 * 桶排序
 *
 * 参数说明：
 *     a -- 待排序数组
 *     n -- 数组a的长度
 *     max -- 数组a中最大值的范围
 */
void bucketSort(int a[], int n, int max);


/*
 * 基数排序
 *
 * 参数说明：
 *     a -- 数组
 *     n -- 数组长度
 */
void radix_sort(int a[], int n);


#endif/* ArrayTest_h */


