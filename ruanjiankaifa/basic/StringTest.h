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


/*
 1）字符的运算
 int dd= 'c'-'a'; dd的值是2
 char c= 'a'+2; ;  c的值为 ’c‘
  0和’0‘的转化
  int num= '0'-48; num的值为0
 
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

//统计输入字符数
int countInputCharNumber(void);


 
#endif 
