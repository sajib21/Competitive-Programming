#include <stdio.h>

int main()
{
    int t=1, pola,maiya, p,m, a, i,j;
    while(scanf("%d %d", &pola, &maiya) && (pola || maiya))
    {
        scanf("%d", &p);
        for(i=1; i<pola; i++)
        {
            scanf("%d", &a);
            if(a<p) p=a;
        }
        for(i=0; i<maiya; i++) scanf("%d", &a);

        if(pola<=maiya) printf("Case %d: 0\n", t++);
        else printf("Case %d: %d %d\n", t++, pola-maiya, p);
    }

    return 0;
}
