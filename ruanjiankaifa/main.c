

#include <stdio.h>
#include "BasicTest.h"
#include "Exam.h"
#include "CLanguageDemo.h"
#include "StringTest.h"
#include "PointerTest.h"
#include "student.h"
#include "studentHandle.h"
#include "ArrayTest.h"

//文件
FILE* fp;
//数组
int *a;


void basicTest(void){
    // printfTest();
    // scanfTest();
    
     fprintfTest(fp);
}

void examTest(void){
  
    int n,range;
    char ch;
    //功能1 。循环等待用户输入
    while (1) {
        printf("请输入元素个数n以及范围:\t");
        fflush(stdout);
        scanf("%d%d",&n,&range);
        if (n>0&&n<1001) {
            break;
        }
    }
    

    
    //功能2.初始化数组
    a=(int*)malloc(n*sizeof(int));
    initArray(a, n, range);
    
    print( "原数组：",fp);
    writeArray(a, n, 10,fp);
    
    
    //功能3 循环等待 用户输入字符 ch
    
    while (1){
        printf("请选择\n\t\t排序s    \t查询f \t");
        fflush(stdout);
        scanf("%c", &ch);
        if (ch=='f' || ch=='s')
            break;
    }
    
    if (ch=='s') {
        //排序
        print("排序后的序列:\n",fp);
        Sort(a, n,fp);
        
    }else{
        //查询
        print("能被三整除的是：",fp);
        Search(a, n,fp);
        
    }
}

void studentTest(void);
void studentHandleTest(void);
void stringTest(void);
void arrayTest(void);

int main(int argc, const char * argv[]) {
  
   // printfTest();
   // scanfTest();
    
    
    fflush(stdin);
    // fopen函数（https://blog.csdn.net/manonghouyiming/article/details/78606710）
    fp=fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/out.txt", "w+");
  //  basicTest();
    //examTest();
    
    //Faibonaqi2();
    //jiecheng();
    //a1PlusA2toA3();
   // JinZiTa4();
   // JuzhenReverse();
   // pointerBasicTest();
   // studentTest();
   // studentHandleTest();
    stringTest();
    //arrayTest();
    
    
    
    return 0;
}


void studentTest(void){
    //1、学生结构体开辟内存空间（malloc）
    ST_STUDENT *stu=(ST_STUDENT*)malloc(sizeof(ST_STUDENT));
    //2.开辟失败处理
    if (!stu) {
        exit(-1);
    }
    //3.生成具体结构体实例
    initSTUDENT(stu,"小明",MALE,18);
    
    printStudent(stu);
    setstudentName(stu,"小张");
    printStudent(stu);
    setstudentSex(stu, FEMALE);
    printStudent(stu);
    setstudentAge(stu, 25);
    printStudent(stu);
    deallocStudent(stu);
}
void studentHandleTest(void){
    
    //这三个是不同的学生，在结构体的数组的索引是0，1，2
    //以后对学生的操作只需要传入句柄，根据句柄索引出具体的学生，然后进行设置
    studentHandle tempId=createStudent("范冰冰",1,33);
    studentHandle tempId1=createStudent("范冰冰",1,33);
    studentHandle tempId2=createStudent("范冰冰",1,33);
    
    printStudent2(tempId);
    setStudentName2(tempId,"赵薇");
    printStudent2(tempId);
    setStudentSex2(tempId, 0);
    printStudent2(tempId);
    setStudentAge2(tempId, 35);
    printStudent2(tempId);
    releaseStudent2(tempId);
    
    
}
void stringTest(void){
    
    //atoi函数就是从左到右遍历，如果以字母开头，返回0，如果数字开头，知道不是数字
    int a= atoi("7576"); //7576
    int b=atoi("1234ghhg345"); //1234
    int e=atoi("-1234-345");//-1234
    int f=atoi("-f1213sf");//0
    printf("%d\n%d\n%d\n",a,b,e,f);
    

    
    
  unsigned long len=  mystrlen("abcdefgh");
    
    //拷贝
    char buf[100]={};
    char* p="abcd";
    //char *ret=strcpy(buf, p1);
    char *ret=mystrcpy(buf, p);
    printf("%s\n%s\n%c\n",buf,ret,*ret);
    
    
    //追加
    char buf1[100]={};
    char *p1="abcd";
    strcpy(buf1, p1);
    char *src="egfh";
    //char *ret1= strcat(buf1,src);
    char *ret1= mystrcat(buf1,src);
    printf("%s\n%s\n%c\n",buf,ret1,*ret1);
    
    int c=strcmp("fjgff", "kgkghjgk");
    printf("%d\n",c);
    int d=strcmp("abc","cd");
    printf("%d\n",d);
    char*p0="abcd";
    char j[]="abcd";
    d=strcmp(p0,j);
    
    
//    char*str=strchr("abcdefghijksdddsdsds", 'd');
//    char*rstr=strrchr("abcdefghijkdjklleowip", 'd');
    
        char*str=mystrchr("abcdefghijksdddsdsds", 'd');
        char*rstr=mystrrchr("abcdefghijkdjklleowip", 'd');
    
    int aaa= '0';
    
    stringReset();
    memcpyTest();
    

    
}

void arrayTest(void){
    YangHuiSanjiao();
    DengYaoYangHuiSanjiao();
}
