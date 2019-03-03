#include <stdio.h>

int main()
{
    long long int a,b,c,d,x, count, rt;
    while((scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &x))==5)
    {
        if(!a && !b && !c && !d && !x) break;
        count=0;
        while(x>=0)
        {
            rt=a*x*x+b*x+c;
            if(!(rt%d)) count++;
            x--;
        }
        printf("%lld\n", count);
    }
    return 0;
}
