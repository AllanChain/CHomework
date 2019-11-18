#include <stdio.h>
#include <string.h>

/* int mystrcmp(const char *p1, const char *p2){ */
/*     while(*p1**p2 && *p1++==*p2++); */
/*     if(!(*p1**p2)) */
/*         return *p1-*p2; */
/*     return *--p1-*--p2; */
/* } */

void strsort(char *strs[10])
{
    char *t;
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(strcmp(strs[i],strs[j])>0){
                t=strs[i];
                strs[i]=strs[j];
                strs[j]=t;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    char strs[10][20], *p[10];
    for (int i = 0; i < 10; ++i){
        scanf("%s", strs[i]);
        p[i]=strs[i];
    }
    strsort(p);
    for (int i = 0; i < 10; ++i)
        printf("%s", p[i]);
    return 0;
}
