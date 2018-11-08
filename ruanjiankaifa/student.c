//
//  student.c
//  student_
//  用结构体构造对象
//

#include <stdio.h>
#include"student.h"

//校验性别
static bool checkSex(unsigned int sex);

//初始化对象的时候，要开辟内存
ST_STUDENT   *initSTUDENT (ST_STUDENT *c_self,char *name,unsigned int sex, unsigned int age)
{
   //没有开辟成功，或者没有名称的，是不能生成具体的学生对象的
    if (!c_self||!name) {
        return NULL;
    }
    //名称空间开辟
    int nameLen=(int)strlen(name);
    c_self->name=(char*)malloc(nameLen+1);
    
    if(!c_self){
        return NULL;
    }
    strncpy(c_self->name,name,nameLen+1);
    
    //校验性别，如果失败释放空间
    if (!checkSex(sex)) {
        free( c_self->name);
        c_self->name=NULL;
        return NULL;
    }
    
    c_self->sex=sex;
    c_self->age=age;

    return c_self;

}
bool setstudentName(ST_STUDENT *c_self,char *name)
{
    if(!c_self||!name)
     {return false;}

    int nameLen=(int)strlen(name);
    if (!c_self->name) {
       c_self->name=(char*)malloc(nameLen+1);}
    else{
        c_self->name=realloc(c_self->name,nameLen+1);
    
    }
        if(!c_self->name)
            return false;
        
    
   strncpy(c_self->name,name,nameLen+1);
return true;
}


bool setstudentSex(ST_STUDENT *c_self, unsigned int sex)

{
    if (!c_self) {
        return false;
    }
    if (!checkSex(sex)) {
        return false;
    }
    c_self->sex=sex;
    return true;


}
bool setstudentAge(ST_STUDENT *c_self,unsigned int age)
{
    if (!c_self) {
        return false;
    }
    c_self->age=age;
    return true;

}
//销毁，名称空间，释放自身空间
void deallocStudent(ST_STUDENT *c_self)
{
    if (!c_self) {
        return;
    }
    if(c_self->name)
    {}
    else
    {   free (c_self->name);
        c_self->name=NULL;
    }
    free(c_self);
    c_self=NULL;
    return;
        


}

void printStudent(ST_STUDENT *c_self)
{
    if (!c_self) {
        return;
    }
    printf("************************\n");
     printf("************************\n");
    if (c_self->name) {
        printf("名字: %s\n",c_self->name);
    }
else
{
    printf("名字   \n");

}
    
    if (c_self->sex==MALE) {
        printf("性别: 男性\n");
    }
    else if (c_self->sex==FEMALE) {
        printf("性别: 女性\n");
    }
    else{
        printf("性别错误\n");}
    printf("年龄: %d\n",c_self->age);
    printf("******************************\n");
    printf("******************************\n");
    
    
}



static bool checkSex(unsigned int sex)
{

    if (sex==MALE||sex==FEMALE) {
        return true;
        
    }
    else
        return false;
}
