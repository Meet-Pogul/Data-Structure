#include<stdio.h>
void main()
{
    int n,m,i,j;
    printf("Enter Dimension(rowsXcoloumns) of Matrixes: ");
    scanf("%d %d",&n,&m);
    int a[n][m],b[n][m],c[n][m];
    printf("Enter values of matrix A (column wise):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("Enter values of matrix B (column wise):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&b[i][j]);
            c[i][j]=a[i][j]-b[i][j];
        }
        printf("\n");
    }
    printf("Matrix A:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("\nSubtracted Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}