//
//  Exam.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/5.
//  Copyright © 2018 chance. All rights reserved.
//

#include "Exam.h"
#include <time.h>
#include <stdlib.h>
//数组
int *a;
//文件
FILE* fp;

//自定义打印
void print(char*s,FILE*fp);
//初始化数组
void initArray(int a[],int n,int r);
//写入数组到文件
void writeArray(int a[],int n,int c,FILE*fp);
//排序
void Sort(int *a,int n,FILE*fp);
//查找
void Search(int *a,int n,FILE*fp);



void print(char*s,FILE*fp){
    printf("%s",s);
    fprintf(fp, "%s\t",s);
}

void initArray(int a[],int n,int r){
    long now;
    srand(time(&now));
    for (int k=0; k< n; k++) {
        a[k]= rand() % r ;
    }
}
//写入数组到文件
void writeArray(int a[],int n,int c,FILE*fp){
    for (int k=0; k<n; k++) {
        if (k && k%c == 0){
            printf("\n\t");
            print("\n",fp);
        }
        
        printf("%6d", a[k]);
        fprintf(fp, "%6d",a[k]);
    }
    print("\n",fp);
}
//排序
void Sort(int *a,int n,FILE*fp){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            
            if(a[j-1]>a[j]){
                int temp=0;
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
        printf("i==%d",i);
        fprintf(fp, "i==%d",i);
        writeArray(a, n, 10,fp);
        
    }
}
void Search(int *a,int n,FILE*fp){
    for (int i=0; i<n; i++) {
        if (a[i]%3==0) {
            printf("%6d",a[i]);
            fprintf(fp,"%6d",a[i]);
        }
    }
}

#pragma mark 软件开发工具考试
void examTest(void){
    
    fflush(stdin);
    //fopen函数（https://blog.csdn.net/manonghouyiming/article/details/78606710）
    fp=fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/out.txt", "w+");
    
    int n,range;
    char ch;
    //功能1 。循环等待用户输入
    while (1) {
        printf("请输入元素个数n以及范围:\t");
        fflush(stdout);
        scanf("%d%d",&n,&range);
        if (n>0&&n<1001) {
            break;
        }
    }
    
    
    
    //功能2.初始化数组
    a=(int*)malloc(n*sizeof(int));
    initArray(a, n, range);
    
    print( "原数组：",fp);
    writeArray(a, n, 10,fp);
    
    
    //功能3 循环等待 用户输入字符 ch
    
    while (1){
        printf("请选择\n\t\t排序s    \t查询f \t");
        fflush(stdout);
        scanf("%c", &ch);
        if (ch=='f' || ch=='s')
            break;
    }
    
    if (ch=='s') {
        //排序
        print("排序后的序列:\n",fp);
        Sort(a, n,fp);
        
    }else{
        //查询
        print("能被三整除的是：",fp);
        Search(a, n,fp);
        
    }
}

