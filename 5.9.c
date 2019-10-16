#include<stdio.h>

int main(){
    int s=1,n=1;
    for(;n<1000;n++,s=1){
        for(int i=2;i<n;i++) if(n%i==0) s+=i;
        if(s==n){
            printf("\n%d it's factors are 1", n);
            for(int i=2;i<n;i++) if(n%i==0) printf(",%d", i);
        }
    }
}
