#include <stdio.h>

int main()
{
    int t, n;
    scanf("%d", &t);

    while(t)
    {
        scanf("%d", &n);
        n=(63*n+7492)*5-498;
        n=n-((int)(n/100))*100;
        if(n<0) n=n*-1;
        printf("%d\n", (n/10));
        t--;
    }
    return 0;
}
