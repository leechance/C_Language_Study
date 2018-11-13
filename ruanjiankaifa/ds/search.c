//
//  search.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/13.
//  Copyright © 2018 chance. All rights reserved.
//

#include "search.h"
//遍历数组，找到返回，如果遍历结束，还没有就没有找到
bool arr_sequence_search(int a[],int len,int num ){
    bool result = false;
    
    for (int i=0; i<len; i++) {
        if (a[i]==num) {
            result=true;
            break;
        }
        if (i==len-1&&a[i]!=num) {
            result =false;
        }
    }
    result?printf("找到了\n"):printf("没有\n");
    return result;
}

// 每一次循环（while）,都取中间元素
// 判断中间元素，如果>taget,低坐标等于middle+1;如果<taget,高坐标等于middle-1
// 判断条件 low<=high
bool arr_middleSlice_search(int a[], int n,int low, int high, int target){
     bool result=false;
    
        while (low <= high)
        {
            int middle = (low + high) / 2;
            if (target == a[middle])
            {
                printf("索引是%d\n",middle);
                result=true;
                 break;
                
            }
            else if (target > a[middle])
            {
                low = middle + 1;
            }
            else if (target < a[middle])
            {
                high = middle - 1;
            }
        
        
    }
     result?printf("找到了\n"):printf("没有\n");
     return result;
}
