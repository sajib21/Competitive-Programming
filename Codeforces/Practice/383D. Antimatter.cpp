#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int

using namespace std;

int n, a[1010];
int dp[1010][20010];

int f(int in, int cur) {
    int v = cur - 10000;
    if(in == n) return v == 0;
    if(dp[in][cur] != -1) return dp[in][cur];
    ll ans = 0;
    if(!v) ans++;
    ans = (ans + f(in+1, cur+a[in])) % MOD;
    ans = (ans + f(in+1, cur-a[in])) % MOD;
    return dp[in][cur] = ans;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    for(int i=0; i<n; i++) ans = (ans + f(i+1, 10000+a[i]) + f(i+1, 10000-a[i])) % MOD;
    printf("%I64d\n", ans);
}
