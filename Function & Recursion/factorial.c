#include<stdio.h>
long fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}
void main()
{
    int n;
    printf("Enter number:");
    scanf("%d",&n);
    printf("%d!=%ld\n",n,fact(n));
}