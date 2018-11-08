//
//  StaticTest.c
//  ruanjiankaifa
//
//  Created by chance on 2018/11/8.
//  Copyright © 2018 chance. All rights reserved.
//

#include "StaticTest.h"
//static int val=50;
void printTest(void)
{
    static int a=100;
    a++;
    printf("%d\n",a);
    
    return;
    
}
