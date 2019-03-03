#include <stdio.h>
#include <math.h>

int main()
{
    long long int n, a,b, sum, na, v, dif;
    while(scanf("%lld", &n) && n!=-1)
    {
        a=1;
        b= (int) ((double) (-1.0+sqrt(1+8*n))/2.0+ 0.999999);
        sum=b*(b+1)/2;
        while(sum!=n)
        {
            if(sum<n) sum+=++b;
            else
            {
                dif=sum-n;
                v=2*a-1;
                na= (-v+sqrt((v*v)+8*dif))/2 + 0.999999;
                sum-= na*(2*a+(na-1))/2;
                a+=na;
            }
        }
        printf("%lld = %lld + ... + %lld\n", n, a,b);
    }
    return 0;
}
