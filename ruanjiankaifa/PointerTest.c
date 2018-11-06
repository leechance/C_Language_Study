//
//  PointerTest.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/6.
//  Copyright © 2018 chance. All rights reserved.
//

#include "PointerTest.h"

void pointerBasicTest(void){
    //变量地址
    int a=50;
    printf("%p\n",&a);
    
    //间接寻址
    int b;
    int *p=&b;
    *p=100;
    printf("%d %d\n",*p,b);
    
    //*p ++ 也就是 b++,先赋值给k 然后b(糊涂)
    int k=*p++;
    printf("%d %d\n",k,*p);
    
    //打印指针地址
    int c=1000;
    int *q=&c;
    printf("%p\n",q);
    
    //指针 直接寻址,前提确定改地址可以访问,否则极容易崩溃
    //*(int *)( 0x7ffeefbff518)=8888;
    
    //求字节数 64位系统指针变量,在内存占用8个字节;
    printf("%ld\n", sizeof(q));
    char ch1='A';
    char *ch=&ch1;
    printf("%ld\n", sizeof(ch));
    printf("%ld\n",sizeof(int *));
    printf("% ld\n",sizeof(char *));
    printf("%ld\n",sizeof(long*));
    
    
    //指针和数组
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int (*p1)[10]=&arr;
    printf("%p %p\n",p1,p1+1);
    
    
    int *pa=arr;
    printf("%p\n",arr);
    printf("%p %p %d\n",pa,&pa ,*pa);//0x7fff5fbff8b0 0x7fff5fbff8d8 0x7fff5fbff8b0
    pa++;
    printf("%p  %p\n",pa,&arr[1]);
    printf("%p %p\n",pa+1,&arr[2]);
}
