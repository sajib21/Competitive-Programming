#include <stdio.h>
#include <math.h>
int main()
{
    int t,T;
    long long int s, root, c, ctime;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld", &s);
        root=sqrt(s-1);

        c=ceil(sqrt(s));
        ctime= c*c - c + 1;
        if(root%2)
        {
            if(s<ctime) printf("Case %d: %lld %lld\n",t, c-ctime+s, c);
            else printf("Case %d: %lld %lld\n",t, c,c-s+ctime);
        }
        else
        {
            if(s>ctime) printf("Case %d: %lld %lld\n",t, c-s+ctime, c);
            else printf("Case %d: %lld %lld\n",t, c, c-ctime+s);
        }
    }
    return 0;
}
