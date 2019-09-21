#include <stdio.h>
void main()
{
    int n, m, i, j, l, k;
    do
    {
        printf("Enter Dimension(rowsXcoloumns) of Matrixes A: ");
        scanf("%d %d", &n, &m);
        printf("Enter Dimension(rowsXcoloumns) of Matrixes B: ");
        scanf("%d %d", &l, &k);
        int a[n][m], b[l][k];
        if (m == l)
        {
            int c[n][k];
            printf("Enter values of matrix A (column wise):\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &a[i][j]);
                }
                printf("\n");
            }
            printf("Enter values of matrix B (column wise):\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &b[i][j]);
                }
                printf("\n");
            }
            printf("Matrix A:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    printf("%d\t", a[i][j]);
                }
                printf("\n");
            }
            printf("Matrix B:\n");
            for (i = 0; i < l; i++)
            {
                for (j = 0; j < k; j++)
                {
                    printf("%d\t", b[i][j]);
                }
                printf("\n");
            }
            printf("\nMultiplied Matrix:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < k; j++)
                {
                    c[i][j] = 0;
                    for (l = 0; l < m; l++)
                    {
                        c[i][j] += a[i][l] * b[l][j];
                    }
                    printf("%d\t", c[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("These Matrixes are not VALID for Multiplication\n");
        }
    } while (l != m);
}