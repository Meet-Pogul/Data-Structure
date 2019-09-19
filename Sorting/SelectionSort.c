#include<stdio.h>
void main()
{
    int i,n,j,t;
    printf("Enter No. of element: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>=a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}