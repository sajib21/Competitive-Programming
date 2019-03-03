#include<bits/stdc++.h>

using namespace std;

int main() {

    int n,m,k, army[1010], diff[23], ans=0;
    memset(diff, 0, sizeof(diff));

    scanf("%d %d %d", &n,&m,&k);
    for(int i=0; i<=m; i++) scanf("%d", &army[i]);

    for(int i=0;i<m;i++)
    {
        if(__builtin_popcount(army[m] ^ army[i]) <= k)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
