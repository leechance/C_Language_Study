//
//  StringTest.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/6.
//  Copyright © 2018 chance. All rights reserved.
//

#include "StringTest.h"
#include<stdlib.h>
#include<ctype.h>
#include <string.h>
#include <stdlib.h>


//未完待续
int myatoi(const char *src){
  
    int i=0;//记录位数
    
        if (*src=='-'||*src=='+'||(*src>='0'&&*src<='9')) {
            i++;
            src++;
        
            
            while (src&&(*src>='0'&&*src<='9')) {
                i++;
                src++;
                
            }
            
            
        }else{
            return 0;
        }
    
  
    return 0;
    
}

//字符串求长度
unsigned long mystrlen(char *src)
{
    //字符串指针（p指向字符串的首地址）
    // p++ 偏移的大小也就是p指向的数据类型占用的字节数,这里p指向的是单个字符，所以p++每次偏移一个字节0x0000000000007812 到 0x0000000000007813，
    
    
    // pstr的地址变化 pstr其实就是字符串，
    //(char *) $0 = 0x0000000100002f20 "abcdefgh"
    //(char *) $1 = 0x0000000100002f21 "bcdefgh"
    //(char *) $2 = 0x0000000100002f22 "cdefgh"
    //.....
    //(char *) $3 = 0x0000000100002f27 "h"
    //(char *) $0 = 0x0000000100002f28 ""
    // 判定条件可以 while(strcmp(pstr, ""))或者 while (*pstr!='\0')
    
    
    char*pstr=src;
    
    unsigned long len=0;
    while (*pstr!='\0') {
        len++;
        //指针偏移
        pstr++;
    }
    return len;
}

char *mystrcpy(char *dest ,const char*src)//dest 指向的空间 要可以容纳src的空间
{
    char*pstr=dest;

    //src本身字符串，同时指向字符串的首地址
    
    //通过遍历src字符串，不断偏移pstr指针，并且给*pstr赋值
    //遍历结束之后 一定要给 *pstr一个 '\0'
    while (*src) {
        *pstr=*src;
        pstr++;
        src++;
    }
   *pstr='\0';
    return dest;
}


char *mystrcat(char *dest ,const char*src)//dest 指向的空间 要可以容纳src的空间
{
    //1)*pstr 赋初值，比如dest=”abcd“,先让pstr指向’\0‘
    //2)通过遍历src字符串，不断偏移pstr指针，并且给*pstr赋值
    //3)遍历结束之后 一定要给 *pstr一个 '\0'
    size_t len=strlen(dest);
    char*pstr=dest+len;
    while (*src) {
        *pstr=*src;
        pstr++;
        src++;
    }
    *pstr='\0';
    return dest;
}

/*
 参数
 str1 -- 要进行比较的第一个字符串。
 str2 -- 要进行比较的第二个字符串。
 返回值
 该函数返回值如下：
 如果返回值 < 0，则表示 str1 小于 str2。
 如果返回值 > 0，则表示 str2 小于 str1。
 如果返回值 = 0，则表示 str1 等于 str2
 */


int mystrcmp(char*str1,char*str2)
{
    //同时遍历两个字符串，只要不相等就退出
    //返回比较的是第一个不相等的字符的ASCII之差
    while (*str1&&*str2) {
        if (*str1!=*str2) {
            break;
            
        }
        str1++;
        str2++;
    }
    return *str1-*str2;

}


char* mystrchr(const char *src,char ch)
{
    while (*src) {
        if (*src==ch) {
            return (char *)src;
        }
        src++;
    }
    return NULL;

}

char* mystrrchr(const char *src,char ch)
{
    long  len=strlen(src);
    char *pstr=(char*)src+len-1;
    for (long i=len-1; i>0; i++) {
        if (*pstr==ch) {
            return pstr;
        }
        pstr--;
    }
     return NULL;
}

//就是将字符串的每一个字符重置，原字符串改变
void stringReset(void){
        char str[100]={};
        scanf("%s",str);
        int len=(int)strlen(str);
        char* ret=memset(str,'a',len);
        printf("%s\n",str);
        printf("原字符串：%s\n",ret);
    
}
//由src所指内存区域复制count个字节到dest所指内存区域。
//src和dest所指内存区域不能重叠，函数返回指向dest的指针。
void memcpyTest(void){
        char str[100]={};
        char d[20];
    
        scanf("%s",str);
        puts(str);
        memcpy(d,str,strlen(str));
        d[strlen(str)]=0;
        printf("%s",d);
        printf("原字符串：%s\n",d);
    
    //    return 0;
}

void strstrTest(void){
   char str[100]={};
   char p[20]={};
   scanf("%s %s",str,p);
   char*ret=strstr(str, p);
   if (ret) {
       printf("YES");
   }else
       printf("NO");
}


int strncmpTest(char *s, char *a){
        int ls,la,i;
        int flag = -1;
        ls = (int )strlen(s);
        la = (int)strlen(a);
        if (la > ls) return -1;
        for (i=0;i<=ls-la;i++){
            if  (strncmp(s+i,a,la)==0) return i;
        }
        return flag;
}
void strncmpTestDemo(void){
        char s[20]={};
        char a[10]={};
        scanf("%s %s",s,a);
        int i;
        i = strncmpTest(s,a);
    if (i < 0) printf("No match\n"); else printf("%d\n",i);
}
//统计输入字符数
int countInputCharNumber(void){
    char ch=' ';
    int count=0;
   //这行代码如果不添加，在Xcode控制台输入字符，不显示
    printf("请输入字符 按回车键结束：\n");
    //1. while的循环条件其实是逗号表达式，先执行 scanf("%c",&ch)，但是判断条件是ch!='\n'
    //2. 如果把 scanf("%c",&ch) 放入循环体内，这样统计字符的话，会多一个
    //3 scanf函数的返回值，不管输入什么字符都是返回1
    
    while (scanf("%c",&ch),ch!='\n') {
        count++;
    }
  
    printf("\ncount = %d", count);
   
    
    return count;
}

int countInputCharNumber2(void){
    //这行代码如果不添加，在Xcode控制台输入字符，不显示
    printf("请输入字符 按回车键结束：\n");
    
    int count=0;
    while (getchar()!='\n') {
        count++;
    }
    printf("count = %d\n",count);
    return count;

}
