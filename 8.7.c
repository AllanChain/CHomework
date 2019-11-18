#include <stdio.h>

void copy_from_m(char *src, char *dest, int m)
{
    src += m;
    while((*dest++=*src++));
}

int main(void)
{
    char a[]="Hello Tsinghua University!";
    char b[40];

    copy_from_m(a, b, 6);
    printf("%s", b);
    return 0;
}
