#include <stdio.h>

int main(void)
{
    short a=13, helper=1, result=0;

    a = a >> 1;
    for(int i=1; i<16; i+=2){
        result += a & helper;
        a = a >> 1; helper = helper << 1;
    }
    printf("%o", result);
    return 0;
}
