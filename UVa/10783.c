#include <stdio.h>

int main()
{
    int t,i, a,b;

    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d", &a, &b);
        if(!(a%2) && a) a=a+1;
        if(!(b%2) && b) b=b-1;
        a=(b+1)*(b+1)/4-(a-1)*(a-1)/4;
        printf("Case %d: %d\n", i, a);
    }
    return 0;
}
