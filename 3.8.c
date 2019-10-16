#include <stdio.h>

int main(int argc, char *argv[])
{
    /* char c1, c2; */
    int c1, c2, c3; // 中文三个字节。。
    c1 = getchar();
    c2 = getchar();
    c3 = getchar();
    /* putchar(c1); */
    /* putchar(c1*256+c2); */
    /* putchar(c2); */
    /* putchar(c1*256+c2); */
    putchar(c1);
    putchar(c2);
    putchar(c3);
    printf("\n%d %d", c1, c2);
    printf("\n%c %c\n", c1, c2);
    return 0;
}
