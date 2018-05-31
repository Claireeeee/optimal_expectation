//
//  main.c
//  算法实验2
//
//  Created by claire on 2018/5/30.
//  Copyright © 2018年 claire. All rights reserved.
//

#include <stdio.h>


float recur(int n,float *temp);
float recur(int n,float *temp){
    if (n==1||n==0) {
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else {
        float result=n;
        for (int i=1;i<n;i++) {
            float b;
            if (i==1) {
                b=1+(float)(n-1)/n*(float)temp[n-2];
                printf("n=%d,i=%d,b=%f\n",n,i,b);
            }
            else if (i==2) {
                b=1+(float)2/n+(float)(n-2)/n*(float)temp[n-3];
                printf("n=%d,i=%d,b=%f\n",n,i,b);
            }
            else {
                b=1+(float)((i)*(i-1)+2*(i-1))/(2*n)+(float)(n-i)/n*(float)temp[n-i-1];
                printf("n=%d,i=%d,b=%f\n",n,i,b);
            }
                if (b<=result) {
                    //printf("%f   ",b);
                    result=b;
                }
            
        }
        printf("\nresult:%f\n",result);
        return result;
    }
}
int main(void) {
    
    float temp[32];
    temp[0]=0;
    temp[1]=1;
    for (int c=3; c<=32; c++) {
        temp[c-1]=recur(c,temp);
    }
    printf("\n%f",temp[31]);


}
