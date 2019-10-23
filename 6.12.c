#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char ch;
    if(argc==1){
        printf("Please add command line argument as secret code");
        return -1;
    }
    char *s;
    for(int j=1;j<argc;j++){
        s = argv[j];
        printf("The Original String: ");
        printf(s);
        printf("\nThe Encoded String:  ");
        while ((ch=*s++)) {
            if('A'<=ch && ch<='Z') putchar('A'+'Z'-ch);
            else if('a'<=ch && ch<='z') putchar('a'+'z'-ch);
            else putchar(ch);
        }
        putchar('\n'); putchar('\n');
    }
    return 0;
}
