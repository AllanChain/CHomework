#include <stdio.h>
#include <malloc.h>

struct BigInt
{
    int len;
    char *val;
};

void parse_big(char *a, struct BigInt *x)
{
    char *p = a;
    int len;
    while (*p++)
        ;
    p -= 2; //now p is the last char
    len = p - a + 1;
    // add one for another digit if odd
    len = len % 2 == 0 ? len / 2 : (len + 1) / 2;
    char *xp = (char *)malloc(len);
    x->val = xp;
    x->len = len;
    while (p > a)
    {
        *xp++ = (*p - '0') + (*(p - 1) - '0') * 10;
        p -= 2;
    }
    if (p == a)
        *xp++ = *p - '0';
}
void print_big(struct BigInt x)
{
    for (int i = x.len - 1; i >= 0; i--)
        printf("%d", *(x.val + i));
    printf("\n");
}

/* dividing x to xlow (lowest `0` to higher i digit exclusive)[len=i]
   and xhigh (i th inclusive to the highest `len`)[len=x.len-i] */
void divide_big(struct BigInt x, int i,
                struct BigInt *xlow, struct BigInt *xhigh)
{
    xlow->len = i;
    xhigh->len = x.len - i;
    xlow->val = x.val;
    xhigh->val = x.val + i;
}
int main(void)
{
    char a[] = "11256869";
    struct BigInt b, c, d;
    parse_big(a, &b);
    print_big(b);
    divide_big(b, 2, &c, &d);
    print_big(c);
    print_big(d);
    return 0;
}
