#include<stdio.h>

long power(int a,int n)
{
    if(n==0)
        return 1;
    else
    {
        return a*power(a,n-1);
    }
}
void main()
{
    int n,a;
    printf("Enter number=");
    scanf("%d",&a);
    printf("Enter power=");
    scanf("%d",&n);
    printf("%d^%d = %ld",a,n,power(a,n));
}