//
//  main.c
//  Practice02
//
//  Created by 綦 on 16/11/14.
//  Copyright © 2016年 PowesunHolding. All rights reserved.
//

#include <stdio.h>

int del_substr(char *str, char const *subStr);
int main(int argc, const char * argv[]) {
    char source[] = "ABCDEFG";
    char chars[] = "CDE";
    
    if (del_substr(source, chars)) {
        printf("%s\n", source);
    }
    
    return 0;
}

int del_substr(char *str, char const *subStr)
{
    if (!subStr) {
        return 1;
    }
    if (!str) {
        return 0;
    }
    
    for (char *ch = str; *ch != '\0'; ch++) {
        if (*ch == *subStr) {
            int isSub = 1;
            int lenth = 1;
            for (char const *subCh = subStr + 1; *subCh != '\0'; subCh++) {
                if (*(ch + (subCh - subStr)) != *subCh) {
                    isSub = 0;
                    break;
                }
                
                lenth++;
            }
            
            if (isSub) {
                for (char *insertCh = ch + lenth; *insertCh != '\0' || *ch != '\0'; ch++) {
                    if (*insertCh != '\0') {
                        *ch = *insertCh;
                        *insertCh = '\0';
                        insertCh++;
                    }
                    else
                    {
                        *ch = '\n';
                    }
                }
                
                return 1;
            }
        }
    }
    
    return 0;
}
