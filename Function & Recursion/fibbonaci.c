#include<stdio.h>
long z=1,k=2,l=0;

long fib(int n)
{
    long x,y;
    if (n<=1)
        return n;
    x=fib(n-1),y=fib(n-2);
    if(n==k)
    {
        if(k==2)
            printf("Sequence = 1,1,");
        else if(k==l)
            printf("%d\n",x+y);
        else
            printf("%d,",x+y);
        z+=x+y;
        k++;
    }
    return x+y;
}

void main()
{
    int n;
    printf("Enter the position:");
    scanf("%d",&n);
    l=n;
    printf("Number at position %d = %ld\n",n,fib(n));
    printf("Sum till %d position = %ld\n",n,z);
}