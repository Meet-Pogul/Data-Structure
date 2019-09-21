#include <stdio.h>

int len(char str[]);
void cpy(char *p, char *q);
void rev(char *s1);
void cat(char *s1, char *s2);
char* str(char *s1, char *s2);
int cmp(char *s1, char *s2);
int i;
int main()
{
    char s1[50], sw = '0', s2[50];
clear:
    if (sw == 'c')
    {
        for (i = 0; s1[i] != '\0'; i++){s1[i]='\0';}
        getchar();
    }
    printf("Enter String:");
    gets(s1);
    do
    {
        printf("What do you want to do\n1.Find Length of the String\t");
        printf("2.Copy one string to another\n3.Reverse the string\t\t");
        printf("4.Concate the string\n5.Find the substring\t\t6.Compare two strings\n7.Re-Enter String\t8.Quit\n");
        scanf(" %c", &sw);
        switch (sw)
        {
        case '1':
            printf("Length: %d\n", len(s1));
            i = 1;
            break;
        case '2':
            cpy(s1, s2);
            printf("String Copied.\ns2=%s\n", s2);
            i = 1;
            break;
        case '3':
            rev(s1);
            printf("String Reversed = %s\n", s1);
            i = 1;
            break;
        case '4':
            printf("Enter Other String:");
            getchar();
            gets(s2);
            cat(s1, s2);
            printf("%s\n", s1);
            i=1;
            break;
        case '5':
            printf("Enter Sub String:");
            getchar();
            gets(s2);
            if(str(s1,s2)!=0)
            {
                printf("Matched\n");
            }
            else
            {
                printf("Error: 404 Not Found!\n");
            }
            i=1;
            break;
        case '6':
            printf("Enter String 2:");
            getchar();
            gets(s2);
            if (cmp(s1, s2) == 0)
            {
                printf("Matched\n");
            }
            else
            {
                printf("Not Matched!\n");
            }
            i = 1;
            break;
        case '7':
            goto clear;
        case '8':
            return 0;
        default:
            wrong:
            printf("Wrong Input!\n");
            break;
        }
        printf("Do you Want to Continue(y/n/c):");
        scanf(" %c", &sw);
        if (sw == 'y')
        {
            i = 0;
        }
        if (sw == 'c')
        {
            goto clear;
        }
        if(sw != 'y'&&sw!='c'){goto wrong;}

    } while (i == 0);
}
int len(char str[])
{
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}
void cpy(char *p, char *q)
{
    for (i = 0; *p != '\0'; i++)
    {
        *q++ = *p++;
    }
}
int cmp(char *s1, char *s2)
{
    int n1, n2, i;
    i = len(s1);
    n1 = i;
    i = len(s2);
    n2 = i;
    if (n1 > n2)
    {
        return 1;
    }
    else if (n1 < n2)
    {
        return -1;
    }
    else
    {
        for (i = 0; i < n1; i++)
        {
            if (*(s1 + i) != *(s2 + i))
            {
                return *(s1 + i) - *(s2 + i);
            }
        }
    }
    return 0;
}
void rev(char *s1)
{
    char ch;
    int n, i;
    n = len(s1);
    for (i = 0; i < n / 2; i++)
    {
        ch = *(s1 + i);
        *(s1 + i) = *(s1 + n - i - 1);
        *(s1 + n - i - 1) = ch;
    }
    *(s1 + n) = '\0';
}
void cat(char *s1, char *s2)
{
    int n1, n2, i;
    n1 = len(s1);
    n2 = len(s2);
    for (i = 0; i < n2; i++)
    {
        *(s1 + i + n1) = *(s2 + i);
    }
    *(s1 + n1 + n2) = '\0';
}
char* str(char *s1, char *s2)
{
    int n1, n2, i=0,j=0;
    n1 = len(s1);
    n2 = len(s2);
    for (i = 0; i < n1; i++)
    {
        j=0;
        while(*(s2+j)==*(s1+i)){j++;i++;}
        if(j==n2){return s1+i-j;}
    }
    return'\0';
}
