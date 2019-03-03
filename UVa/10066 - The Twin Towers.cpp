#include<bits/stdc++.h>

using namespace std;

int t1[110], t2[110];
int dp[110][110];
int n,m;


int maxLcs(int a, int b) {

    if(a==n || b==m) return 0;
    if(dp[a][b] == -1) {

        if(t1[a] == t2[b]) dp[a][b] = 1 + maxLcs(a+1, b+1);
        else dp[a][b] = max(maxLcs(a+1, b), maxLcs(a, b+1));
    }
    return dp[a][b];
}

int main() {

    int t=1;
    while(scanf("%d %d", &n,&m) && n && m) {

        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++) scanf("%d", &t1[i]);
        for(int i=0; i<m; i++) scanf("%d", &t2[i]);

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", t++, maxLcs(0,0));
    }

    return 0;


}
