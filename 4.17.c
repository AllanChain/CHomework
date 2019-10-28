#include <stdio.h>

void s2i(int a, char* p)
{
    *p=a%10+48;
    if(a>=10)
        s2i(a/10,++p);
    return;
}
void str2int(int a)
{
    char out[10];
    char *p=out;
    s2i(a, p);
    int i=9;
    while((out[i--])==48);
    for(i=9;i>0;i--)
        printf("%c", out[i]);
}
int main(void)
{
    int a=20075058;
    str2int(a);
    return 0;
}
