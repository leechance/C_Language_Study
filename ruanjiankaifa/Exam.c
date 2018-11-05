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

