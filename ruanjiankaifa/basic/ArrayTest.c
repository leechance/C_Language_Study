//
//  ArrayTest.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/8.
//  Copyright © 2018 chance. All rights reserved.
//

#include "ArrayTest.h"
#include <time.h>
#include <stdlib.h>

FILE*pFile;


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

    }
    for (int i=0; i<10; i++) {
        printf("%*d", 24-2*i, a[i][0]);
        for (int j=1; j<=i; j++) {
            printf("%4d", a[i][j]);
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

void reverse(int *a[],int n)
{
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int temp = a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
}

void JuzhenReverse(void){
    int a[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int *p[3];
    for (int i=0; i<3; i++) {
        p[i]=a[i];
    }
    reverse(p, 3);
    
    /*for (int i=0; i<3; i++) {
     for (int j=i; j<3; j++) {
     if (i!=j)
     {
     int temp = a[i][j];
     a[i][j]=a[j][i];
     a[j][i]=temp;
     }
     }
     }*/
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



int * initArrayWithRandFunc(int n,int range){
    
    pFile=fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/output/out2.txt", "w+");
    
    int * arr= (int*)malloc(n*sizeof(int));
     time_t now;
    srand(time(&now));
    for (int i=0; i<n; i++) {
        arr[i]= rand()%range;
    }
    return arr;
    
}
void printArrayToFile(int*arr,int n){
    
    for (int i=0; i<n; i++) {
        printf("%4d",arr[i]);
        fprintf(pFile,"%4d",arr[i] );
        
        //输出完毕换行
        if (i==n-1) {
            printf("\n");
            fprintf(pFile,"\n" );
        }
        
    }
}

void maopaoSort(int*arr,int n){
    printf("原数组： ");
    fprintf(pFile, "原数组： ");
    printArrayToFile(arr, n);
    
    //1）只有一个元素是不用排序的
    //2) 依次比较的个数是  n-1,n-2,n-3......1
    //   理论上需要比较的次数 （1+ n-1）*(n-1)/2=n(n-1)/2
    //   需要交换的次数理论上 n(n-1)/2，但是部分有序的情况下，不需要交换那么多
    for (int i=0; i<n-1; i++) {
        
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        fprintf(pFile, "第%d遍：",i+1);
        printArrayToFile(arr, n);
    }
    
    
}

//明显减少交换的次数
void selectSort(int *a,int n){
    printf("原数组： ");
    fprintf(pFile, "原数组： ");
    printArrayToFile(a, n);

        for (int i=0; i<n-1; i++)
        {
            int k=i;//保存最小值下标
            for (int j=i+1; j<n; j++)//求最小值下标
            {
                if (a[k]>a[j])
                {
                    k=j;
                }
            }
            if (k!=i)
            {
                int temp=a[i];
                a[i]=a[k];
                a[k]=temp;
            }
            
            fprintf(pFile, "第%d遍：",i+1);
            printArrayToFile(a, n);
        }
    
}
void insertSort(int a[], int len)
{
    printf("原数组： ");
    fprintf(pFile, "原数组： ");
    printArrayToFile(a, len);
    for (int i=0; i<len -1; i++) {
        int temp = a[i+1];
        //        int j=i;
        //        while (j>=0 && a[j]>temp) {
        //            a[j+1]=a[j];
        //            j--;
        //        }
        int j=i;
        for (; j>=0 && a[j]>temp; j--) {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
        
        
        fprintf(pFile, "第%d遍：",i+1);
        printArrayToFile(a, len);
    }
}

