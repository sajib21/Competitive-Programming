#include<cstdio>
int main()
{
    long long  int n,a,b,c,d,e,f,g,h,i,j,k,l,m,o,p,q,r,s;
    int count=0;
    while (scanf("%lld",&n)==1)
    {
        count++;
        printf("%4d.",count);
        b=n/100000000000000;
        if (b>0)
            printf(" %lld kuti",b);
        c=n%100000000000000;
        d=c/1000000000000;
        if (d>0)
            printf(" %lld lakh",d);
        e=c%1000000000000;
        f=e/10000000000;
        if (f>0)
            printf(" %lld hajar",f);
        g=e%10000000000;
        h=g/1000000000;
        if (h>0)
            printf(" %lld shata",h);
        i=g%1000000000;
        j=i/10000000;
        if (j==0&&n>10000000)
            printf(" kuti");
        if (j>0)
            printf(" %lld kuti",j);
        k=i%10000000;
        l=k/100000;
        if (l>0)
            printf(" %lld lakh",l);
        m=k%100000;
        o=m/1000;
        if (o>0)
            printf(" %lld hajar",o);
        p=m%1000;
        q=p/100;
        if (q>0)printf(" %lld shata",q);
        r=p%100;
        s=r/1;
        if (s>0)
            printf(" %lld",s);
        if (n==0)
            printf(" %lld",n);
        printf("\n");
    }
    return 0;
}
