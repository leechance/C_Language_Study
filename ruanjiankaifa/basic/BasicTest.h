//
//  BasicTest.h
//基本测试 scanf,printf,sprintf(打印到文件)
//文件读取
//https://blog.csdn.net/zzwtyds/article/details/75207666

#ifndef BasicTest_h
#define BasicTest_h

#include <stdio.h>


//输出函数printf
void printfTest(void);
void scanfTest(void);
//打印到文件
void fprintfTest(FILE*fp);


//文件操作三步
//1. 文件打开 fopen ,并且判断是否f打开成功
//2. 文件处理 fprintf,fgetc,fgets,fputc,fputs,fread,fwrite;在while循环中处理
//3. 文件关闭 fclose 并且要判断文件是否关闭成功

//读取文件的三种方式 字符，字符串，二进制流
//字符 fgetc
void readFileTest(void);
//字符串 fgets
void readFileTest2(void);
// fread fwrite
void readFileTest3(void);

//文件的拷贝 fgetc的 同时进行fputc
void copyFileTest(void);
void fprintfTest2(void);


#endif
