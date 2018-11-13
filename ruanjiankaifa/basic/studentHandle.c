//
//  studentHandle.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/8.
//  Copyright © 2018 chance. All rights reserved.
//

#include "studentHandle.h"
static bool checkSex(unsigned int sex);

//全局的结构体数组
static ST_STUDENT *stu[NUMBER_OF_SIZE]={NULL};

//创建一个学生，句柄+1（也就是这个函数每调用一次都会加1）
studentHandle createStudent(char *name,unsigned int sex,unsigned int age)
{
    int ID=-1;
    int i=0;
    int  nameLen=0;
    if(!name)
    {return -1;}
    
    //校验，如果数组中不存在结构体，句柄+1
    for(i=0;i<NUMBER_OF_SIZE;i++)
    {if(!stu[i])
    {
        break;}
        
    }
    if(i==NUMBER_OF_SIZE)
    {  return -1;
    }
    ID=i;
    stu[ID]=(ST_STUDENT*)malloc(sizeof(ST_STUDENT));
    if(!stu[ID])
    {return -1;}
    nameLen=(int)strlen(name);
    stu[ID]->name=(char*)malloc(nameLen+1);
    if(!stu[ID]->name)
    { free(stu[ID]);
        stu[ID]=NULL;
        return -1;
    }
    strncpy(stu[ID]->name, name,nameLen+1);
    
    
    
    if(!checkSex(sex)){
        free(stu[ID]->name);
        free(stu[ID]);
        stu[ID]=NULL;
        return -1;
    }
    
    stu[ID]->sex=sex;
    stu[ID]->age=age;
    return ID;
    
}

bool setStudentName2(studentHandle stuID,char *name)
{
    if (stuID>NUMBER_OF_SIZE-1) {
        return false;
    }
    if (!stu[stuID]) {
        return false;
    }
    int nameLen=(int)strlen(name);
    if (stu[stuID]->name) {
        stu[stuID]->name=(char*)realloc(stu[stuID]->name, nameLen+1);
        if (!stu[stuID]->name) {
            return false;
        }
    }
    else
    {
        stu[stuID]->name=(char*)malloc(nameLen+1);
        if (!stu[stuID]->name) {
            return false;
        }
        
    }
    strncpy(stu[stuID]->name,name,nameLen+1);
    return true;
    
    
    
}

bool setStudentSex2(studentHandle stuID,unsigned int sex)
{
    if (stuID>NUMBER_OF_SIZE-1) {
        return false;
    }
    if (!stu[stuID]) {
        return false;
    }
    if (!checkSex(sex)) {
        return false;
    }
    stu[stuID]->sex=sex;
    return true;
    
}

bool setStudentAge2(studentHandle stuID,unsigned int age)
{
    if (stuID>NUMBER_OF_SIZE-1) {
        return false;
    }
    if (!stu[stuID]) {
        return false;
    }
    
    stu[stuID]->age=age;
    
    return true;
}

void releaseStudent2(studentHandle stuID)
{
    if (stuID > NUMBER_OF_SIZE-1) {
        return;
    }
    if (!stu[stuID]) {
        return;
    }
    if (stu[stuID]->name) {
        free(stu[stuID]->name);
        stu[stuID]->name = NULL;
    }
    free(stu[stuID]);
    stu[stuID]=NULL;
    return;
    
}




void printStudent2(studentHandle stuID)
{
    if (stuID>NUMBER_OF_SIZE) {
        return;
    }
    if (!stu[stuID]) {
        return;
    }
    printf("********************************\n");
    printf("********************************\n");
    if (stu[stuID]->name) {
        printf("姓名: %s\n",stu[stuID]->name);
    }
    else{
        printf("姓名:     \n");}
    if (stu[stuID]->sex==0) {
        printf("性别: 男性\n");
    }
    else if (stu[stuID]->sex==1)
    {
        printf("性别: 女性\n");}
    else
        printf("性别错误\n");
    
    printf("年龄: %d\n",stu[stuID]->age);
    printf("********************************\n");
    printf("********************************\n");
    
    return;
    
    
}

static bool checkSex(unsigned int sex)
{
    if (sex==0||sex==1) {
        return true;
    }
    else
        return false;
    
}
