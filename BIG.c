#include <stdio.h>

void printrn(char a[])
{
    char *pa=a+199;
    while(pa>=a && *pa--==0);
    pa++; //for test
    while(pa>=a) putchar(*pa--+48); //printf("%d",*pa--);
    putchar('\n');
}
void add(char *a, char *b, char *c)
{
    short toadd=0, t=0, terms=0;
    while(terms<2)
    {
        if(*a==255) terms+=1, *a=0;
        if(*b==255) terms+=1, *b=0;
        t=*a+*b+toadd;
        if(t>9) toadd=1, t-=10;
        else toadd=0;
        *c++=t; a++; b++;
    }
    *c=255;
}
void mul(char *a, char *b, char *c)
{
    int toadd=0, t;
    char p[201]="";
    int ia=0,ib=0,ip=0;
    while(a[ia]!=255)
    {
        ip=0;
        for(int j=0;j<201;j++) 
            p[j]=0;
        ip=ia; //start from ia
        ib=0;
        while(b[ib]!=255)
        {
            t=a[ia]*b[ib++]+toadd;
            toadd=t/10;
            p[ip++]=t%10;
        }
        p[ip]=toadd; p[ip+1]=255;
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
    *b=255; //terminator
}
int main(void)
{
    char input1[200]="11119";
    char input2[200]="256";
    char a[200]="", b[200]="";
    char c[400]="";
    c[1]=255;  //mark term
    /* scanf("%s", input1); */
    /* scanf("%s", input2); */
    reverse(input1, a);
    printrn(a);
    reverse(input2, b);
    printrn(b);
    mul(a, b, c);
    printrn(c);
    return 0;
}
