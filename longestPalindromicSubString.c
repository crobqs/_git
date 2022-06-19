#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindromicSubString(const char *str) {
    char *s = (char*)calloc(strlen(str)+1,sizeof(char));
    memcpy(s,str,strlen(str));
    char *start, *end;
    char *p=s, *subStart=s;
    int maxLen=1;
    while(*p) {
        start=end=p;
        while(*(end+1) && *(end+1)==*(end)) { ++end; }
        p=end+1;
        while(*(end+1) && (start>s) && *(end+1)==*(start-1)) { --start,++end; }
        if(end-start+1 > maxLen) {
            maxLen=end-start+1;
            subStart=start;
        }
    }
    char *rst=(char*)calloc(maxLen+1,sizeof(char));
    memcpy(rst,subStart,maxLen);
    free(s);
    return rst;
}

#if 1
int main(int argc, char **argv) {
    char *(*fp)(const char*) = longestPalindromicSubString;
    char *s;

    puts(s=fp("~aba")), free(s);
    puts(s=fp("abba.")), free(s);
    puts(s=fp("noty")), free(s);
}
#endif