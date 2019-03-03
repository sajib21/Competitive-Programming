#include <stdio.h>

int main()
{
    int a,b, temp;

    while(1)
    {
        scanf("%d %d", &a, &b);
        putchar('[');
        printf("%d", a/b);
        temp=b;
        b=a%b;
        a=temp;
        if(b)
        {
            putchar(';');
            printf("%d", a/b);
            temp=b;
            b=a%b;
            a=temp;
        }
        while(b)
        {
            putchar(',');
            printf("%d", a/b);
            temp=b;
            b=a%b;
            a=temp;
        }
        putchar(']');
        putchar('\n');
    }
    return 0;
}
