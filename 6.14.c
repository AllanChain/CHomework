#include <stdio.h>

int mystrcmp(const char *p1, const char *p2){
    while(*p1**p2 && *p1++==*p2++);
    if(!(*p1**p2))
        if(*p1>*p2) return 1;
        else if(*p1<*p2) return -1;
    return *--p1-*--p2;
}

int main(int argc, char *argv[])
{
    char s[]="And";
    printf("%d\n", mystrcmp(s, "Aid"));
    printf("%d\n", mystrcmp(s, "And"));
    printf("%d\n", mystrcmp("And", "Andr"));
    printf("%d\n", mystrcmp("And", "An"));
    printf("%d\n", mystrcmp("And", "Cid"));
    return 0;
}
