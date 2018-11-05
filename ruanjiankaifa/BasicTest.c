//
//  BasicTest.c
//  ruanjiankaifa
// fflush在 scanf之前执行 fflush(stdout) 在打开文件之前执行 fflush(stdin)
//

#include "BasicTest.h"
//输出函数printf
void printfTest(){
    //1.换行符号
    printf("hello c\n");
    //2.格式化符号%d
    int c=10;
    printf("hello c=%d\n",c);
    //3.空格
    char space=32;
    printf("hello%cc\n",space);
    //4.制表符号
    printf("hello\tc\tc\n");
    //5.占位符号
    printf("hello c=%4d,c=%4d,c=%4d\n",c,c,c);
}

void scanfTest(){
    
    //嵌入代码的方式1，输完就结束，不进行校验
    /*
     int n,range;
     printf("请输入元素个数n 以及范围range:\t\n");
     fflush(stdout);
     scanf("%d%d",&n,&range);
     */
    
    //嵌入代码的方式2，循环等待用户输入，满足条件退出循环😀
    
    int n,range;
    while (1) {
        printf("请输入元素个数n 以及范围range:\t\n");
        fflush(stdout);
        scanf("%d%d",&n,&range);
        if (n>0&&n<1001) {
            break;
        }
    }
}

void fprintfTest(FILE*fp){
    printf("输入到文件测试 \n");
    fprintf(fp, "输入到文件:\n");
    
    //for循环输出变量到文件
    for (int i=0; i<10; i++) {
        fprintf(fp, "i=%d\n",i);
    }
}
