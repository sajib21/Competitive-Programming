#include <stdio.h>

long long int n;
long long int m;
long long int p[17];

long long int lcd(long long int x,long long int y)
{
    long long int temp, a=x, b=y;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return (x/a)*y;
}

long long int div(long long int l,long long int x)
{
    long long int c=0, lc;
    if(x==m) return 0;
    for( ; x<m; x++)
    {
        lc=lcd(l, p[x]);
        c-= (n/lc + div(lc, x+1));
    }
    return c;
}

int main()
{
    long long int t, i,j,k, count,tem;
    scanf("%lld", &t);

    for(i=1; i<=t; i++)
    {
        count=0;
        scanf("%lld %lld", &n, &m);
        tem=n;
        for(j=0; j<m; j++) scanf("%lld", &p[j]);

        for(k=0; k<m; k++)
        {
            tem-= (n/p[k] + div(p[k], k+1));
        }

        printf("Case %lld: %lld\n",i, tem);
    }
    return 0;
}
