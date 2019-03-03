#include <stdio.h>

int main()
{
    int t,T, r1,c1,r2,c2, x,y, m1,m2,m3,m4;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d %d %d", &r1,&c1,&r2,&c2);
        m1=r1%2; m2=c1%2; m3=r2%2; m4=c2%2;
        if( (m1==m3 && m2==m4) || (m1!=m3 && m2!=m4) )
        {
            x=abs(c1-c2);
            y=abs(r1-r2);
            if(x==y) printf("Case %d: 1\n", t);
            else printf("Case %d: 2\n", t);
        }
        else printf("Case %d: impossible\n", t);

    }
    return 0;
}
