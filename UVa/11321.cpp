#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector < int > ara[100010];

int main()
{

    int n,m, nm[100002], i=0,j, a, sz;
    while(scanf("%d %d", &n, &m) && n && m )
    {
        while(i--) ara[i].clear();

        for(i=0; i<n; i++) scanf("%d", &nm[i]);
        sort(nm,nm+n);

        for(i=0; i<n; i++)
        {
            ara[nm[i]%m].push_back(nm[i]);
        }

        printf("%d %d\n", n,m);
        for(i=0; i<m; i++)
        {
            sz=ara[i].size();
            for(j=sz-1; j>=0; j--) if(ara[i][j]%2) printf("%d\n", ara[i][j]);
            for(j=0; j<sz; j++) if(!(ara[i][j]%2)) printf("%d\n", ara[i][j]);
        }
    }

    printf("0 0\n");

    return 0;
}
