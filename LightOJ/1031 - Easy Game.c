#include <stdio.h>

int main()
{
    int t,T, n, ara[102], i,j, max1,max2, temp=0, sum=0, dif;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        max1=0; max2=0; temp=0; sum=0; dif=0;
        scanf("%d", &n);
        scanf("%d", &ara[0]); max1=ara[0];
        for(i=1; i<n; i++)
        {
            scanf("%d", &ara[i]);
            ara[i]+=ara[i-1];
        }
        n--;
        for(i=0; i<=n; i++) if(2*ara[i]>ara[n] && ara[i]-ara[n]>dif) dif=abs(ara[i]-ara[n]);

        //if(max1==ara[n-1]) printf("Case %d: %d\n", t,max1);
        printf("Case %d: %d\n", t, dif);
    }
    return 0;
}
