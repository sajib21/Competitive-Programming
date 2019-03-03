#include <stdio.h>
int main()
{
    long long  int n,b, temp;
    int count=0;
    while (scanf("%lld",&n)==1)
    {
        temp=n;
        count++;
        printf("%4d.",count);
        b=n/100000000000000;
        if (b) printf(" %lld kuti",b); ///these spaces needs to be printed before so that no space is printed after the whole line
        n=n%100000000000000;
        b=n/1000000000000;
        if (b) printf(" %lld lakh",b);
        n=n%1000000000000;
        b=n/10000000000;
        if (b) printf(" %lld hajar",b);
        n=n%10000000000;
        b=n/1000000000;
        if (b) printf(" %lld shata",b);
        n=n%1000000000;
        b=n/10000000;
        if (b) printf(" %lld",b);
        if(temp>=10000000) printf(" kuti");
        n=n%10000000;
        b=n/100000;
        if (b) printf(" %lld lakh",b);
        n=n%100000;
        b=n/1000;
        if (b) printf(" %lld hajar",b);
        n=n%1000;
        b=n/100;
        if (b) printf(" %lld shata",b);
        n=n%100;
        if(n) printf(" %lld\n", n);
        else if(!temp) printf(" %lld\n", temp);
        else printf("\n");
    }
    return 0;
}
