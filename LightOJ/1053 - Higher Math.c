#include <stdio.h>

int main()
{
    int t,T, a,b,c;
    scanf("%d", &T);
    for(t=1;t<=T; t++)
    {
        scanf("%d %d %d", &a,&b,&c);
        a*=a; b*=b; c*=c;
        if(a==b+c || a==abs(b-c)) printf("Case %d: yes\n", t);
        else printf("Case %d: no\n", t);
    }
    return 0;
}
