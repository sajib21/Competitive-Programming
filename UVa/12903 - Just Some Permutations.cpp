#include<bits/stdc++.h>
#define LIM 2020
#define MOD 1000000007
#define ll long long int

using namespace std;

int n,k;
ll dp[LIM][LIM];

ll f(int n, int k) {
    if(k < 0 || n < 0) return 0;
    if(n == 0) return k == 0;
    if(dp[n][k] != -1) return dp[n][k];

    ll ans = f(n-1, k-1) + f(n-2, k-2);
    ans %= MOD;

    for(int i=3; i<=n; i++) {
        ans += 2*f(n-i, k-i+1);
        ans %= MOD;
    }

    return dp[n][k] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
//    cout << f(3, 2) << endl;
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &k);
        ll ans = 0;
        for(int i=k; i<=n; i++) {
            cout << n << " " << i << ' ' << f(n,i) << endl;
            ans += f(n, i);
            ans %= MOD;
        }
        printf("Case %d: %lld\n", t, ans);
    }
}
