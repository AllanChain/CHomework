#include <stdio.h>
#include <malloc.h>

struct BigInt{
    int len;
    char *val;
};

struct BigInt* parse_big(char *a)
{
    char *p=a;
    int len;
    static struct BigInt x;
    while(*p++);
    p-=2;  //now p is the last char
    len = p-a+1;
    // add one for another digit if odd
    len = len%2==0?len/2:(len+1)/2;
    static char *xp=NULL;
    xp=(char*)malloc(100);
    x.val=xp; x.len=len;
    while(p>a){
        *xp++=(*p-'0')+(*(p-1)-'0')*10;
        p-=2;
    }
    if(p==a) *xp++=*p-'0';
    return &x;
}
void print_big(struct BigInt *x)
{
    for(int i=x->len-1; i>=0; i--)
        printf("%d ", *(x->val+i));
}

int main(void)
{
    char a[]="11256869";
    struct BigInt *b;
    b=parse_big(a);
    print_big(b);
    return 0;
}
