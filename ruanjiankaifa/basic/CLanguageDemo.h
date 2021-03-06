//
//  CLanguageDemo.h
//  C 语言常见编程练习
//  旨在学习过程式编程思想
//

#ifndef CLanguageDemo_h
#define CLanguageDemo_h

#include <stdio.h>


/*
 输出数字序列2/1，3/2，5/3，8/5，13/8，21/13...，输出个数由键盘输入。注意输入使用scanf输入
\
比如：

输入 3输出为

2/1
3/2
5/3

输入 4 输出为
2/1
3/2
5/3
8/5
int a=1,b=1;
a=2,b=1
a=3,b=2
a=5,b=3
a=8,b=5
*/
//变相考察斐波那契数列，输入输出
void Faibonaqi(void);


//斐波那契数列
//1 1 2 3 5 8 13 21 34 55 89 144 ....
//递归
void Faibonaqi2(void);



/*
 for求阶乘的和 ）    输入n(int类型)，打印1！+2！+3！+4！+5！+。。。+n!的值
 //比如：
 //
 //输入：2
 //输出：
 //3
 //
 //输入：3
 //
 //输出:
 //9
 //6! = 6*5! = 6*5*4!;
 
 //temp =1
 //temp =2!=2*temp
 //temp =3!=3*temp
 //temp =4!=4*temp
 
 
 */

void jiecheng(void);


/*
输出数字序列 1，2，3，5，8，13，21...，输出个数由键盘输入。注意输入使用scanf输入
//\
//比如：
//\
//输入 3输出为
//
//1
//2
//3
//
//输入 4 输出为
//1
//2
//3
//5
// a=1,b=0    1
// a=1,b=1    2
// a=2,b=1    3
// a=3,b=2    5
// a=5,b=3    8
*/

//数列前两项之和为第三项
//思路：不使用数组的情况下，采用临时变量
void a1PlusA2toA3(void);

// 输入一个大写字母，如F
//\
//比如：
//\
//输入:F
//\
//输出：
//
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
//ABCDEFEDCBA
void JinZiTa(void);


//for循环）    输入一个大写字母，如 F，输出
//\
//比如：
//\
//输入：F
//\
//输出：
//     F
//    EFE
//   DEFED
//  CDEFEDC
// BCDEFEDCB
//ABCDEFEDCBA
void JinZiTa2(void);

//（for循环)输入一个大写字符，如F
//\
//比如：
//
//输入:F
//
//输出：
//
//FEDCBA
// EDCBAB
//  DCBABC
//   CBABCD
//    BABCDE
//     ABCDEF
void JinZiTa3(void);


//输入一个大写字母，如F
//比如：
//输入:F
//输出：
//A
//ABA
//ABCBA
//ABCDCBA
//ABCDEDCBA
//ABCDEFEDCBA
//
//输入:C
//输出:
//A
//ABA
//ABCBA

void JinZiTa4(void);







#endif 
