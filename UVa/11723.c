#include <stdio.h>

int main()
{
    int R, N, D, i=1;
    while((scanf("%d %d", &R, &N))==2)
    {
        if(!R || !N) break;
        D=(R-1)/N;
        if(D>26) printf("Case %d: impossible\n", i);
        else printf("Case %d: %d\n", i, D);
        i++;
    }
    return 0;
}
