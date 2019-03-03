#include <stdio.h>

int main()
{
    int t,i, n,p,q, j, sumt, w[32];
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d", &n, &p, &q);

        for(j=0; j<n; j++) scanf("%d", &w[j]);

        sumt=0;
        j=0;
        while(sumt<p && w[j]<=q)
        {
            sumt++;
            q=q-w[j];
            j++;
        }

        printf("Case %d: %d\n",i, sumt);
    }
    return 0;
}
