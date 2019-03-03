#include <stdio.h>
#include <string.h>
int main()
{
    int g,i,j, len;

    while(scanf("%d", &g)==1)
    {
        if(!g) break;
        getchar();
        char str[101];
        gets(str);
        len=strlen(str);
        g=len/g;
        char out[g+1];
        for(i=0; i<len; i=i+g)
        {
            int ex=0;
            for(j=g-1; j>=0; j--)
            {
                out[j]=str[i+ex];
                ex++;
            }
            out[g]='\0';
            printf("%s", out);
        }
        putchar('\n');
    }
    return 0;
}
