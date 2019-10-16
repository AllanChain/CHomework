/* calculating 1!+ ... + 20! */
#include <stdio.h>

int main(int argc, char *argv[])
{
    long s, m;
    for(int i=1; i<=20; i++)
    {
        m=1;
        for (int j=1; j<=i; j++) m*=j;
        printf("%ld\n", s);
        s+=m;
    }
    printf("%ld", s);
    return 0;
}
