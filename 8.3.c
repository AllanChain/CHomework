#include <stdio.h>

void input(int *a)
{
    for(int i=0; i<10; i++)
        scanf("%d", a++);
}

void print(int *a)
{
    for(int i=0; i<10; i++)
        printf("%d ", *a++);
}

void parse(int *a)
{
    int max=*a, maxi=0;
    int min=*a, mini=0;
    for(int i=0; i<10; i++)
    {
        if(a[i]>max)
            max=a[i], maxi=i;
        else if(a[i]<min)
            min=a[i], mini=i;
    }
    // a little tricky here
    // cover 0 and 9 later
    a[maxi]=a[9]; a[mini]=a[0];
    a[0]=min; a[9]=max;
}

int main(void)
{
    int a[10];
    input(a); parse(a); print(a);
    return 0;
}
