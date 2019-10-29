#include <stdio.h>

int i2s(int a, char s[])
{
    int i=0;
    if(a>10) i=i2s(a/10, s);
    s[i++]=a%10+'0';
    return i;
}
int main()
{
    char s[10]="";
    int a=12705;
    i2s(a, s);
    printf("%s", s);
    return 0;
}
