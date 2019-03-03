#include <stdio.h>

int fun(int n, int l)
{
    if(n==1) return 1;
    else if(n>l) return 0;
    else if(n%2) return 1+fun(3*n+1, l);
    else return 1+fun(n/2, l);
}

int main()
{
    int t=1, i,j, n,l;
    while(1)
    {
        scanf?0"%d %d", &n, &l);
        if(n<0 && l<0) return 0;
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", t++, n,l, fun(n,l));
    }
}
