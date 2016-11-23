//
//  main.c
//  11.14
//
//  Created by 綦 on 16/11/14.
//  Copyright © 2016年 PowesunHolding. All rights reserved.
//

#include <stdio.h>

char * find_char(char const *source, char const *chars);
int main(int argc, const char * argv[]) {
    char source[] = "ABCDEF";
    char chars[] = "XAZ";
    
    char *ch = find_char(source, chars);
    if (ch) {
        printf("%c\n", *ch);
    }
    
    return 0;
}

char * find_char(char const *source, char const *chars)
{
    for (char const *ch = source; *ch != '\0'; ch++) {
        for (char const *findChar = chars; *findChar != '\0'; findChar++) {
            if (*ch == *findChar) {
                return (char *)ch;
            }
        }
    }
    
    return NULL;
}