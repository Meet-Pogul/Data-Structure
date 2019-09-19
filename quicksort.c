#include<stdio.h>
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int p;
        p=part(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}
int part(int a[],int low,int high)
{
    int pivot=a[low],i=low+1,j=high;
    while(i<=j)
    {
        while (a[i]<pivot)
            i++;
        while (a[j]>pivot)
            j--;
        if(i<j)
            swap(&a[i],a[j]);
    }
    a[low]=a[j];
    a[j]=pivot;
    return j;
}
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void main()
{
    int i,a[50],n;
    printf("Enter no. of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter a[%d]= ",i);
        scanf("%d",a+i);
    }printf("\n");
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("a[%d]= %d\n",i,a[i]);
    }  
}