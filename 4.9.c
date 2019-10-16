#include <stdio.h>

int main() {
    int a=1254, i=0;
    do {
        printf("%d", a % 10);
        i++;
    } while ((a/=10) > 0);
    printf("\n%d",i);
}
