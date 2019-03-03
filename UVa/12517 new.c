#include <stdio.h>

int main()
{
    long long int m, n,div, cur,pre;
    while((scanf("%lld %lld", &m, &n)))
    {
        if(!m && !n) break;

        long long int sum1=0;
        cur=n%10;
        sum1=45*(n/10)+(cur)*(cur+1)/2;
        for(div=10; ; div=div*10)
        {
            if(div>n) break;
            pre=n%div;
            cur= (n/div)%10;
            sum1=sum1 + 45*(n/(div*10))*div+(cur-1)*(cur)/2*div+cur*(pre+1);
        }

        m=m-1;
        long long int sum2=0;
        cur=m%10;
        sum2=45*(m/10)+(cur)*(cur+1)/2;
        for(div=10; ; div=div*10)
        {
            if(div>m) break;
            pre=m%div;
            cur= (m/div)%10;
            sum2=sum2 + 45*(m/(div*10))*div+(cur-1)*(cur)/2*div+cur*(pre+1);
        }

        printf("%lld\n", sum1-sum2);
    }
    return 0;
}
