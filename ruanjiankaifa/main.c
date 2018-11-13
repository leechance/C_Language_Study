


#include "Header.h"

#define LENGTH 10
#define RANGE  100

#pragma mark 函数声明
void basicTest(void);
void studentTest(void);
void studentHandleTest(void);
void stringTest(void);
void arrayTest(void);
void DemoTest(void);
void pointerTest(void);

#pragma mark 程序入口
int main(int argc, const char * argv[]) {
    
    


//    basicTest();
//    examTest();
//    DemoTest();

//    studentTest();
//    studentHandleTest();
//    stringTest();
    arrayTest();
//    pointerTest();
    
    return EXIT_SUCCESS;
}

#pragma mark 基础测试
void basicTest(void){
//    printfTest();
//    scanfTest();
    
    fflush(stdin);
    fp=fopen("/Users/chance/Documents/GitHub/C_Language_Study/ruanjiankaifa/output/out.txt", "w+");
    fprintfTest(fp);
}

#pragma mark C语言编程demo
void DemoTest(void){
//    Faibonaqi2();
//    jiecheng();
//    a1PlusA2toA3();
//    JinZiTa4();
//    JuzhenReverse();
}

#pragma mark 结构体模拟对象
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

#pragma mark 创建多个对象使用 句柄
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
#pragma mark 字符串测试
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
#pragma mark 数组测试
void arrayTest(void){
//    YangHuiSanjiao();
//    DengYaoYangHuiSanjiao();
    
   
    
    int *a =initArrayWithRandFunc(LENGTH, RANGE);
    //maopaoSort(a, LENGTH);
    //selectSort(a, LENGTH);
    insertSort(a,LENGTH);
    
    
    
}
#pragma mark 指针测试
void pointerTest(void){
    pointerBasicTest();
}
