#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float xn, xn1, a;
    printf("Input a: ");
    scanf("%f", &a);
    xn = a;
    while(fabs(xn-(xn1=(xn+a/xn)/2))>=1e-5) xn=xn1;
    printf("%f", xn);
    return 0;
}
