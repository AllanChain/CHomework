#include <stdio.h>
#include <malloc.h>

struct BigInt
{
    int len;
    char *val;
};

struct BigInt parse_big(char *a)
{
    char *p = a;
    int len;
    struct BigInt x;
    while (*p++)
        ;
    p -= 2; //now p is the last char
    len = p - a + 1;
    // add one for another digit if odd
    len = len % 2 == 0 ? len / 2 : (len + 1) / 2;
    char *xp = (char *)malloc(len);
    x.val = xp;
    x.len = len;
    while (p > a)
    {
        *xp++ = (*p - '0') + (*(p - 1) - '0') * 10;
        p -= 2;
    }
    if (p == a)
        *xp++ = *p - '0';
    return x;
}
struct BigInt int2big(int a)
{
    struct BigInt x;
    x.len=1;
    x.val=(char*)malloc(1);
    *x.val=a;
    return x;
}
void print_big(struct BigInt x)
{
    for (int i = x.len - 1; i >= 0; i--)
        printf("%d", *(x.val + i));
    printf("\n");
}

void divide_big(struct BigInt x, int i,
                struct BigInt *xlow, struct BigInt *xhigh)
{
    if (i>=x.len){
        xlow->len = 0;
        xhigh->len = x.len;
    }else{
        xlow->len = x.len - i;
        xhigh->len = i;
    }
    xlow->val = x.val;
    xhigh->val = x.val + x.len - xhigh->len;
}
struct BigInt add_big_shift(struct BigInt a, struct BigInt b, int n){
    struct BigInt x, longer, shorter;
    short t, toadd=0;
    x.len = a.len+n>b.len ? a.len+n : b.len;
    x.val = (char*)malloc(x.len+1);
    for (int i=0; i<n && b.len; i++){
        *(x.val+i) = *b.val++;
        b.len--;
    }
    longer  = a.len > b.len ? a : b;
    shorter = a.len > b.len ? b : a;
    for (int i = 0; i<shorter.len; i++){
        t=*(a.val+i)+*(b.val+i)+toadd;
        if(t>99) toadd=1, t-=100;
        else toadd=0;
        *(x.val+i+n)=t;
    }
    // incase it need `jin wei`
    // and optimise a little
    for (int i = shorter.len; i<longer.len; i++){
        if (toadd){
            if(*(longer.val+i)==99) *(x.val+i+n)=0;
            else *(x.val+i+n)=*(longer.val+i)+toadd--;
        }
        else *(x.val+i+n)=*(longer.val+i);
    }
    if (toadd)
        // longer x here
        *(x.val+x.len++)=toadd;
    // free a and b?
    return x;
}
struct BigInt add_big(struct BigInt a, struct BigInt b)
{
    return add_big_shift(a, b, 0);
}
struct BigInt mul_big(struct BigInt a, struct BigInt b)
{
    int maxlen, n;
    maxlen = a.len > b.len ? a.len : b.len;
    if (maxlen==1) return int2big(*a.val**b.val);
    struct BigInt alow, ahigh, blow, bhigh;
    n=maxlen/2;
    divide_big(a, n, &alow, &ahigh);
    divide_big(b, n, &blow, &bhigh);
    struct BigInt P1, P2, P3;
    P1 = mul_big(ahigh, bhigh);
    P2 = mul_big(alow, blow);
    P3 = mul_big(add_big(alow, ahigh), add_big(blow, bhigh));
    return P1;
}

int main(void)
{
    char a0[] = "1156869";
    char b0[] = "123456869";
    struct BigInt a, b, c, d;
    a = parse_big(a0);
    b = parse_big(b0);
    print_big(a);
    print_big(b);
    print_big(add_big_shift(a, b, 1));
    divide_big(b, 2, &c, &d);
    print_big(c);
    print_big(d);
    return 0;
}
