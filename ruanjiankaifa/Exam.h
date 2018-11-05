//
//  Exam.h
//软件开发工具实践考试

#ifndef Exam_h
#define Exam_h
#include <stdio.h>

void print(char*s,FILE*fp);
void initArray(int a[],int n,int r);
//写入数组到文件
void writeArray(int a[],int n,int c,FILE*fp);
//排序
void Sort(int *a,int n,FILE*fp);
void Search(int *a,int n,FILE*fp);

#endif
