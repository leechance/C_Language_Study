//
//  Faceoffer.c
//  ruanjiankaifa
//
//  Created by 李春桂 on 2018/12/4.
//  Copyright © 2018 chance. All rights reserved.
//

#include "Faceoffer.h"
#include <math.h>
void dataWidthForBigNum(void){
    long int n;
    long int i;
    double sum;
    
    while(scanf("%ld", &n)!=EOF)
    {
        sum=0.0;
        for(i=2; i<=n; i++)
        {
            sum+=log2(i);
        }
        printf("%ld\n", (int)sum+1 );
    }
    
}
