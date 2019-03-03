#include<bits/stdc++.h>

using namespace std;

int n,len, cut[55];
int dp[55][55];

int f(int lft, int rgt) {
    if(lft+1 == rgt) return 0;
    if(dp[lft][rgt] != -1) return dp[lft][rgt];
    int ans = INT_MAX, cost = cut[rgt] - cut[lft];
    for(int i=lft+1; i<rgt; i++) ans = min(ans, cost + f(lft, i) + f(i, rgt) );
    return dp[lft][rgt] = ans;
}

int main() {
    while(true) {
        scanf("%d", &len);
        if(!len) return 0;
        scanf("%d", &n);
        cut[0] = 0; cut[n+1] = len;
        for(int i=1; i<=n; i++) scanf("%d", &cut[i]);
        memset(dp, -1, sizeof dp);
        printf("The minimum cutting is %d.\n", f(0, n+1));
    }
}
