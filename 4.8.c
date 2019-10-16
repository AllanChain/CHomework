#include <stdio.h>

int main(int argc, char *argv[])
{
    int mark;
    scanf("%d", &mark);
    switch (mark/10) {
        case 9:
            putchar('A');
            break;
        case 8:
            putchar('B');
            break;
        case 7:
            putchar('C');
            break;
        case 6:
            putchar('D');
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            putchar('E');
            break;
        default:
            putchar(128);
    }
    return 0;
}
