//
//  StringTest.h
//  字符串测试
//  Created by chance on 2018/11/6.
//  Copyright © 2018 chance. All rights reserved.
//
//http://www.runoob.com/cprogramming/c-function-strcmp.html

/*
 字符操作函数
 int     isalnum(int);//判断是否为数字或者字母;
 int     isalpha(int);//判断是否为字母;
 int     isdigit(int);//判断是否为十进制数字0~9
 int     isgraph(int);//判断是否为可见字符, 空字符,\0 \n均不可见\t \f
 int     islower(int);  //判断是否为小写字母;
 int     isspace(int);//\n,\t,\f,是1,\0是 0 //判断是否为空格
 int     isupper(int);//判断是否为大写字符
 int     isxdigit(int);//判断是否为是否为十六进制数字0~f或者大写
 int     tolower(int);//把大写字母转换小写字母;如果是小写,直接输出
 int     toupper(int);//把小写字母转换大写字母
 int     isascii(int);//
 int     toascii(int);
 int     _tolower(int);
 int     _toupper(int);
 int     digittoint(int); //把十六进制转换十进制整形输出
 int     ishexnumber(int);//判断是否十六进制 类似isxdigit
 int     isideogram(int);
 int     isnumber(int);//判断是否为数字,类似isdigit
 
 
 
 1)字符串必须以\0结尾
 2)字符串每个字符占用一个字节的内存空间
 3)字符串的有效长度 不包括\0

 
 字符串操作函数
 void    *memchr(const void *, int, size_t);
 int     memcmp(const void *, const void *, size_t);
 void    *memcpy(void *, const void *, size_t);
 void    *memmove(void *, const void *, size_t);
 void    *memset(void *, int, size_t);
 char    *strcat(char *, const char *);
 char    *strchr(const char *, int);
 int     strcmp(const char *, const char *);
 int     strcoll(const char *, const char *);
 char    *strcpy(char *, const char *);
 size_t     strcspn(const char *, const char *);
 char    *strerror(int) __DARWIN_ALIAS(strerror);
 size_t     strlen(const char *);
 char    *strncat(char *, const char *, size_t);
 int     strncmp(const char *, const char *, size_t);
 char    *strncpy(char *, const char *, size_t);
 char    *strpbrk(const char *, const char *);
 char    *strrchr(const char *, int);
 size_t     strspn(const char *, const char *);
 char    *strstr(const char *, const char *);
 char    *strtok(char *, const char *);
 size_t     strxfrm(char *, const char *, size_t);
 
 1)strcpy 拷贝之后默认加一个'\0'
 2)strncpy 有字节数限制,安全性高一点,拷贝的字符串不一定以\0结束，拷贝个数可以大于被拷贝的字符串的长度，dest跟src所指向的内存不能重叠
 3)strcat src指向的内存不能重叠，直接在dest后面加一个\0然后拼接;dest 剩余的内存空间足够容纳src指 向的字符串的空间;剩余的空间 sizeof(dest)-strlen(dest)-1;
 4）strncat 表示从src中最大拷贝的字节数,拷贝的字符串自动添加'\0'，剩余的空间 sizeof(dest)-strlen(dest)-1
 5）strcmp 返回值为两个字符串第一个不相等的差值 dest-src;比较的时ASCII值
 6)strchr  把字母的地址,从该字符的地址返回;没有找到,返回空;;从左到右输出
 7)strrchr 从右到左输出
 8)字符串解析函数 sscanf sprintf
 9)文件解析函数 fscanf fprintf
 */



#ifndef StringTest_h
#define StringTest_h

#include <stdio.h>
//字符串转整数atoi
int myatoi(const char *src);

//字符串求长度
unsigned long mystrlen(char *src);
//字符串拷贝
char *mystrcpy(char *dest ,const char*src);
//字符串追加
char *mystrcat(char *dest ,const char*src);
//字符串比较
int mystrcmp(char*str1,char*str2);
//从左到右遍历知道某个字符出现，从左到右输出
char* mystrchr(const char *src,char ch);
//从从右到左遍历知道某个字符出现，从左到右输出
char* mystrrchr(const char *src,char ch);



/*
 定义一个字符数组，初始化数组，将内容输出利用memset函数将数组中的内容全部初始化为a,并将数组内容输出。
 比如：
 输入
 asdfwd
 输出为
 asdfwd
 aaaaaa
 
 输入
 sgfgeasdfw
 输出为
 sgfgeasdfw
 aaaaaaaaaa

 */

void stringReset(void);

/*
 定义两个元素个数相同的整型数组，然后对其中一个数组进行随机初始化，
 利用memcpy函数将第一个数组中的内容复制到第二个数组中，并将两个数组中的内容分别输出。
 比如：
 输入
 asdfwd
 输出为
 asdfwd
 asdfwd
 
 输入
 sgfgeasdfw
 输出为
 sgfgeasdfw
 sgfgeasdfw
 */
void memcpyTest(void);

/*
 比较一个字符串2在字符串1中是否存在,如果存在输出Y，否则输出N
 比如：
 输入
 asdfwd
 dfw
 输出为
 Y
 
 输入
 sgfgeasdfw
 hhff
 输出为
 N
 */
void strstrTest(void);


/**
 查找一个字符在字符串1中第一次出现的字符位置，
 比如：
 输入
 asdfwd
 d
 输出为
 2
 
 输入
 hhff
 h
 输出为
 0
 */
int strncmpTest(char *s, char *a);

