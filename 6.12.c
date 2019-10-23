#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char ch;
    char s[]="R hzb dszg gsv svoo";
    int len = strlen(s);
    char m[len+1];
    m[len]='\0';
    for (int i = 0; i < len; ++i) {
        ch=s[i];
        if('A'<=ch && ch<='Z') m[i]='A'+'Z'-ch;
        else if('a'<=ch && ch<='z') m[i]='a'+'z'-ch;
        else m[i]=ch;
    }
    printf(m);
    return 0;
}
