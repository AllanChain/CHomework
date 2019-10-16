#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[])
{
    int v[4];
    for(int i=0, *p=v;i<4;i++,p++)
    {
        printf("%s", "Input: ");
        scanf("%d", p);
    }
    qsort(v, 4, sizeof(int), cmp);
    for(int i=0, *p=v;i<4;i++,p++) printf("%d\n", *p);
    return 0;
}