void strncmpTestDemo(void);


 
//
//
//
// #include<stdlib.h>
// #include<ctype.h>
// #include<stdio.h>
// #include <string.h>
// #include <stdlib.h>
//
//
//
//
//
// //从键盘输入一个只包含0和1的二进制数字串（字符串不超过64位），然后把这个字符串所表示的二进制数转换成十进制数，并输出。
// //比如：
// //输入：
// //00000001
// //输出为
// //1
// //
// //输入：
// //1001
// //
// //输出为
// //9
// //输入
// //000111
// //输出为
// //7
//
//
//
// //#include <stdio.h>
// //#include <math.h>
// //#include <string.h>
// //
// //int main()
// //{
// //    char s[21];
// //    long a, i, len, k;
// //
// //    scanf("%s",s);
// //    len = strlen(s);
// //    a = 0; k = 1;
// //    for(i=len-1; i>=0; i--)
// //    {
// //        if(s[i] == '1') a += pow(2.0, len-1-i);
// //        //a += k;
// //        //k = k * 2;   /* 表示2^k的值 */
////    }
////    printf("%ld\n",a);
////    return 0;
////}
//
////统计任意串中大写字母的个数。
////比如：
////输入
////234ADWDGfwDW
////输出为
////7
////输入
////772WdfWFDGWH3r
////输出为
////#include<stdio.h>
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    char*p=str;
////    int i=0;
////    int cnt=0;
////    for (i=0; i<100; i++) {
////        scanf("%c",&str[i]);
////    if (*(p+i)=='\n') {
////        break;
////    }
////        if (*(p+i)>='A'&&*(p+i)<='Z') {
////            cnt++;
////        }
////
////    }
////    printf("%d",cnt);
////    return 0;
////}
//
//
//
//
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    char*p=str;
////    int i=0;
////    int cnt=0;
////    for (i=0; i<100; i++) {
////        scanf("%c",&str[i]);
////        if (*(p+i)=='\n') {
////            break;
////        }
////        if (isupper(*(p+i))) {
////            cnt++;
////        }
////
////    }
////    printf("%d",cnt);
////    return 0;
////}
//
//
//
//// 统计任意串中小写字母的个数。
//
////int main(int argc,const char *argv[])
////{
////    char ch;
////    //char*p=str;
////
////    int cnt=0;
////    while (scanf("%c",&ch))
////    {
////        if (ch=='\n') {
////            break;
////        }
////        if (ch>='a'&&ch<='z') {
////            cnt++;
////        }
////
////    }
////    printf("%d",cnt);
////    return 0;
////}
//
//
////统计小写字母的个数
//
////int main(int argc,const char *argv[])
////{
////    char ch;
////
////
////    int cnt=0;
////    while (scanf("%c",&ch))
////    {
////        if (ch=='\n') {
////            break;
////        }
////        if (islower(ch)) {
////            cnt++;
////        }
////
////    }
////    printf("%d",cnt);
////    return 0;
////}
//
////统计数字个数
////#include<stdio.h>
////#include<ctype.h>
////int main(int argc,const char *argv[])
////{
////    char ch[100];
////    int cnt=0;
////    int i;
////    for (i=0;i<100;i++)
////    {
////        scanf("%c",&ch[i]);
////        if (ch[i]=='\n') {
////            break;
////        }
////        if (isdigit(ch[i])) {
////            cnt++;
////        }
////
////    }
////    printf("%d",cnt);
////    return 0;
////}
//
////绝对值大小
//
////#include<math.h>
////int main(int argc,const char *argv[])
////{
////    int a,b;
////    scanf("%d %d",&a,&b);
////    printf("%d",abs(a-b));
////    return 0;
////}
//
//
////字符串排序。比较三个字符串的大小，然后按从小到大的顺序将字符串输出。
////比如：
////输入
////asdfwd
////ddrwf
////ffweff
////输出为
////asdfwd
////ddrwf
////ffweff
////#include <stdio.h>
////#include <string.h>
////int main(int argc,const char*argv[])
////{
////    char str1[100]={};
////    char str2[100]={};
////    char str3[100]={};
////    scanf("%s%s%s",str1,str2,str3);
////    if (strcmp(str1,str2)>0)
////    {
////        if (strcmp(str3, str1)>0) {
////            printf("%s\n%s\n%s\n",str2,str1,str3);
////        }
////
////        else {if(strcmp(str2, str3)>0){printf("%s\n%s\n%s\n",str3,str2,str1);}
////            else printf("%s\n%s\n%s\n",str2,str3,str1);}
////
////
////    }
////    else{
////        if (strcmp(str3, str1)>0) {
////            printf("%s\n%s\n%s\n",str1,str2,str3);
////        }
////
////        else {if(strcmp(str2, str3)>0){printf("%s\n%s\n%s\n",str3,str1,str2);}
////            else printf("%s\n%s\n%s\n",str1,str3,str3);}
////    }
////
////    return 0;
////
////}
////选择排序,用指针的方式
////int main(int argc,const char*argv[])
////{
////    char*pstr[3]={};
////
////    char *temp={NULL};
////    int i,j,small;
////    for (i=0;i<3; i++) {
////        pstr[i]=(char*)malloc(20*sizeof(char));
////        //pstr[i]=(char*)calloc(100,1);//两种内存申请方式
////        if(!pstr[i]){return -1;}
////        scanf("%s",pstr[i]);
////    }
////    for (i=0; i<3; i++) {
////        small=i;
////        for (j=i+1; j<3; j++) {
////            if (strcmp(pstr[small], pstr[j])>0) {
////                temp=pstr[small];
////                pstr[small]=pstr[j];
////                pstr[j]=temp;
////            }
////        }
////    }
////    for (i=0; i<3; i++) {
////        printf("%s\n",pstr[i]);
////        free(pstr[i]);
////        pstr[i]=NULL;
////    }
////
////}
//
////#############################
//
////int main(int argc,const char *argv[])
////{
////    char *str= "afalfalfa";
////    char *pstr =str;
////    while ((pstr= strchr(pstr, 'a'))) {
////
////        printf("%lu\n",pstr-str+1);
////        pstr++;
////    }
////    return 0;
////}
//
////查找一个字符在字符串1中出现的所有字符位置，
////比如：
////输入
////asdfwd
////d
////输出为
////3
////6
//
////int main(int argc,const char *argv[])
////{
////    char str[100]= {};
////    char *pstr =str;
////    char ch;
////    char*p=&ch;
////    scanf("%s %c",pstr,p);
////    // pstr=strchr(str,p);然后直接输出,不用判断;;
////    while ((pstr= strchr(pstr, *p))) {
////
////        printf("%lu\n",pstr-str+1);
////        pstr++;
////    }
////    return 0;
////}
//
//
////查找一个字符串2在字符串1中出现的次数，
////比如：
////输入
////asdfwd
////d
////输出为
////2
//
////只有一个字符的情况下
////int main(int argc,const char *argv[])
////{
////    char str[100]= {};
////    char *pstr =str;
////    char ch;
////    char*p=&ch;
////    int count=0;
////    scanf("%s %c",pstr,p);
////    while ((pstr= strchr(pstr, *p))) {
////
////        count++;
////        pstr++;
////    }
////    printf("%d",count);
////    return 0;
////}
////字符串的情况下;
////int main(int argc,const char *argv[])
////{
////    char str[100]= {};
////    char *pstr =str;
////    char ch[10]={};
////    char*p=ch;
////    int count=0;
////    scanf("%s",pstr);
////      scanf("%s",p);
////    while ((pstr= strstr(pstr, p))) {
////
////        count++;
////        pstr++;
////    }
////    printf("%d",count);
////    return 0;
////}
//
////查找一个字符串2在字符串1中第一次出现的位置
////比如：
////输入
////asdfwd
////df
////输出为
////3
//
////查找一个字符串2在字符串1中第一次出现的位置
//
////int main(int argc,const char *argv[])
////{
////    char str[100]= {};
////    char *pstr =str;
////    char ch[10]={};
////    char*p=ch;
////
////    scanf("%s",pstr);
////      scanf("%s",p);
////    if (strstr(str, ch)==0) {
////        printf("0");
////    }
////    while ((pstr= strstr(pstr, p))) {
////
////    printf("%lu",pstr-str+1);
////
////        break;
////        pstr++;
////    }
////
////
////    return 0;
////}
//
//
////查找一个字符串2在字符串1中所有出现的位置
////比如：
////输入
////hhfhf
////hf
////输出为
////2
////4
//
////int main(int argc,const char *argv[])
////{
////    char str[100]= {};
////    char *pstr =str;
////    char ch[10]={};
////    char*p=ch;
////
////    scanf("%s",pstr);
////      scanf("%s",p);
////    if (strstr(str, ch)==0) {
////        printf("0");
////    }
////    while ((pstr= strstr(pstr, p))) {
////
////    printf("%lu\n",pstr-str+1);
////
////
////        pstr++;
////    }
////
////
////    return 0;
////}
//
//
////给定一个任意字符串，然后将该字符串逆序输出。
////
////比如：
////
////输入
////
////asdfwd
////
////输出为
////
////dwfdsa
//
////int main(int argc,const char *argv[])
////{
////    char str[100]= {};
////    char *pstr =str;
////         long i;
////    scanf("%s",pstr);
////    long len=strlen(pstr);
////    for (i=len-1; i>=0; i--) {
////        printf("%c",*(pstr+i));
////    }
////    return 0;
////}
//
//
////输入一段字符串，统计其中的单词个数
////比如：
////输入 I like iOS
////输出：
////3
////
////输入 this is Qian Feng College
////输出:
////5
//
////以空格作为分隔符, 统计单词个数
////"qian    feng    hello   world"
////"    qian feng hello   world"
//
////int word_number(const char *str)
////{
////    int cnt=0;
////    int flag=0;
////    while (*str)
////    {
////        if (*str!=' ')
////        {
////            if (!flag)
////            {
////                cnt++;
////                flag=1;
////            }
////        }
////        else
////        {
////            if (flag) {
////                flag =0;
////            }
////        }
////        str++;
////    }
////    return cnt;
////}
////int main(int argc,const char* argv[])
////{
////    char str[100]={};
////
////    scanf("%[^\n]",str);
////    printf("%d",word_number(str));
////    return 0;
////}
//
////输入一段字符串(不超过10个单词)，没有空格外的标点符号，将每个单词逆序输出
////比如：
////输入 this is a cat
////输出：
////cat a is this
////
////输入 who are you
////输出:
////you are who
//
//
////int main(int argc,const char* argv[])
////{
////    char str[100]={};
////        scanf("%[^\n]",str);
////    char *pstr=str;
////    char *q[10]={};
////    int i=0;
////    while (1) {
////        pstr=strtok(pstr," ");
////        if(!pstr)
////            break;
////        q[i++]=pstr;
////        pstr=NULL;
////    }
////
////    for (i=9; i>=0; i--) {
////       if (q[i])printf("%s\n",q[i]);
////    }
////    return 0;
////        }
//
////定义两个字符数组，分别输入两个字符串，利用字符串处理函数判断，字符串2在字符串1中是否存在,如果存在输出Y，否则输出N。
////
////比如：
////
////输入：
////
////abcdefg
////
////cde
////
////输出：
////
////Y
////int main(int argc,const char*argv[])
////{
////    char str[100]={};
////    char pstr[20]={};
////    scanf("%s %s",str,pstr);
////    char*ret=strstr(str,pstr);
////    if (ret) {
////        printf("Y");
////    }
////    else
////        printf("N");
////
////}
////输入一段字符串(不超过10个单词)，没有空格外的标点符号，将每个单词逆序输出
////
////比如：
////
////输入 this is a cat
////
////输出：
////
////cat a is this
//
//
////int main(int argc,const char*argv[])
////{
////    char str[100]={};
////    scanf("%[^\n]",str);
////    char*p=str;
////    char *q[10]={};
////    int i=0;
////    while(1)
////    {
////        p=strtok(p," ");
////
////        if(!p) break;
////        q[i++]=p;
////        p=NULL;
////    }
////    for(i=9;i>=0;i--){
////        if(q[i])
////        printf("%s ",q[i]);
////    }
////    return 0;
////}
//
////从键盘输入五个字符串，把这些字符串地址放入一个指针数组中，然后输入两个数n和m（n 和m是数组的下标，所以不要越界），把数组的下标n和下标m进行交换，并且打印数组中的字符串；
////比如：
////输入：
////I am Optimus Prime lucy
////0 1
////输出为
////am
////I
////Optimus
////Prime
////lucy
////输入：
////Hi welcome to qianfeng lilei
////2 3
////输出为
////Hi
////welcome
////qianfeng
////to
////lilei
////输入
////abc def ghi jkl heihei
////0 4
////输出为
////heihei
////def
////ghi
////jkl
////abc
//
////#include<stdio.h>
////#include<stdlib.h>
////#include<string.h>
////#define N 100
////int main(int argc,const char *argv[])
////{
//////    //补充 strcpy
//////    //char    *strcpy(char *, const char *);
//////    char str1[100]={};
//////    char str2[100]={};
//////    scanf("%s %s",str1,str2);
//////    strcpy(str1, str2);
//////    printf("%s\n",str1);
////////    asdfg d
////////    d
////////    sdfg dsfgfghjkl
//////    dsfgfghjkl
//////
////////    aaas aaas
////////    aaas
////
////
////
////    int i,cnt;
////    char*p[10]={};
////    for (i=0; i<10; i++) {
////        p[i]=(char*)malloc(N);
////        if (!p[i]) {
////            return -1;
////        }
////        scanf("%s",p[i]);
////        cnt++;
////        if (getchar()=='\n') {
////            break;
////        }
////    }
////    int n,m;
////    scanf("%d %d",&n,&m);
////    char*temp=(char*)malloc(N);
////    if (!temp) {
////        return -1;//必须给临时变量申请同样大的空间,才能保证不出现bug;;
////    }
////    strcpy(temp, p[n]);
////    strcpy(p[n], p[m]);
////    strcpy(p[m], temp);
////       for (int i=0; i<cnt; i++) {
////           if (p[i]) {
////               printf("%s\n",p[i]);
////               free(p[i]);
////               p[i]=NULL;
////           }
////    }
////    free(temp);
////    temp=NULL;
////
////    return 0;
////
////}
//
////int main(int argc,const char *argv[])
////
////{int cnt=0;
////    char *pstr[10]={};
////    for (int i=0; i<10; i++) {
////        pstr[i]=(char*)malloc(50);
////        scanf("%s",pstr[i]);
////        cnt++;
////        if (getchar()=='\n') {
////            break;
////        }
////    }
////    char substr[50]={};
////    int n,m;
////    scanf("%s %d %d",substr,&n ,&m);
////    for (int i=n; i<n+(m>cnt?cnt:m); i++) {
////        if (strcmp(substr, pstr[i])==0) {
////            free(pstr[i]);
////            pstr[i]=NULL;
////        }
////    }
////
////    for (int i=0; i<cnt; i++) {
////        if (pstr[i]) {
////            printf("%s\n",pstr[i]);
////        }
////    }
////
////    return 0;
////
////}
//
//
////字符串是常量,不能直接交换;语法没有错误,但逻辑有错误!!!!!!!!!|!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////int main(int argc,const char *argv[])
////
////{int cnt=0;
////    char *pstr[10]={};
////    for (int i=0; i<10; i++) {
////        pstr[i]=(char*)malloc(50);
////        scanf("%s",pstr[i]);
////        cnt++;
////        if (getchar()=='\n') {
////            break;
////        }
////    }
////
////    int n,m;
////    scanf("%d %d",&n ,&m);
////    for (int i=0; i<cnt; i++) {
////        char*temp=pstr[n];
////        pstr[n]=pstr[m];
////        pstr[m]=temp;//注意,这么做是不对的因为字符串是常量;不能直接交换;;;
////
////               }
////
////
////    for (int i=0; i<cnt; i++) {
////        if (pstr[i]) {
////            printf("%s\n",pstr[i]);
////        }
////    }
////
////    return 0;
////
////}
//
////在给定的任意字符串中查找指定字符，然后用新字符进行替换,
////满足条件的小写字符用新的小写字符替换，大写字符用新的大写字符替换，
////然后将替换后的字符串输出
////#$%^^@#$%^&#$%^&#$%@#$%#$%#$%%$%$
////
////比如：
////输入
////234ADWDGfwDW
////w
////m
////输出为
////234ADMDGfmDM
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    scanf("%[^\n]",str);
////    char ch1,ch2;
////    scanf("%c %c",&ch1,&ch2);
////    int len=(int)strlen(str);
////    char*p=str;
////    int i;
////
////    for (i=0; i<len; i++) {
////        if (p[i]==ch1) {
////            if(p[i]>='A'&&p[i]<='Z') p[i]=toupper(ch2);
////            else p[i]=tolower(ch2);
////
////        if (p[i]>='a') {
////
////        }
////        printf("%c",p[i]);
////        }
////
////
////
////        }
////
//
//
//
////输入一段字符串将单词升序排列
////比如：
////输入 come good goals bad bed
////输出：
////bad bed come goals good
////
////输入 I am Optimus Prime
////输出:
////I Optimus Prime am
//
//
////int main(int argc,const char*argv[])
////{
////    char*pstr[10]={};
////
////    char *temp={NULL};
////    int i,j,small;
////    for (i=0;i<10; i++) {
////
////        pstr[i]=(char*)malloc(20*sizeof(char));
////        scanf("%s",pstr[i]);
////
////    }
////    for (i=0; i<10; i++) {
////        small=i;
////        for (j=i+1; j<10; j++) {
////            if (strcmp(pstr[small], pstr[j])>0) {
////                temp=pstr[small];
////                pstr[small]=pstr[j];
////                pstr[j]=temp;
////            }
////        }
////    }
////    for (i=0; i<10; i++) {
////        printf("%s\n",pstr[i]);
////        free(pstr[i]) ;
////    }
////
////}
//
//
////输入一个IP地址，判断时候ip地址合法
////
////ip地址由4位0-255组成 中间使用 . 隔开
////合法的ip地址是:????????????????????????????????????###@@@@@@@@@@@@@@@@@@@@#########@@@@@@@@@@@@@@!!!!!!!!!!!!!!!!!!!!!!!!!
//
////int main(int argc,const char*argv[])
////{
////    char str[100]={};
////    scanf("%[^\n]",str);
////    char*p=str;
////    char *q[10]={};
////    int i=0;
////    while(1)
////    {
////        p=strtok(p,".");
////
////        if(!p) break;
////        q[i++]=p;
////        p=NULL;
////    }
////    for(i=0;i<=10;i++){
////        if(q[i]){
////            if (&q[i]<'255'&&&q[i]>'0') {
////                printf("不合法");break;
////            }
////            else printf("合法");break;
////        }
////    }
////    return 0;
////}
////@@@@@@@@@@@@@@@@@@@@@@@@@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$$$$$$$$$$$$$$$$$$$$
//
//
////int main(int argc,const char*argv[])
////{
////    char str[100]={};
////    scanf("%[^\n]",str);
////    char*p=str;
////    int q[10]={};
////    int i=0;
////    while(1)
////    {
////        p=strtok(p,".");
////
////        if(!p) break;
////        q[i++]=atoi(*p);
////        p=NULL;
////    }
////    for(i=0;i<=10;i++){
////        if(q[i]){
////            if (q[i]>255||q[i]<0) {
////                printf("不合法");break;
////            }
////            else printf("合法");break;
////        }
////    }
////    return 0;
////}
//
//
////在给定的任意字符串中查找指定的小写字符，将其删掉，然后将删除后的字符串输出
////
////
////比如：
////输入
////234ADWDGfwDW
////w
////输出为
////234ADWDGfDW
////
////输入
////772WdfWFDGWH3r
////d
////输出为
////772WfWFDGWH3r
//
////#include<stdio.h>
////#include<string.h>
////#include<stdlib.h>
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    char ch[10]={};
////    scanf("%s %s",str,ch);
////    char*p=str;
////    char*q[10]={};
////    int i=0;
////    while(1)
////            {
////               p=strtok(p,ch);
////
////                if(!p) break;
////               q[i]=p;
////                i++;
////                p=NULL;
////            }
////
////    for (i=0; i<10; i++) {
////        if(q[i])
////            printf("%s",q[i]);}
////
////    return 0;
////}
//
//
//
////在给定的任意字符串中查找指定的字符,不区分大小写，将其删掉，然后将删除后的字符串输出
////
////
////比如：
////输入
////234ADWDGfwDW
////d
////输出为
////88274WWT23ffw4
////
////输入
////772WdfWFDGWH3r
////d
////输出为
////772WfWFGWH3r
////#include<ctype.h>
////#include<stdio.h>
////#include<string.h>
////#include<stdlib.h>
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    char ch ,ch1;
////    scanf("%s %c",str,&ch);
////    char*p=str;
////    int i;
////
////    if (islower(ch))
////        ch1=toupper(ch);
////    else
////        if (isupper(ch)) {
////            ch1=tolower(ch);
////        }
////
////    while(*p)
////    {
////        char *pstr=strchr(str, ch);
////        int len=(int)(pstr-str+1);
////        for (i=len; i<strlen(str)+1; i++) {
////            *pstr=*(pstr+1);
////            pstr++;
////        }
////        str[strlen(str)]='\0';
////        p++;
////    }
////    char*p1=str;
////    while(*p1)
////    {
////        char *pstr=strchr(str,ch1);
////        int len=(int)(pstr-str+1);
////        for ( i=len; i<strlen(str)+1; i++) {
////            *pstr=*(pstr+1);
////            pstr++;
////        }
////        str[strlen(str)]='\0';
////        p1++;
////    }
////
////
////
////    printf("%s\n",str);
////
////    return 0;
////}
//
//
//
//
//
//
////在给定的任意字符串中查找指定的大写字符，将其删掉，然后将删除后的字符串输出
////
////
////比如：
////输入
////234ADWDGfwDW
////D
////输出为
////234ADDGfwD
////
////输入
////772WdfWFDGWH3r
////D
////输出为
////772WdfWFGWH3r
//
////#include<stdio.h>
////#include<string.h>
////#include<stdlib.h>
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    char ch[10]={};
////    scanf("%s %s",str,ch);
////    char*p=str;
////    char*q[10]={};
////    int i=0;
////    while(1)
////    {
////        p=strtok(p,ch);
////
////        if(!p) break;
////        q[i]=p;
////        i++;
////        p=NULL;
////    }
////
////    for (i=0; i<10; i++) {
////        if(q[i])
////            printf("%s",q[i]);}
////
////    return 0;
////}
//
//
////输入一个字符串，然后返回连续最大的字符串
////
////比如demo
////1,3,3,3,4,4,4,4,4,0,0,0,4,4,4,4
////，此例中由5个连续的4为最大连续子串，返回结果为44444.
////1,3,3,3,4,4,4,4,4,0,0,0,5,5,5,5 返回44444;
////1,3,3,3,5,5,5,5,5,4,4,4,4,4,0,0,0,0,0,0,4,4,4,4}，返回000000;
////
////这是公司OC面试题
//
//
////在给定的任意字符串中删除数字，然后将删除后的字符串输出
////
////
////比如：
////输入
////234ADWDGfwDW
////输出为
////ADWDGfwDW
////
////输入
////772WdfWFDGWH3r
////输出为
////WdfWFDGWHr
//
////#include<stdio.h>
////#include<string.h>
////#include<stdlib.h>
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    scanf("%s",str);
////    char *p=str;
////    while (*p) {
////        if (isdigit(*p)) {
////            char *pstr=strchr(str,*p);
////            int len=(int)(pstr-str);
////            for (int i=len; i<(int)strlen(str)+1; i++) {
////                *pstr=*(pstr+1);
////                pstr++;
////            }
////            str[strlen(str)]='\0';
////            }
////
////        else{
////            p++;
////        }
////    }
////
////    printf("%s",str);
////
////}
////将给定的字符串进行从小到大排序。将排序后的字符串输出，字符串内包含大小写字符。
////
////
////比如：
////输入
////adbAFEHHFS
////输出为
////AEFFHHSabd
////
////输入
////qfdgJKlin
////输出为
////JKdfgilnq
//
//
//
//
//
//
////输入一段字符串，把相同的字符按出现顺序，归在一起，并压缩
////比如：
////输入 SamSameCome
////输出：
////SSaammmeeCo
////S2a2m3e2C1o1
////
////输入 ComeTomeTCoe
////输出:
////CCooommeeeTT
////C2o3m2e3T2
//#if 0
//int main(int argc,const char *argv[])
//
//{ char str[100]={};
//
//    scanf("%s",str);
//    int len=(int)strlen(str);
//    for (int i=0; i<len; i++) {
//        char ch=str[i];
//        for (int j=i+1; j<len; j++) {
//            if (str[j]==str[i]) {
//                memmove(&str[i+1], &str[i], j-i);
//                str[i+1]=ch;
//                break;
//            }
//        }
//
//
//    }
//
//    printf("%s",str);
//}
//#endif
////输入两个字符串，然后不区分大小写进行比较，输出比较结果；
////要求实现一个字符串比较函数，不区分大小写进行比较，如果第一个字符串大输出1，相等输出0，小于输出-1。
////比如：
////输入 HELLO hello 输出为0
////输入 hello hello 输出为0
////输入 Hello hEllo 输出为0
////输入 hello gello 输出为1
////输入 hello jello 输出为-1
////????????????????????????!@$#%^&**^%$@#$%^&*&(*&^@!@#$^&*(^%$#))
////int mystrchr( char * str1,char *str2)
////
////{
////    char *p1=str1;
////    char*p2=str2;
////
////    while(*p1)
////    {tolower(*p1);
////        p1++;
////    }
////    while(*p2)
////    {tolower(*p2);
////        p2++;
////    }
////    while (*p1&&*p2) {
////              if (*p1==*p2) {
////                continue;        }
////               p1++;
////               p2++;
////           }
////    if(*p1>*p2) return 1;
////    else if (*p2<*p2) return-1;
////    else return 0;
////
////
////}
////
////int main(int argc,const char *argv[])
////
////{  char str1[100]={};
////        char str2[100]={};
////        scanf("%s %s",str1,str2);
////        printf("%d\n",mystrchr(str1,str2));
////
////        return 0;
////
////}
//
//
//
////输入两个字符串，以第二个字符串整体作为分割条件把第一个字符串进行分割,然后输出分割之后的单词。
////比如：
////输入：
////I:am:Optimus:Prime!
////:
////输出:
////I
////am
////Optimus
////Prime!
////输入：
////Hi#@welcome#@to#@qianfeng
////#@
////输出:
////Hi
////welcome
////to
////qianfeng
////提示
////没有提示
////输入
////I:am:Optimus:Prime!
////:
////输出
////I
////am
////Optimus
////Prime!
//
////输入一个以空格和逗号分隔的字符串，提取每个单词，并对单词进行从大到小排序，将排序后的结果输出。
////比如：
////输入：Where there is a will, there is a way
////输出：will way there there is is a a Where
//
//
//
////输入两个字符串,然后输入一个数字n和数字m，将第一个字符串抽取出从第n（从0开始）个开始数m个字符构成一个新的字符串并输出，然后把这个新的字符串插入到第二个字符串的第n（从0开始）个字符后输出（注意不要超过字符串范围）
////比如：
////12345 67890
////2 1
////输出为673890
////输入：
////12345 67890
////0 3
////输出为12367890
////输入:
////abcde xyz
////2
////3
////输出为xycdez
//
//
////输入一个字符串,再输入一个数字n，抽取出第n个到结尾的所有字符返回并打印（注意不要超过字符串范围）
////比如：
////输入：
////12345
////2
////输出为345
////输入：
////12345
////1
////输出为2345
////输入
////abcde
////4
////输出为e
//
////输入一个字符串,再输入一个数字n，抽取第0个到第n个之间的所有字符返回并打印（注意不要超过字符串范围）
////比如：
////输入：
////12345
////2
////输出为123
////输入：
////12345
////1
////输出为12
////输入
////abcde
////4
////输出为abcde
//
////输入两个字符串,查看第一个字符串是否以第二个字符串结尾，是返回1否则返回0
////比如：
////输入：
////12345 23
////输出为0
////输入：
////12345 45
////输出为1
////输入
////abcde e
////输出为1
//
////
////  main.c
////  字符串练习
////
////  Created by zhangxueming on 14-10-15.
////  Copyright (c) 2014年 zhangxueming. All rights reserved.
////
//
//#include <stdio.h>
////1.字符串排序。比较三个字符串的大小，然后按从小到大的顺序将字符串输出。
////比如：
////输入
////asdfwd
////ddrwf
////ffweff
////输出为
////asdfwd
////ddrwf
////ffweff
////
////输入
////sgfgeasdfw
////aabbe
////wrwwdfaf
////输出为
////aabbe
////sgfgeasdfw
////wrwwdfaf
//
//#include <stdlib.h>
//#include <string.h>
//#if 0
//int main(int argc, const char * argv[])
//{
//    char *pstr[10]={NULL};//定义一个指针数组
//    int cnt = 0;
//    for (int i=0; i<10; i++) {
//        pstr[i]=(char *)calloc(100, 1);//给每个数组元素开辟100个字节的内存空间,记住不要忘记前面的(char *)
//        if (!pstr[i]) {//判断是否开辟成功
//            return -1;
//        }
//        scanf("%s",pstr[i]);
//        cnt++;//用来统计输入的个数
//        if (getchar()=='\n') {  //输入水车表示输入结束
//            break;//跳出循环
//        }
//    }
//    for (int i=0; i<cnt-1; i++) {
//        for (int j=0; j<cnt-i-1; j++) {
//            if (strcmp(pstr[j], pstr[j+1])>0) {//使用strcmp函数
//                char *temp = pstr[j];//定义一个临时变量,注意数据结构类型必须匹配
//                pstr[j]=pstr[j+1];//冒泡排序
//                pstr[j+1]=temp;
//            }
//        }
//    }
//    for (int i=0; i<cnt; i++) {
//        printf("%s\n", pstr[i]);
//        free(pstr[i]);//释放申请的对内存空间,释放cnt次
//        pstr[i]=NULL;//赋值为空
//    }
//
//    return 0;
//}
//
//#endif
//
//
////2.
////查找一个字符在字符串1中第一次出现的字符位置，
////比如：
////输入
////asdfwd
////d
////输出为
////2
////
////输入
////hhff
////h
////输出为
////0
//#if 0
//int main(int argc,const char *argv[])
//{
//    char str[100];
//    char ch;
//    scanf("%s %c", str, &ch);
//    char *pstr = strchr(str, ch);//利用字符查找函数strchr pstr指向找到该字符的地址
//    printf("%lu\n", pstr-str);//高地址减地址就是该字符的在字符串中的位置
//    return 0;
//}
//#endif
//
////3.求一个字符串s的最大连续递增数字子串。
////
////
////比如：
////输入
////f123fffwf3210a1234
////输出为
////123
////
////输入
////abcd765bbw1357f12
////输出为
////123
//#include <ctype.h>
//#if 0
//int main(int argc,const char *argv[])
//{
//    char str[100];//定义一个字符数组
//    char *pstr = str;//定义一个指针指向str
//    char *pmax = NULL;//定义一个指针指向要输出的字串,并赋初值为空;
//    int maxlen=0;//定义一个临时变量,用于保存最大连续递增的个数
//    int cnt=0;//用于统计连续递增的数字字符个数
//    scanf("%s", str);
//    while (*pstr) //当pstr 不指向'\0'时开始循环;
//    {
//        if (isdigit(*pstr))  //判断字符是否为数字
//        {
//            cnt = 1; //是数字cnt 肯定为一个
//            while (*pstr == *(pstr+1)-1) {//判断当前字符比下一个字符小一
//                cnt++;  //个数加一
//                pstr++;//pstr指向下一个字符
//            }
//            pstr++;
//            if (maxlen < cnt) {//把最大的cnt给maxlen
//                maxlen = cnt;
//                pmax = pstr -cnt; //pmax指向该最大字符串的首地址
//                cnt = 0;//cnt 清零是为了保证下次计数的准确性
//            }
//        }
//        else//不是数字的话,指针指向下一个字符
//        {
//            pstr++;
//        }
//    }
//
//    if (pmax)//判断pmax是否存在,如果没有数字的话,就不会打印输出
//    {
//        *(pmax + maxlen)='\0';//字符串必须以\0结尾
//        printf("%s\n", pmax);//打印输出
//    }
//    return 0;
//}
//
//#endif
//
////字符串压缩算法，把输入的字符串压缩处理后的结果保存到第二个字符串中，并输出。
////比如：
////输入：aaaaaaaaaaaeefggg
////输出为：a11e2f1g3
////输入：eeeeeaaaff
////压缩为：e5a3f2
//#if 0
//int main(int argc,const char *argv[])
//{
//    char str[100];
//    char buf[100];//用于保存输出的字符串
//    scanf("%s", str);
//    char *pbuf = buf;//定义一个指针指向buf,可以动态的控制buf的输出内容
//    char *pstr = str;//定义一个指针指向str,可以动态的控制str的指向位置
//    char ch = *pstr;//定义一个字符,赋初值为第一个字符
//    int cnt = 0;//统计个数
//    int val=0;//控制输入几次
//    while (*pstr)
//    {
//        if (*pstr == ch)
//        {
//            cnt++;//
//        }
//        else
//        {
//            val = sprintf(pbuf, "%c%d",ch,cnt);//不等开始把统计好的字符及个数输入到buf缓冲区,返回值为输出的个数
//            pbuf+=val;//pbuf开始指向下一个地址,为下次输出做准备
//            cnt=0;//计数清零
//            ch = *pstr;//ch等于当前所指向的字符,为下次if判断做准备
//            pstr--;  //aaaeee,不进行减,当下次if判断会指向第二个e --后再++后才能保证不跳过一个字节
//        }
//        pstr++;
//    }
//    val = sprintf(pbuf, "%c%d", ch, cnt);//防止少打印
//    pbuf+=val;
//    *pbuf='\0';//结尾以\0
//    printf("%s\n", buf);
//    return 0;
//}
//#endif
//
////5.
//// 字符串解压缩算法，把输入字符串解压处理后结果保存在第二个字符串中，并输出。
//// 比如：
//// 输入：a11e2f1g3
//// 输出：aaaaaaaaaaaeefggg
//// 输入：e5a3f2
//// 输出：eeeeeaaaff
//
////char * str_write(char *pstr, char ch, int len)
////{
////    for (int i=0; i<len; i++) {
////        pstr[i]=ch;
////    }
////    pstr[len]='\0';//打印结束控制
////    return pstr;//返回char*类型
////}
////
////int main(int argc,const char *argv[])
////{
////    char str[100];
////    char buf[100];
////    scanf("%s", str);
////    char *pstr = str;
////    char *pbuf = buf;
////    char ch;
////    int len = 0;
////    while (*pstr)
////    {
////        ch = *pstr;
////        sscanf(pstr, "%c%d", &ch, &len);//读取字符到buf缓冲区,len等于读得个数;
////        str_write(pbuf, ch, len);//读完之后,调用自定义的打印函数
////        pbuf += len;//pbuf开始指向下一个字符,为下次打印做准备
////        pstr++;
////        while (isdigit(*pstr))//判断是否为数字,不是字符,是数字继续循环
////        {
////            pstr++;
////        }
////    }
//////    pbuf = buf;
//////    pstr = str;
//////    printf("%s\n", buf);
////    return 0;
////}
//
////返回在两字符串中第一个相同的子串(大于1个字符),并将子串输出
////
////
////比如：
////输入
////adbAFEHHFS
////acwfagAFEf
////输出为
////AFE
////
////输入
////qfdgJKlin
////qdfgJKwfo
////输出为
////gJK
//#if 0
//int main(int argc,const char *argv[])
//{
//    char str1[100]={};
//    char str2[100]={};
//    scanf("%s %s",str1,str2);
//    char *pstr=(char*)memmem(str1, 5, str2, 2);
//
//    printf("%s",pstr);
//
//
//}
//
//#endif
//
////#if 0
////#include <string.h>
////
//// int main(int argc,const char *argv[])
//// {
//// char str1[100]={};
//// char str2[100]={};
//// int i=0;
//// char *pstr1 = NULL;
//// char *pstr2 = NULL;
//// scanf("%s %s", str1,str2);
//// int len1 = (int)strlen(str1);
//// int len2 = (int)strlen(str2);
//// for (i=0; i<len2-1; i++) {
//// pstr1 = (char *)memmem(str1, len1, &str2[i], 2);
//// if (pstr1) {
//// break;
//// }
//// }
////     printf("pstr1=%s\n",pstr1);
////     printf("&str2[i]=%s\n",&str2[i]);
//// pstr2 = &str2[i];
////     printf("pstr2=%s\n",pstr2);
//// while (*pstr1 == *pstr2) {
//// pstr1++;
//// pstr2++;
//// }
//// *pstr2 = '\0';
//// printf("%s\n", &str2[i]);
//////     qewrtysdffedgaaaaaaaaaaaaffffffffffffffffdff hhhhhhhhaaaaaaaafffffkjhklj
//////     pstr1=aaaaaaaaaaaaffffffffffffffffdff
//////     &str2[i]=aaaaaaaafffffkjhklj
//////     pstr2=aaaaaaaafffffkjhklj
//////     aaaaaaaa
////
//// return 0;
//// }
////#endif
////输入一个字符串，然后再输入一个数字n，将这个字符串的第n个字符删除（从0开始数）;原来第n个字符后面的字符向前移(注意不要超过字符串的范围)
////比如：
////输入：
////hello
////2
////输出为helo
////输入：
////12345
////2
////输出为1245
////输入
////abcd
////0
////输出为bcd
//
////#include<ctype.h>
////#include<stdio.h>
////#include<string.h>
////#include<stdlib.h>
////int main(int argc,const char *argv[])
////{
////    char str[100]={};
////    int num;
////       scanf("%s %d",str,&num);
////    char*p=str;
////    int i;
////
////        for (i=num; i<(int)(strlen(str))+1; i++) {
////            *(p+num)=*(p+num+1);num++;
////        }
////
////    printf("%s\n",str);
////
////    return 0;
////}
//
//#if 0
//int main(int argc,const char *argv[])
//{
//    char str1[100]={};
//    char str2[100]={};
//    int index;
//    scanf("%s %s %d",str1,str2,&index);
//    int len1=(int)strlen(&str1[index]);
//    printf("&str1[index]=%s\n",&str1[index]);//字符串从哪里取地址打印就是后面的字串
//    printf("len1=%d\n",len1);
//    int len2=(int)strlen(str2);
//    printf("len2=%d\n",len2);
//    printf("&str1[index]+len2=%s\n",&str1[index]+len2);
//
//
//    memmove(&str1[index]+len2, &str1[index], len1);
//    str1[index+ len1+len2]='\0';
//    printf("&str1[index]=%s\n",&str1[index]);
//    printf("str1=%s\n",str1);
//    printf("str2=%s\n",str2);
//    printf("&str1[index]=%s\n",&str1[index]);
//    strncpy(&str1[index], str2, len2);
//    printf("&str1[index]=%s\n",&str1[index]);
//    printf("%s\n",str1);
//    return 0;
//
//    //    123456789 phone 3
//    //    &str1[index]=456789
//    //    len1=6
//    //    len2=5
//    //    &str1[index]+len2=9
//    //    &str1[index]=45678456789
//    //    str1=12345678456789
//    //    str2=phone
//    //    &str1[index]=45678456789
//    //    &str1[index]=phone456789
//    //    123phone456789
//
//
//}
//#endif
//
//
//
////void    *memmove(void *, const void *, size_t);
//
//#if  0
//int main(int argc,const char *argv[])
//{
//    char str1[100]={};
//    char str2[100]={};
//    scanf("%s %s",str1,str2);
//
//    char *p=memmove(str1, str2, 5);
//    printf("%s\n",p);
//    printf("%c\n",*p);
//    printf("%c\n",*p+1);
//    printf("%c\n",*p);
//    *(p+6)='\0';
//    printf("%s\n",p);
//    printf("%s\n",str1);
//    printf("%s\n",str2);
//
//    //memmove 会把rsc的size_t个字节复制到dest上,rsc字节不够加上\0一块复制
//
//    //    dgfhjkjfhjghkjfgh 12344566468
//    //    12344kjfhjghkjfgh
//    //    1
//    //    2
//    //    1
//    //    12344k
//    //    12344k
//    //    12344566468
//
//}
//#endif
//
//
//
////把一个数组的所有的0往后移动
////#define  nSize 7
////int* sort(int *a)
////{
////    for (int i=0; i<nSize; i++)
////    {
////        if (a[i]==0) {
////            for (int j=i+1; j<7; j++)
////            {
////                if (a[j]) {
////                    int temp=a[i];
////                    a[i]=a[j];
////                    a[j]=temp;
////                      break;//每次找到零就与相邻的下一个不是零的数字交换,而且只交换一次;
////                }
////
////            }
////
////
////        }
////
////    }
////
////    return a;
////}
////
////int main (int argc,const char *argv[])
////
////{
////
////    int a[nSize]={};
////    for (int i=0; i<nSize; i++) {
////        scanf("%d",&a[i]);
////    }
////    sort(a);
////    for (int i=0; i<7; i++) {
////        printf("%d ",a[i]);
////    }
////    return 0;
////
////}
////  17. 题目：输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。求所有子数组的和的最大值。
////    例如输入的数组为1 -2 3 10 -4 7 2 -5，和最大的子数组为3, 10, -4, 7, 2，因此输出为该子数组的和
//
////int MaxSum(int* a, int n)
////{
////    int nSum = 0;
////    int nValue=0;//定义一个临时变量,保存保存遍历的数值之和
////
////    for(int i = 0; i < n; i++)
////    {
////        if (nValue <= 0)
////            nValue = a[i];//
////        else
////            nValue += a[i];
////
////        if(nSum < nValue)
////            nSum = nValue;
////    }
////
////    return nSum;
////}
////
////int main(int argc, const char * argv[])
////{     int n=1;
////    scanf("%d",&n);//输入一个数字
////    int anAry[n];//数组可以可以直接引用n
////    for (int i=0; i<n; i++) {
////        scanf("%d",&anAry[i]);
////    }//输入 数组的元素的数值
////    printf("最大子数组之和:%d\n",MaxSum(anAry,n));
////
////    return 0;
////}
//
////输入两个字符串，然后再输入两个数字n 和 m，将第一个字符串从第n（从0开始数）个字符开始，数m个字符（包含第n个）替换为第二个字符串;(注意不要超过字符串的范围)
////比如：
////输入：
////12345 abcde
////1 2
////输出为1abcde45
////输入：
////12345 abcde
////0
////4
////输出为abcde5
////输入
////Iloveyou hate
////1
////4
////输出为Ihateyou
//
//#if 0
//int main(int argc,const char *argv[])
//{
//    char str1[100]={};
//    char str2[100]={};
//    int index;
//    scanf("%s %s %d",str1,str2,&index);
//    int len1=(int)strlen(&str1[index]);
//    printf("&str1[index]=%s\n",&str1[index]);//字符串从哪里取地址打印就是后面的字串
//    printf("len1=%d\n",len1);
//    int len2=(int)strlen(str2);
//    printf("len2=%d\n",len2);
//    printf("&str1[index]+len2=%s\n",&str1[index]+len2);
//
//
//    memmove(&str1[index]+len2, &str1[index], len1);
//    str1[index+ len1+len2]='\0';
//    printf("&str1[index]=%s\n",&str1[index]);
//    printf("str1=%s\n",str1);
//    printf("str2=%s\n",str2);
//    printf("&str1[index]=%s\n",&str1[index]);
//    strncpy(&str1[index], str2, len2);
//    printf("&str1[index]=%s\n",&str1[index]);
//    printf("%s\n",str1);
//    return 0;
//
//    //    123456789 phone 3
//    //    &str1[index]=456789
//    //    len1=6
//    //    len2=5
//    //    &str1[index]+len2=9
//    //    &str1[index]=45678456789
//    //    str1=12345678456789
//    //    str2=phone
//    //    &str1[index]=45678456789
//    //    &str1[index]=phone456789
//    //    123phone456789
//
//
//}
//#endif
//
//
//
////void    *memmove(void *, const void *, size_t);
//
//#if  0
//int main(int argc,const char *argv[])
//{
//    char str1[100]={};
//    char str2[100]={};
//    scanf("%s %s",str1,str2);
//
//    char *p=memmove(str1, str2, 5);
//    printf("%s\n",p);
//    printf("%c\n",*p);
//    printf("%c\n",*p+1);
//    printf("%c\n",*p);
//    *(p+6)='\0';
//    printf("%s\n",p);
//    printf("%s\n",str1);
//    printf("%s\n",str2);
//
//    //memmove 会把rsc的size_t个字节复制到dest上,rsc字节不够加上\0一块复制
//
//    //    dgfhjkjfhjghkjfgh 12344566468
//    //    12344kjfhjghkjfgh
//    //    1
//    //    2
//    //    1
//    //    12344k
//    //    12344k
//    //    12344566468
//
//}
//#endif
////从键盘输入个数不定的字符串（不超过10个），把这些字符串放入一个数组中，然后再输入一个字符串，输入两个数n和m（n 是数组的下标，m是从下标n开始数m个字符串），从下标n开始数m个字符串进行查找输入的最后一个字符串；找到之后，有几个就删除几个。后面没有被删除的字符串前移。（不要超过范围）
////比如：
////输入：
////I am Optimus Prime lucy
////am
////0 2
////输出为
////I Optimus Prime lucy
////输入：
////Hi welcome to to qianfeng lilei
////haha
////1 2
////输出为 Hi welcome to to qianfeng lilei
////输入
////abc ghi def ghi jkl heihei
////ghi
////1 3
////输出为 abc def jkl heihei
//
//int main(int argc,const char *argv[])
//{
//    int cnt =0;
//    char *pstr[10]={NULL};
//    for (int i=0; i<10; i++) {
//        pstr[i]=(char *)malloc(50);
//        scanf("%s",pstr[i]);
//        cnt++;
//        if (getchar()=='\n') {
//            break;
//        }
//    }
//    char substr[50]={};
//    int n,m;
//    scanf("%s %d %d",substr,&n,&m);
//
//    for (int i=n; i<n+(m>cnt?cnt:m); i++) {
//        if (strcmp(substr,pstr[i])==0) {
//            free(pstr[i]);
//            pstr[i]=NULL;
//        }
//    }
//    for (int i=0; i<cnt; i++) {
//        if(pstr[i])
//        {
//            printf("%s\n", pstr[i]);
//        }
//    }
//    return 0;
//}




#endif 
