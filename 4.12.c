#include <stdio.h>

int main(int argc, char *argv[])
{
    float x, y, dm2, dt2;
    dm2=2;
    printf("x,y: ");
    scanf("%f,%f", &x, &y);
    for (int i = -2; i <= 2; i+=4) {
        for (int j = -2; j <= 2; j+=4) {
            dt2 = (x-i)*(x-i)+(y-j)*(y-j);
            if(dm2 > dt2) dm2 = dt2;
        }
    }
    if(dm2<=1) printf("10");
    else printf("0");
    return 0;
}
