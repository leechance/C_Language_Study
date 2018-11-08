//
//  student.h
//用结构体构造对象
//

#ifndef student_demo1_student_h
#define student_demo1_student_h
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//学生结构体
typedef struct{
   //名字
   char *name;
   //性别
   unsigned int sex;
    //年龄
   unsigned int age;
} ST_STUDENT;

//性别枚举
typedef enum{
     MALE,
     FEMALE
} SEX;


/**
 构造结构体

 @param c_self 指针
 @param name 名称
 @param sex 性别
 @param age 年龄
 @return 学生
 */
ST_STUDENT   *initSTUDENT (ST_STUDENT *c_self,char *name,unsigned int sex,unsigned int age);

//设置学生名称
bool setstudentName(ST_STUDENT *c_self,char *name);
//设置学生性别
bool setstudentSex (ST_STUDENT *c_self,unsigned int sex);
//设置学生年龄
bool setstudentAge( ST_STUDENT *c_self,unsigned int age);
//打印学生
void printStudent(ST_STUDENT *c_self);
//销毁
void deallocStudent(ST_STUDENT *c_self);



#endif
