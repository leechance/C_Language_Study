

#include <stdio.h>
#include "BasicTest.h"
#include "Exam.h"
#include "CLanguageDemo.h"
#include "StringTest.h"
#include "PointerTest.h"
#include "student.h"

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
    studentTest();
    
    
    
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
