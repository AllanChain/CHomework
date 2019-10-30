#include <stdio.h>
#define TERM 127

/* 
If you define terminator as 255,
Then in some system, after converting to int,
it will be 255, but some will be -1.
So 127 seems to be a good option.
*/
void putrn(char *p)
{
    if(*p==TERM) return;
    putrn(p+1);
    putchar(*p+'0');
}
void add(char *a, char *b, char *c)
{
    short toadd=0, t=0, terms=0;
    while(terms<2)
    {
        if(*a==TERM) terms+=1, *a=0;
        if(*b==TERM) terms+=1, *b=0;
        t=*a+*b+toadd;
        if(t>9) toadd=1, t-=10;
        else toadd=0;
        *c++=t; a++; b++;
    }
    *c=TERM;
}
void mul(char *a, char *b, char *c)
{
    int toadd=0, t;
    char p[201]="";
    int ia=0,ib=0,ip=0;
    printf("%d", ib);
    while(a[ia]!=TERM)
    {
        ip=0;
        for(int j=0;j<201;j++) 
            p[j]=0;
        ip=ia; //start from ia
        ib=0;
        while(b[ib]!=TERM)
        {
            t=a[ia]*b[ib++]+toadd;
            toadd=t/10;
            p[ip++]=t%10;
        }
        p[ip]=toadd; p[ip+1]=TERM;
        toadd=0; ia++;
        add(p, c, c);
    }
}
void reverse(char a[], char b[])
{
    char *pa=a+199;
    while(*pa--==0);
    pa++;
    while(pa>=a) *b++=*pa---48;
    *b=TERM; //terminator
}
int main(void)
{
    char input1[200]="11119";
    char input2[200]="256";
    /* A little more for terminators */
    char a[201]="", b[201]="";
    char c[401]="";
    c[1]=TERM;
    /* scanf("%s", input1); */
    /* scanf("%s", input2); */
    reverse(input1, a);
    putrn(a); printf("\n");
    reverse(input2, b);
    putrn(b); printf("\n");
    mul(a, b, c);
    putrn(c); printf("\n");
    return 0;
}
