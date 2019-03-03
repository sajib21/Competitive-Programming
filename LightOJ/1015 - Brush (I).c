#include <stdio.h>

int main()
{
    int t,T, n,i,a, total;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        total=0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &a);
            if(a>0) total+=a;
        }
        printf("Case %d: %d\n", t,total);
    }
    return 0;
}
