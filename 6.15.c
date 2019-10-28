#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char s2[100]="I say PhenylKetonUria.";
    int len=strlen(s2);
    char s1[len];
    char *p1=s1, *p2=s2;
    while((*p1++=*p2++));
    printf(s1);
    return 0;
}
