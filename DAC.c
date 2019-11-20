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
void print_big(struct BigInt x)
{
    for (int i = x.len - 1; i >= 0; i--)
        printf("%d", *(x.val + i));
    printf("\n");
}

/* dividing x to xlow (lowest `0` to higher i digit exclusive)[len=i]
   and xhigh (i th inclusive to the highest `len`)[len=x.len-i]
   But... is it okay if one of them is empty? or i larger than x.len? */
void divide_big(struct BigInt x, int i,
                struct BigInt *xlow, struct BigInt *xhigh)
{
    if (i>=x.len){
        xlow->len = x.len;
        xhigh->len = 0;
    }else{
        xlow->len = i;
        xhigh->len = x.len - i;
    }
    xlow->val = x.val;
    xhigh->val = x.val + i;
}
struct BigInt add_big(struct BigInt a, struct BigInt b)
{
    struct BigInt x, longer, shorter;
    short t, toadd=0;
    longer  = a.len > b.len ? a : b;
    shorter = a.len > b.len ? b : a;
    // x.len may be added by 1 if needed
    x.len = longer.len;
    // In case it need one more digit
    x.val = (char*)malloc(x.len+1);
    for (int i = 0; i<shorter.len; i++){
        t=*(a.val+i)+*(b.val+i)+toadd;
        if(t>99) toadd=1, t-=100;
        else toadd=0;
        *(x.val+i)=t;
    }
    // incase it need `jin wei`
    // and optimise a little
    for (int i = shorter.len; i<longer.len; i++){
        if (toadd){
            if(*(a.val+i)==99) *(x.val+i)=0;
            else *(x.val+i)=*(a.val+i)+toadd--;
        }
        else *(x.val+i)=*(a.val+i);
    }
    if (toadd)
        // longer x here
        *(x.val+x.len++)=toadd;
    return x;
}

int main(void)
{
    char a0[] = "1156869";
    char b0[] = "56869";
    struct BigInt a, b, c, d;
    a = parse_big(a0);
    b = parse_big(b0);
    print_big(a);
    print_big(b);
    print_big(add_big(a, b));
    /* divide_big(b, 5, &c, &d); */
    /* print_big(c); */
    /* print_big(d); */
    return 0;
}
