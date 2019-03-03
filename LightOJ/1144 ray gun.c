#include <stdio.h>

int gcd(int n, int i)
{
    int temp;
    while(i)
    {
        temp=i;
        i=n%i;
        n=temp;
    }
    return n;
}

int cdiv(int n, int m)
{
    int i, c=0;
    for (i=2; i<=m; i++) if(gcd(n,i)!=1) c++;
    return c;
}

int shot(int n, int m)
{
    if(m==1 && n==1) return 3;
    if(n>m) return shot(n-1, m) + (m-cdiv(n, m));
    else return 2*shot(n,n-1) - shot(n-1, n-1);
}

int main()
{
    int t, i, m,n;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d", &m, &n);
        if(n>m) printf("Case :%d %d\n", i, shot(n,m));
        else printf("Case :%d %d\n", i, shot(m,n));
    }
    return 0;
}
