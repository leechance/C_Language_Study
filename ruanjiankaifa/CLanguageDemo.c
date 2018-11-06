//
//  CLanguageDemo.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/5.
//  Copyright © 2018 chance. All rights reserved.
//

#include "CLanguageDemo.h"

void Faibonaqi(void){
    int n;
    int a=1,b=1;
    printf("输入n的值：");
    scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        printf("%d/%d ",a+b,a);
        int temp;
        temp = a;
        a=a+b;
        b=temp;
    }
    putchar('\n');
}

void jiecheng(void){
    int Sn=0;
    int n;
    int temp=1;
    printf("输入n的值：");
    scanf("%d",&n);
    printf("Sn = ");

    for (int i=1; i<=n; i++)
    {
        temp=i*temp;
        Sn+=temp;
        i==n? printf("%d! = %d\n",i,Sn):
        printf("%d!+",i);
    }
    
}


//借助临时变量交换值
void changeValueWithTempParam(void){

    int a=3;
    int b=5;
    int temp = a;
    a=b;
    b=temp;
    printf("a=%d b=%d\n",a, b);

}

//不借助第三个变量交换两个变量的值
void changeValueWithNoHelpTempParam(void){

        int a=3, b=5;
        a=a+b;//a=8;
        b=a-b;//b=3;
        a=a-b;//a=5;
    printf("a=%d b=%d\n",a, b);
}

void a1PlusA2toA3(void){
    
    printf("输入n的值：\n");
    int n=0;
    scanf("%d",&n);
    
    int a=1,b=0;
    for (int i=0; i<n; i++) {
        printf("%d ", a+b);
        int temp;
        temp = a;
        a=a+b;
        b=temp;
    }
    putchar('\n');

}

void JinZiTa(void){
    char ch;
    printf("输入字符：\n");
    scanf("%c", &ch);
    
    for (int i=0; i < ch-'A'+1; i++) {
        for (int j = ch-'A'-i; j>0; j--) {
            printf(" ");
        }
        for (int j=0; j<=i; j++) {
            printf("%c",'A'+j);
        }
        for (int j=i; j>0; j--) {
            printf("%c",'A'+j-1);
        }
        printf("\n");
    }
}

void JinZiTa2(void){
    char ch;
    printf("输入字符：\n");

    scanf("%c", &ch);
    
    for (int i=0; i<ch-'A'+1; i++)
    {
        for (int j=0; j<ch-'A'-i; j++)
        {
            printf(" ");
        }
        for (int j=i; j>=0; j--) {
            printf("%c",ch-j);
        }
        for (int j=0; j<i; j++) {
            printf("%c",ch-1-j);
        }
        printf("\n");
    }
}
void JinZiTa3(void){
    char ch;
    printf("输入字符：\n");

    scanf("%c",&ch);
    
    for (int i=0; i<ch-'A'+1; i++) {
        for (int j=i; j>0; j--) {
            printf(" ");
        }
        for (int j=i; j<ch-'A'+1; j++) {
            printf("%c", ch-j);
        }
        for (int j=0; j<i; j++) {
            printf("%c",'A'+1+j);
        }
        printf("\n");
    }
}

void JinZiTa4(void){
    char ch;
    printf("输入字符：\n");
    scanf("%c",&ch);
    for (int i=0; i<ch-'A'+1; i++) {
        for (int j=0; j<=i; j++) {
            printf("%c", 'A'+j);
        }
        for (int j=i; j>0; j--) {
            printf("%c",'A'+j-1);
        }
        printf("\n");
    }
}
