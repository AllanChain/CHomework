#include <stdio.h>
#include <malloc.h>

struct BigInt
{
    int len;
    char *val;
};
struct BigInt zero(){
    struct BigInt x;
    x.len=0;
    return x;
}
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
    if (a<100){
        x.len=1;
        x.val=(char*)malloc(1);
        *x.val=a;
    } else {
        x.len=2;
        x.val=(char*)malloc(2);
        *x.val=a%100;
        *(x.val+1)=a/100;
    }
    return x;
}
void print_big(struct BigInt x)
{
    if (x.len==0){
        printf("0");
        return;
    }
    // 0 is needed only in the later
    printf("%d", *(x.val + x.len -1));
    for (int i = x.len - 2; i >= 0; i--)
        printf("%02d", *(x.val + i));
    printf("\n");
}
char digit(struct BigInt a, int i)
{
    if (i<a.len) return *(a.val+i);
    else return 0;
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
struct BigInt add_big_shift(struct BigInt a, struct BigInt b, int n){
    struct BigInt x;
    short longer, t, toadd=0;
    if (a.len==0) return b;
    if (b.len==0) return a;
    x.len = a.len+n>b.len ? a.len+n : b.len;
    x.val = (char*)malloc(x.len+1);
    for (int i=0; i<n && b.len; i++){
        *(x.val+i) = *b.val++;
        b.len--;
    }
    longer  = a.len > b.len ? a.len : b.len;
    for (int i = 0; i<longer; i++){
        t=digit(a, i)+digit(b, i)+toadd;
        if(t>99) toadd=1, t-=100;
        else toadd=0;
        *(x.val+i+n)=t;
    }
    if (toadd)
        // longer x here
        *(x.val+x.len++)=toadd;
    // don't free a and b because P1 P2 P3 need more use
    return x;
}
struct BigInt add_big(struct BigInt a, struct BigInt b)
{
    return add_big_shift(a, b, 0);
}
struct BigInt sub_big(struct BigInt a, struct BigInt b)
{
    struct BigInt x, longer, shorter;
    short t, tosub=0;
    if (a.len==0) return zero();
    if (b.len==0) return a;
    x.len = a.len;
    x.val = (char*)malloc(x.len);
    for (int i = 0; i<a.len; i++){
        if(*(a.val+i) >= digit(b, i)+tosub){
            *(x.val+i)=*(a.val+i)-digit(b, i)-tosub;
            tosub=0;
        } else{
            *(x.val+i)=100+*(a.val+i)-digit(b, i)-tosub;
            tosub=1;
        }
    }
    for (int i=x.len-1; i>=0 && *(x.val+i)==0; i--) x.len--;
    return x;
}
struct BigInt mul_big(struct BigInt a, struct BigInt b)
{
    int maxlen, n;
    maxlen = a.len > b.len ? a.len : b.len;
    if (a.len==0 || b.len==0) return zero();
    if (maxlen==1) return int2big(*a.val**b.val);
    struct BigInt alow, ahigh, blow, bhigh;
    n=maxlen/2;
    divide_big(a, n, &alow, &ahigh);
    divide_big(b, n, &blow, &bhigh);
    struct BigInt P1, P2, P3, t;
    P1 = mul_big(ahigh, bhigh);
    P2 = mul_big(alow, blow);
    P3 = mul_big(add_big(alow, ahigh), add_big(blow, bhigh));
    t = add_big_shift(add_big_shift(P1, sub_big(sub_big(P3, P1), P2), n), P2, n);
    free(P1.val); free(P2.val); free(P3.val);
    return t;
}

int main(void)
{
    char a0[] = "1145758672366542";
    char b0[] = "864572343464298647";
    struct BigInt a, b, c, d;
    a = parse_big(a0);
    b = parse_big(b0);
    print_big(mul_big(a, b));
    return 0;
}
