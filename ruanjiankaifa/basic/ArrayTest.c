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

/*
 
 
 //用辗转相除法求最大公约数
 //
 // 15 5
 //
 //a    b
 //319 377    --- 319
 //a    b
 //377 319    --- 58
 //a    b
 //319  58    --- 29
 //a    b
 //58   29    --- 0
 //a    b
 //29   0
 
 // 300 480   300
 // 480 300   180
 // 300 180   120
 // 180 120   60
 // 120 60    0
 // 60  0
 
 #if 0
 int main(int argc, const char *argv[])
 {
 int a, b;
 scanf("%d%d",&a,&b);
 while (b!=0) {
 int temp;
 temp = a%b;
 a=b;
 b=temp;
 }
 printf("最大公约数%d\n",a);
 
 return 0;
 }
 #endif
 
 
 //倒序输出两个大写字母之间的字母序列。注意输入使用scanf输入
 //比如：
 //输入 U Y
 //输出为
 //Y
 //X
 //W
 //V
 //U
 //输入 V X 输出为
 //X
 //W
 //V
 #if 0
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc,const char *argv[])
 {
 char ch1,ch2;
 scanf("%c %c",&ch1,&ch2);
 for (int i=0; i< abs(ch1-ch2)+1; i++) {
 if (ch1>ch2) {
 printf("%c ",ch1-i);
 }
 else
 {
 printf("%c ",ch2-i);
 }
 }
 printf("\n");
 
 return 0;
 }
 #endif
 
 //将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
 //10 = 2*5
 //
 // 10  2  --- 0
 // 5   2  ----
 // 5   3  ----
 // 5   4  ---
 // 5   5  == 0
 
 //90  2  ---- 0
 //45  2  ----
 //45  3  ---- 0
 //15  3  ---  0
 //5   3  ---
 //5   4  ---
 //5   5  ---  0
 //1
 #if 0
 int main(int argc, const char *argv[])
 {
 int n;
 scanf("%d",&n);
 
 printf("%d=",n);
 for (int i=2; n!=1; i++)
 {
 
 if (n%i==0)
 {
 n==i?printf("%d",i):printf("%d*",i);
 n/=i;
 i--;
 }
 }
 printf("\n");
 return 0;
 }
 
 #endif
 
 //21.给定一个 5 位的整数,将该数按照 10 进制位逆置,例如给定 12345 变成 //54321,12320 无法求负数
 //变成 2321。
 #if 0
 int main(int argc,const char *argv[])
 {
 int num;
 scanf("%d",&num);
 if (num<10000 || num >99999)
 {
 return -1;
 }
 while (num%10==0)
 {
 num/=10;
 }
 while (num)
 {
 int temp = num%10;
 printf("%d",temp);
 num/=10;
 }
 printf("\n");
 return 0;
 }
 #endif
 
 //输入一个自然数n, 统计 n! 末尾有多少个0?
 //5!  1   120    5*4*3*2*1
 //10! 2         2*5*9*8*7*6*5*4*3*2*1
 //15! 5 10 15  3
 //25! 5 10 15 20 25   6
 #if 0       //方法一
 int main(int argc,const char *argv[])
 {
 int n;
 int count=0;
 scanf("%d", &n );
 for (int i=n/5; i>0; )
 {
 
 count+=i;
 i/=5;
 }
 printf("%d\n", count);
 
 return 0;
 }
 #endif
 //方法二
 //int main(int argc,const char*argv[])
 //{
 //    int i, n;
 //    scanf("%d",&n);
 //
 //    int count=0;
 //    for (i=1; i<=n; i++) {
 //        if(i%5==0)
 //        {int k;
 //            k=i/5;
 //            count++;
 //            while (k%5==0)
 //            {
 //                count++;k/=5;
 //            }
 //
 //        }
 //    }
 //
 //    printf("%d",count);
 //}
 
 
 
 //十进制转二进制
 //int main(int argc, const char * argv[])
 //{
 //    int bin[32]={};
 //    int a;
 //    scanf("%d", &a);
 //    int i=0;
 //    while (a) {
 //        bin[i]=a%2;
 //        a=a/2;
 //        i++;
 //    }
 //    for (i=i-1; i>=0; i--) {
 //        printf("%d",bin[i]);
 //    }
 //    printf("\n");
 //    return 0;
 //}
 
 
 //十进制转八进制
 
 
 //int main(int argc, const char * argv[])
 //{
 //    int bin[32]={};
 //    int a;
 //    scanf("%d", &a);
 //    int i=0;
 //    while (a) {
 //        bin[i]=a%8;
 //        a=a/8;
 //        i++;
 //    }
 //    printf("0");
 //    for (i=i-1; i>=0; i--) {
 //        printf("%d",bin[i]);
 //    }
 //    printf("\n");
 //    return 0;
 //}
 
 
 
 
 
 
 
 
 
 //递归: 函数直接或者间接的调用本身,那么这个函数是递归的
 //n!  = n*(n-1)!
 //(n-1)! = (n-1)(n-2)!
 //
 //1! = 1
 
 //求n!
 //5 = 5*4! 120
 //4!= 4*3! 24
 //3!= 3*2! 6
 //2!= 2*1! 2
 //1!= 1
 
 //factrial(2)=2*factrial(1)
 //factrial(3)=3*factrial(2)=3*2*factrial(1)
 
 //int factrial(int n)
 //{
 //    if (n==1)
 //    {
 //        return 1;
 //    }
 //    return n*factrial(n-1);
 //}
 //
 //int main(int argc, const char *argv[])
 //{
 //
 //    printf("%d\n",factrial(5));
 //
 //    return 0;
 //}
 
 
 
 
 
 
 //2、编写递归函数求两个正整数a和b的最大公约数（GCD，Greatest Common Divisor），使用Euclid算法：
 //
 //如果a除以b能整除，则最大公约数是b。
 //
 //否则，最大公约数等于b和a%b的最大公约数。
 //
 //Euclid算法是很容易证明的，请读者自己证明一下为什么这么算就能算出最大公约数。最后，修改你的程序使之适用于所有整数，而不仅仅是正整数。
 
 //3、趣味问题——年龄。有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。问第三个人，又说比第2人大两岁。问第2个人，说比第一个人大两岁。最后问第一个人，他说是10岁。请问第五个人多大？用递归算法实现。
 //int euclid(int a,int b)
 //{
 //    if(a%b==0)
 //    {
 //        return b;
 //    }
 //    return euclid(b, a%b);
 //}
 //
 //int main(int argc,const char *argv[])
 //{
 //    printf("%d\n", euclid(319, 377));
 //
 //    return 0;
 //}
 
 //int age(int n)
 //{
 //    if (n==1) {
 //        return 10;
 //    }
 //    return 2+age(n-1);
 //}
 //
 //int main(int argc, const char *argv[])
 //{
 //    printf("%d ", age(5));
 //    return 0;
 //}
 //#

 */
