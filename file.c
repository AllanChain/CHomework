/* 输入一段文字，建立文件存储这些文字， */
/* 约定输入Tab或回车时结束录入。 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a;
    FILE *f;
    f = fopen("d:/Desktop/lalal.txt", "wt");
    if(!f){
        printf("voila!");
        exit(1);
    }
    while((a=getchar()) != '\t')
        fputc(a, f);
    fputc(EOF, f);
    fclose(f);
    return 0;
}
