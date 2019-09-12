#include <stdio.h>
void move(int n, char src, char dest, char aux)
{
    if (n > 1)
    {
        move(n - 1, src, aux, dest);
        move(1, src, dest, aux);
        move(n - 1, aux, dest, src);
    }
    else
    {
        printf("%c to %c\n", src, dest);
    }
}
void main()
{
    int n;
    printf("Enter number of Disks = ");
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
}