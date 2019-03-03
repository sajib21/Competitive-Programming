#include <bits/stdc++.h>
#define ll long long int
#define LIM 2002
#define MOD 1000000007

int n,k, a[LIM];
ll dp[LIM][LIM];

ll f(int in, int open) {
    if(in == n) return open == 0;
    if(dp[in][open] != -1) return dp[in][open];
    ll ans = 0;
    int cur = a[in] + open;
    if(cur == k) {
        ans = (ans + f(in+1, open)) % MOD;
        if(open) ans = (ans + open*f(in+1, open-1)) % MOD;
    }
    else if(cur == k-1) {
        ans = (ans + (open+1)*f(in+1, open)) % MOD;
        ans = (ans + f(in+1, open+1)) % MOD;
    }
    return dp[in][open] = ans;
}

int main() {
    scanf("%d %d", &n,&k);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    printf("%I64d\n", f(0, 0));
}
