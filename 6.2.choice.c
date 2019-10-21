#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[]={5,62,84,75,
        13,69,14,7,35,70};
    int p,min,t;

    for(int i=0;i<10-1;i++)
    {
        p=i;min=a[i];
        for(int j=i+1;j<10;j++)
            if(a[j]<min)
                p=j,min=a[j];
        if(p!=i){t=a[i];a[i]=min;a[p]=t;}
    }
    for(int i=0;i<10;i++)
        printf("%d ", a[i]);
    return 0;
}
