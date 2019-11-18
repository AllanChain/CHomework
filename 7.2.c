#include <stdio.h>
#include <math.h>

void pos(float a, float b, float t)
{
    printf("%f\n", (-b+sqrt(t))/(2*a));
    printf("%f\n", (-b-sqrt(t))/(2*a));
}
void zero(float a, float b)
{
    printf("%f\n", -b/(2*a));
}
void neg(float a, float b, float t)
{
    printf("%f%+fi\n", -b/(2*a), sqrt(-t)/(2*a));
    printf("%f%+fi\n", -b/(2*a),-sqrt(-t)/(2*a));
}
int main(void)
{
    float a,b,c,t;
    printf("Input a,b,c: ");
    scanf("%f,%f,%f", &a, &b, &c);
    t = b*b-4*a*c;
    if(t > 0) pos(a, b, t);
    else if(t == 0) zero(a, b);
    else neg(a, b, t);
    return 0;
}
