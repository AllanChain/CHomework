#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char a[]="I love";
    char b[]=" what the hell.";
    char c[strlen(a)+strlen(b)];
    char *pa=a, *pb=b, *pc=c;

    while((*pc++=*pa++));
    pc--;
    while((*pc++=*pb++));

    printf("%s", c);
    return 0;
}
