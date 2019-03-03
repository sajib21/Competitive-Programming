#include<bits/stdc++.h>

using namespace std;

int n,m;
int dressCode[111];
int dp[110][110];

int mcm(int l, int r) {

    if(l==r) return 1;
    if(dp[l][r] != -1) return dp[l][r];

    int ans = INT_MAX;
    for(int i=l; i<r-1; i++) {
        ans = min(ans, mcm(l, i) + mcm(i+1, r) );
    }
    if(dressCode[l] == dressCode[r]) ans = min(ans, mcm(l, r-1) );
    else ans = min(ans, mcm(l, r-1)+mcm(r, r));
    return dp[l][r] = ans;
}

int main() {

    int T,t;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d",&n, &m);
        for(int i=1; i<=n; i++) scanf("%d", &dressCode[i]);
        printf("Case %d: %d\n", t, mcm(1, n));
    }
    return 0;
}
