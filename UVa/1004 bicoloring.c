#include <stdio.h>

int c[202][202];

int bic(int x, int flag)
{
    for(i=0; i<)
}

int main()
{
    int n, l, a,b, x;
    start:
    while(scanf("%d", &n) && n)
    {
        scanf("%d", &l);
        while(l)
        {
            scanf("%d %d", &a, &2b);
            c[a] b
            c[b][a]=1;
            l--;
        }
        for(x=0; x<n; x++) if(bic(x, 4)==-1)
        {
            printf("NOT BICOLORABLE.\n");
            goto start;
        }
        printf("BICOLORABLE.\n");
    }
    return 0;
}
