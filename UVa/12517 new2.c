#include <stdio.h>

int main()
{
    long long int m, n, div,pre, cur;
    while((scanf("%lld %lld", &m, &n)))
    {
        if(!m && !n) break;

        long long int sum1=0;
        cur=n%10;
        sum1=45*(n/10)+(cur)*(cur+1)/2;
        pre=cur;
        div=10;
        while(n>=10)
        {
            n=n/10;
            cur= n%10;
            sum1=sum1 + 45*(n/10)*div+(cur-1)*(cur)/2*div+cur*(pre+1);
            pre=pre+(n%10)*div;
            div=div*10;
        }

        m=m-1;
        long long int sum2=0;
        cur=m%10;
        sum2=45*(m/10)+(cur)*(cur+1)/2;
        pre=cur;
        div=10;
        while(m>=10)
        {
            m=m/10;
            cur= m%10;
            sum2=sum2 + 45*(m/10)*div+(cur-1)*(cur)/2*div+cur*(pre+1);
            pre=pre+(m%10)*div;
            div=div*10;
        }

        printf("%lld\n", sum1-sum2);
    }
    return 0;
}
