#include <stdio.h>

char* month(int a)
{
    char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    return months[a-1];
}
int main(void)
{
    int a;
    scanf("%d", &a);
    printf("%s", month(a));
    return 0;
}
