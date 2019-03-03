#include <stdio.h>

int comb(int n, int k)
{
    int i;
    double comb=1.0;
    if(k==0 || n==k) return 1;
    for (i = 1; i <= k; i++)
    {
        comb*= (n - k + i);
        comb/=i;
    }
    return comb;
}

int main()
{
    int n,k,k1;
    while((scanf("%d %d", &n, &k))==2)
    {
        if(!n && !k) break;

        k1=n-k;
        if(k1<k) k=k1;

        printf("%d\n", comb(n,k));
    }
    return 0;
}
