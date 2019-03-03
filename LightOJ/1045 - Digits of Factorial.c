#include <stdio.h>
#include <math.h>

double ans[1000005];

int main()
{
    int t,T, n,b, x;
    scanf("%d", &T);
    for(x=1; x<1000002; x++) ans[x]=log(x)+ans[x-1];


    for(t=1; t<=T; t++)
    {
        scanf("%d %d", &n,&b);
        if(n==0 || n==1) printf("Case %d: %d\n", t,1);
        else printf("Case %d: %d\n", t,(int) ceil(ans[n]/log(b)));
    }
    return 0;
}
