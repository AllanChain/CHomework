#include <stdio.h>

int main(int argc, char *argv[])
{
    int a1=1, a2=2, t;
    float s=0;
    for(int i=0; i<20; i++)
    {
        s+=(float)a2/(float)a1;
        t=a2;a2+=a1;a1=t;
        printf("%d\n", a1);
    }
    printf("%f\n", s);
    return 0;
}
