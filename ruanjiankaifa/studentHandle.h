//
//  studentHandle.h
//  ruanjiankaifa
//  结构体数组保存创建的数组，并返回句柄

#ifndef studentHandle_h
#define studentHandle_h

#include <stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"



typedef unsigned long studentHandle;//句柄,标识在结构体数组的索引
#define NUMBER_OF_SIZE 1024

studentHandle createStudent(char *name,unsigned int sex,unsigned int age);
bool setStudentName2(studentHandle stuID,char *name);
bool setStudentSex2(studentHandle stuID,unsigned int sex);
bool setStudentAge2(studentHandle stuID,unsigned int age);

void printStudent2(studentHandle stuID);
void releaseStudent2(studentHandle stuID);


#endif
