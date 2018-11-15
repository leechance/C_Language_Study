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
#include <string.h>

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
void just_printArray(int*arr,int n){
    for (int i=0; i<n; i++) {
        printf("%4d",arr[i]);
        
        //输出完毕换行
        if (i==n-1) {
            printf("\n");
        }
        
    }
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
    
    //😡😡😡😡😡😡😡😡😇 第1趟（每一趟排好一个）
    //😡😡😡😡😡😡😡😇😁 第2趟
    //😡😡😡😡😡😡😇😁😁
    //😡😡😡😡😡😇😁😁😁
    //😡😡😡😡😇😁😁😁😁
    //😡😡😡😇😁😁😁😁😁
    //😡😡😇😁😁😁😁😁😁
    //😡😇😁😁😁😁😁😁😁
    //😇😁😁😁😁😁😁😁😁

    
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
//找到最小的，交换，排号
//😁😡😡😡😡😡😇😡😡 第1趟（每一趟排好一个）
//😁😁😡😡😡😡😡😇😡 第2趟
//😁😁😁😡😡😡😡😡😇
//😁😁😁😁😡😡😡😇😡
//😁😁😁😁😁😡😡😡😇
//😁😁😁😁😁😁😡😇😡
//😁😁😁😁😁😁😁😡😇
//😁😁😁😁😁😁😁😁😇
//😁😁😁😁😁😁😁😁😁

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

//插入排序其实就是整体移动插入排序的过程
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
 * 快速排序
 快速排序(Quick Sort)使用分治法策略。
 它的基本思想是：选择一个基准数，通过一趟排序将要排序的数据分割成独立的两部分；其中一部分的所有数据都比另外一部分的所有数据都要小。然后，再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
 
 快速排序流程：
 (1) 从数列中挑出一个基准值。
 (2) 将所有比基准值小的摆放在基准前面，所有比基准值大的摆在基准的后面(相同的数可以到任一边)；在这个分区退出之后，该基准就处于数列的中间位置。
 (3) 递归地把"基准值前面的子数列"和"基准值后面的子数列"进行排序。
 
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     l -- 数组的左边界(例如，从起始位置开始排序，则l=0)
 *     r -- 数组的右边界(例如，排序截至到数组末尾，则r=a.length-1)
 */
void quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int i,j,x;
        
        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while(i < j && a[j] > x)
                j--; // 从右向左找第一个小于x的数
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < x)
                i++; // 从左向右找第一个大于x的数
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quick_sort(a, l, i-1); /* 递归调用 */
        quick_sort(a, i+1, r); /* 递归调用 */
    }
}

void bucketSort(int a[], int n, int max)
{
    just_printArray(a, n);

    int i,j;
    int buckets[max];
    
    // 将buckets中的所有数据都初始化为0。
    memset(buckets, 0, max*sizeof(int));
    
    // 1. 计数
    for(i = 0; i < n; i++){
         buckets[a[i]]++;
        
    }
    printf("桶里的数据：\n");
    just_printArray(buckets, max);
    
    
    // 2. 排序
    for (i = 0, j = 0; i < max; i++)
    {
        while( (buckets[i]--) >0 ) //等同于if(buckets[i]==1) 但是释放了桶空间
            a[j++] = i;
    }
    
    just_printArray(a, n);
}


/*
 * 获取数组a中最大值
 *
 * 参数说明：
 *     a -- 数组
 *     n -- 数组长度
 */
int get_max(int a[], int n)
{
    int i, max;
    
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

/*
 * 对数组按照"某个位数"进行排序(桶排序)
 *
 * 参数说明：
 *     a -- 数组
 *     n -- 数组长度
 *     exp -- 指数。对数组a按照该指数进行排序。
 *
 * 例如，对于数组a={50, 3, 542, 745, 2014, 154, 63, 616}；
 *    (01) 当exp=1表示按照"个位"对数组a进行排序
 *    (02) 当exp=10表示按照"十位"对数组a进行排序
 *    (03) 当exp=100表示按照"百位"对数组a进行排序
 *    ...
 */
void count_sort(int a[], int n, int exp)
{
    int output[n];             // 存储"被排序数据"的临时数组
    int i, buckets[10] = {0};
    
    // 将数据出现的次数存储在buckets[]中
    for (i = 0; i < n; i++)
        buckets[ (a[i]/exp)%10 ]++;
    
    // 更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置。
    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];
    
    // 将数据存储到临时数组output[]中
    for (i = n - 1; i >= 0; i--)
    {
        //接着是根据桶数组buckets[]来进行排序。假设将排序后的数组存在output[]中；找出output[]和buckets[]之间的联系就可以对数据进行排序了。
        //http://www.cnblogs.com/skywang12345/p/3603669.html
        
        //{53, 3, 542, 748, 14, 214, 154, 63, 616}
        // buckets 0 1 2 3 4 5 6 7 8 9
        //         0 0 1 4 7 7 8 8 9 9
        //exp=1 a[8]=616 (a[i]/exp)%10=6 buckets[6]-1=7 out7=616
        
        // buckets 0 1 2 3 4 5 6 7 8 9
        //         0 0 1 4 7 7 7 8 9 9
        // a[7]=63      out3=63
        
        // buckets 0 1 2 3 4 5 6 7 8 9
        //         0 0 1 3 7 7 7 8 9 9
        // a[6]=154      out6=154
        
        // buckets 0 1 2 3 4 5 6 7 8 9
        //         0 0 1 3 6 7 7 8 9 9
        // a[5]=214      out5=154
        
        // buckets 0 1 2 3 4 5 6 7 8 9
        //         0 0 1 3 5 7 7 8 9 9
        //
     
        
        output[buckets[ (a[i]/exp)%10 ] - 1] = a[i];
        buckets[ (a[i]/exp)%10 ]--;
    }
    
    // 将排序好的数据赋值给a[]
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

/*
 * 基数排序
 *
 * 参数说明：
 *     a -- 数组
 *     n -- 数组长度
 */
void radix_sort(int a[], int n)
{
    int exp;    // 指数。当对数组按各位进行排序时，exp=1；按十位进行排序时，exp=10；...
    int max = get_max(a, n);    // 数组a中的最大值
    // 1322,456,985,39,57,91,10,65,48
    // 从个位开始，对数组a按"指数"进行排序
    for (exp = 1; max/exp > 0; exp *= 10)
        count_sort(a, n, exp);
}
