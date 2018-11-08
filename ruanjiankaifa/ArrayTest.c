//
//  ArrayTest.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/8.
//  Copyright © 2018 chance. All rights reserved.
//

#include "ArrayTest.h"

void initXYArray(void){
    
    int a[3][2]={};
    for (int i=0; i<3;i++)
    {
        for (int j=0; j<2; j++)
        {
            scanf("%d ",&a[i][j]);
            printf("%d ",a[i][j]);
        }
    }
    
}


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
void YangHuiSanjiao(void){
    printf("杨辉三角：\n");
    int a[10][10]={};
    for (int i=0; i<10; i++)
        
    {
        for (int j=0; j<=i; j++)
        {
            a[i][0]=1;
            if (j==i||j==0)
            {
                a[i][j]=1;
            }
            else{
                a[i][j]=a[i-1][j]+a[i-1][j-1];
                
            }
            printf("%4d",a[i][j]);
        }
        printf("\n");
        
    }
}


/*
 *等腰三角杨辉三角

 */
void DengYaoYangHuiSanjiao(void){
    printf("等腰杨辉三角：\n");

    int a[10][10]={};
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<=i; j++)
        {
            a[i][0]=1;
            if (j==i||j==0)
            {
                a[i][j]=1;
            }
            else{
                a[i][j]=a[i-1][j]+a[i-1][j-1];
                
            }
            printf("%4d",a[i][j]);
        }
        printf("\n");
        
    }
    
}



/**
 定义一个字符数组c[10]，并初始化数组，将字符数组内容倒序输出。。注意输入使用scanf输入
 比如：
 输入 asdf输出为
 fdsa
 
 输入 WgwdGE 输出为
 EGdwgW
 */
void reverseString(void){
    char ch[10]={};
    
    int i ,j;
    for(i=0;i<10;i++)
    {
        scanf("%c",&ch[i]);
        if (ch[i]=='\n') {
            break;
        }
    }
    printf("%d",i);
    for(j=i-1;j>=0;j--)
    {
        printf("%c",ch[j]);
        
    }
}
