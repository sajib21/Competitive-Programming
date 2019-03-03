#include <stdio.h>

int lls;
int dep[11][2];
int count;
int k;

int com(int n, int x, int lls)
{
    int c=0, term, r;
    if(x==k) return 0;
    lls-=dep[x][0];
    again:
    if(n-lls>dep[x][1]) term=dep[x][1];
    else term=n-lls;
    if(term==n) return 1;
    for( ;term>=dep[x][0]; term--)
    {

        r=com(n-term, x+1, lls);
        if(r==1) count++;
    }
    return 0;
}

        /*if(r==1) c+= r+ term-dep[x][0];
        else if(r>1)
        {
            if(term>dep[x][0]) n++;
            goto again;
        }
        return c;*/


int main()
{
    int t,i,n, j;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        lls=0;
        count=0;
        scanf("%d %d", &k, &n);
        for(j=0; j<k; j++)
        {
            scanf("%d %d", &dep[j][0], &dep[j][1]);
            lls+=dep[j][0];
        }
        com(n, 0, lls);
        printf("Case :%d %d\n", i, count);
    }
    return 0;
}
