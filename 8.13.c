#include <stdio.h>
#include <math.h>

double integrate(double (*f)(double)){
    double sum=0, del=0.00001;
    for (double i=0;i<1;i+=del){
        sum += (*f)(i);
    }
    return sum*del;
}
int main(void)
{
    printf("sin: %lf\n", integrate(sin));
    printf("cos: %lf\n", integrate(cos));
    printf("exp: %lf\n", integrate(exp));
    return 0;
}
