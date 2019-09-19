#include<stdio.h>
void main()
{
    int i,n,j,key;
    printf("Enter No. of element: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while((key<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j--;;
        }
        a[j+1]=key;
    }
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}