#include <stdio.h>
#include <stdlib.h>

int findmax(int *ara, int n)
{
    int i, count=1, old=0, val=ara[0];
    for(i=1; i<n; i++)
    {
        if(ara[i]==val) count++;
        else
        {
            val=ara[i];
            if(count>old) old=count;
            count=1;
        }
    }
    if(count>old) return count;
    return old;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{

    int i,j, n, hi;

    while((scanf("%d", &n)))
    {
        if(!n) break;
        int val[n];

        for(i=0; i<n; i++) scanf("%d", &val[i]);

        qsort(val, n, sizeof(int), cmpfunc);

        hi=findmax(val, n);
        printf("%d\n", hi);

        for(i=0; i<hi; i++)
        {
            printf("%d", val[i]);
            for(j=hi; i+j<n; j+=hi ) printf(" %d", val[i+j]);
            putchar('\n');
        }
        putchar('\n');

    }
    return 0;
}
