#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int x, int y)
{
    if(x==y) return;
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}

void quick_sort(int a[], int start, int end)
{
    int left=start-1;
    int right=end;
    int pivot=a[end];
    while(left<right)
    {
        while(left<right && a[++left]<=pivot) ;
        while(left<right && a[--right]>=pivot) ;
        swap(a, left, right);
    }
    swap(a, right, end);
    if(right-1>0) quick_sort(a, 0, right-1);
    if(right+1<end) quick_sort(a, right+1, end);
}
int main(int argc, char *argv[])
{
    int a[10];
    srand(0);
    for(int i=0;i<10;i++)
    {
        a[i]=rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");
    quick_sort(a, 0, 9);
    for(int i=0;i<10;i++)
        printf("%d ", a[i]);
    return 0;
}
