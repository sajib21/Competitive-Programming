#include<bits/stdc++.h>
#define ll long long int
#define LIM 200005

using namespace std;

ll n,k,x, a[LIM];
ll dp[LIM][12];

ll f(int in, int rem) {
    cout << "IN " << in << ' ' << rem << endl; getchar();
    if(in == n) return 0;
    if(dp[in][rem] != -1) return dp[in][rem];
    ll cur = a[in];
    ll ans = cur | f(in+1, rem);
    cout << "CALC " << in << ' ' << rem << ' ' << 0 << ' ' << ans << endl;
    getchar();
    for(int i=1; i<=rem; i++) {
        cur *= x;
        ll temp = cur | f(in+1,rem-i);
        ans = max(ans, temp );
        cout << "CALC " << in << ' ' << rem << ' ' << i << ' ' << temp << endl;
        getchar();
    }
    cout << "OUT " << in << ' ' << rem << ' ' << ans << endl; getchar();
    return dp[in][rem] = ans;
}

int main() {
    scanf("%lld %lld %lld", &n,&k,&x);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    memset(dp, -1, sizeof dp);

    cout << f(0, k) << endl;

    cout << ((a[0]) | (a[1]*x*x) | (a[2])) << endl;
}
