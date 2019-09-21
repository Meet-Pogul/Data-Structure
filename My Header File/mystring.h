int len(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}
void cpy(char *p, char *q)
{
    int i;
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