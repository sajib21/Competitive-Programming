#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ara[19][19], flag[19], n, S[20][20];

int rec(int z)
{
    if(z>n) return 0;

    int i,j, sum=0, maxx=0;
    for(i=1; i<=n; i++)
    {
        if(flag[i]==1) continue;
        flag[i]=1;
        if(S[z][i]==-1) s[z][i]=rec(z+1);
        sum = ara[z][i] + rec( z+1);
        flag[i]=0;

        if(sum>maxx) maxx=sum;
        S[z][i]=maxx;
    }
    return maxx;
}

int main()
{
    int T,t, i,j;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d", &n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d", &ara[i][j]);
            }
        }
        memset(S, -1, sizeof(S));
        printf("Case %d: %d\n",t,  rec( 1));
    }

    return 0;
}
