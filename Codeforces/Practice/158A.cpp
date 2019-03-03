#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k, ara[100], i,j;
    scanf("%d %d", &n, &k);

    for(i=1; i<=n; i++) scanf("%d", &ara[i]);

    if(ara[k] > 0)
    {
        while(ara[k] == ara[k+1])
            k++;
        printf("%d\n", k);
    }
    else
    {
        while(ara[k] <= 0 && k>0)
            k--;
        printf("%d\n", k);
    }

    return 0;

}
