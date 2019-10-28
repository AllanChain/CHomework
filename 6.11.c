#include <stdio.h>

int main(int argc, char *argv[])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<i*2;j+=2)
            putchar(' ');
        for (int j = 0; j < 5; ++j) {
            putchar('*');
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
