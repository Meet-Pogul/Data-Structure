#include<stdio.h>
int n;
void MergeSort(int a[],int left,int right);
void Merge(int a[],int left,int mid,int right);
void main()
{
    int i,a[50];
    printf("Enter no. of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter a[%d]= ",i);
        scanf("%d",a+i);
    }printf("\n");
    MergeSort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("a[%d]= %d\n",i,a[i]);
    }  
}
void MergeSort(int a[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=left+(right-left)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        Merge(a,left,mid,right);
    }
}
void Merge(int a[],int left,int mid,int right)
{
    int b[n];
    int p=left,q=mid+1,r=left;
    while (p<=mid && q<=right)
    {
        if(a[p]<=a[q])
        {
            b[r]=a[p];
            p++;
        }
        else
        {
            b[r]=a[q];
            q++;
        }
        r++;
    }
    while (q<=right)
    {
        b[r]=a[q];
        r++;
        q++;
    }
    while (p<=mid)
    {
        b[r]=a[p];
        r++;
        p++;
    }
    for(p=left;p<=right;p++)
    {
        a[p]=b[p];
    }
}