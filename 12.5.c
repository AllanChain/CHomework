#include <stdio.h>

int main(void)
{
    short a=13;
    /* scanf("%d", &a); */
    if (a >> 15 & 1){
        printf("negtive, complement: 1");
        for(int i=12; i>=0; i-=3)
            printf("%o", a >> i & 7);
        printf("\n         true form:  1");
        a = ~(a - 1);
        for(int i=12; i>=0; i-=3)
            printf("%o", a >> i & 7);
    } else {
        printf("positive, true form & complement: 0");
        for(int i=12; i>=0; i-=3)
            printf("%o", a >> i & 7);
    }
    return 0;
}
