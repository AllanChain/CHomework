#include<stdio.h>

int main(){
    int a=2,n=5,s=0,num=0;
    for(int i=0;i<n;i++)
        s+=num=num*10+a;
    printf("%d", s);
}
