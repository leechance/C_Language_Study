//
//  search.h
//  ruanjiankaifa
//
//  Created by chance on 2018/11/13.
//  Copyright © 2018 chance. All rights reserved.
/*
 
  查找算法
    1.数组的顺序查找
    2.数组的二分查找
 */

#ifndef search_h
#define search_h

#include <stdio.h>
#include <stdbool.h>



/**
 数组顺序查找

 @param a 数组
 @param len 长度
 @param num 查找的数字
 @return 结果
 */
bool arr_sequence_search(int a[],int len,int num );

/**
 二分查找

 @param a 数组
 @param n 长度
 @param low 低范围
 @param high 高范围
 @param target 目标
 @return 结果
 */
bool arr_middleSlice_search(int a[], int n,int low, int high, int target);






#endif
