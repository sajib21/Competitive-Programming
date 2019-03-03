#include <stdio.h>
#include <string.h>
int main()
{
    int g,i, len;

    while(scanf("%d", &g)==1)
    {
        if(!g) break;
        getchar();
        char str[101];
        gets(str);
        len=strlen(str);
        g=len/g;

        for(i=g-1; i<=len; i=i+g)
        {
            int ex=0;
            while(ex<g)
            {
                printf("%c", str[i-ex]);
                ex++;
            }

        }

        putchar('\n');
    }
    return 0;
}
