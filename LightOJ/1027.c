#include <stdio.h>

int gcd(int p, int q)
{
    if(!q) return p;
    return gcd(q, p%q);
}

int div(int p, int q)
{
    int g=gcd(p,q);
    printf("%d/%d\n", p/g, q/g);
}

int main()
{
    int t,T, n,i,j, a, flag, time;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d", &n);
        flag=0;
        time=0;
        for(j=0; j<n; j++)
        {
            scanf("%d", &a);
            if(a<0) flag++;
            time+=abs(a);
        }

        if(flag!=n)
        {
            printf("Case %d: ", t);
            div(time, n-flag);
        }
        else printf("Case %d: inf\n", t);
    }
    return 0;
}
