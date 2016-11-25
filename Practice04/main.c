//
//  main.c
//  Practice04
//
//  Created by 綦 on 16/11/21.
//  Copyright © 2016年 PowesunHolding. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int isZhishu(long int num)
{
    if (num == 0 || num == 1) {
        return 0;
    }
    for (long int i = 2; i <= sqrtf(num); i++) {
        if (num%i == 0) {
            return 0;
        }
    }
    
    return 1;
}
long int totalZhishu(long int length, char *arr)
{
    long int count = 0;
    for (long int i = 0; i < length; i++) {
        if (i == 0 || i == 1) {
            *(arr + i) = 0;
        }
        else
        {
            *(arr + i) = 1;
            count++;
        }
    }
    
    for (long int i = 2; i < length; i++) {
        if (isZhishu(i)) {
            for (long int j = 2*i; j < length; j += i) {
                if (*(arr + j) == 1) {
                    *(arr + j) = 0;
                    count--;
                }
            }
        }
    }
    
    return count;
}
int main(int argc, const char * argv[]) {
    printf("请输入一个正整数：\n");
    long int length = 0;
    scanf("%li", &length);
    
    for (long int spacing = 1000; spacing < length; spacing += 1000) {
        char arr[spacing];
        char arr1[spacing - 1000];
        printf("%li\n", totalZhishu(spacing, arr) - totalZhishu(spacing - 1000, arr1));
    }
    
//    char arr[length];
//    
//    long int count = totalZhishu(length, arr);
//    
//    for (long int i = 0; i < length; i++) {
//        if (*(arr + i) == 1) {
//            printf("%li ", i);
//        }
//    }
//    printf("\n");
//    printf("%li\n", count);
    
    return 0;
}
