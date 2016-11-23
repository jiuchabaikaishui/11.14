//
//  main.c
//  Practice03
//
//  Created by 綦 on 16/11/21.
//  Copyright © 2016年 PowesunHolding. All rights reserved.
//

#include <stdio.h>

void reverse_string(char *string);
int main(int argc, const char * argv[]) {
    char string[1000];
    printf("请输入一个字符串：\n");
    scanf("%s", string);
    reverse_string(string);
    printf("%s\n", string);
    
    return 0;
}

void reverse_string(char *string)
{
    int lenth = 0;
    for (char *ch = string; *ch != '\0'; ch++) {
        lenth++;
    }
    
    char exchangCh;
    for (char *ch = string; ch < string + lenth/2; ch++) {
        exchangCh = *ch;
        *ch = *(string + (string + lenth - ch - 1));
        *(string + (string + lenth - ch - 1)) = exchangCh;
    }
}
