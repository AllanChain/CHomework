#include<stdio.h>

int main(int argc, char *argv[])
{
    float s=0;
    for(int k=1;k<=100;k++) s+=k;
    for(int k=1;k<=50;k++) s+=k*k;
    for(int k=1;k<=10;k++) s+=1.0/k;
    printf("%f", s);
    return 0;
}
