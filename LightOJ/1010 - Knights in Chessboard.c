#include <stdio.h>

int main()
{
    int t,T, n,m, mod;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d", &n, &m);
        if(n==1 || m==1) printf("Case %d: %d\n",t, n+m-1);
        else if(n==2)
        {
            mod=m%4;
            if(!mod) printf("Case %d: %d\n", t, m);
            else if(mod==1) printf("Case %d: %d\n", t, (m/4)*4 + 2);
            else printf("Case %d: %d\n", t, (m/4)*4 + 4);
        }
        else if(m==2)
        {
            mod=n%4;
            if(!mod) printf("Case %d: %d\n", t, n);
            else if(mod==1) printf("Case %d: %d\n", t, (n/4)*4 + 2);
            else printf("Case %d: %d\n", t, (n/4)*4 + 4);
        }
        else printf("Case %d: %d\n",t, (n*m + 1)/2 );
    }
    return 0;
}
