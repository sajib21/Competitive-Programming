#include<bits/stdc++.h>
#define MAX 10000007
#define MOD 100000007
#define ll long long int

using namespace std;

ll n;

ll po(ll n, ll r) {
    if(!r) return 1;
    if(r&1) return (n*po(n, r-1))%MOD;
    ll ans = po(n, r/2);
    return (ans*ans) % MOD;
}

int main() {
    int T;
    while(scanf("%lld", &n) && n) {
        ll ans = 0;
        if(n >= 1) ans = (n * po(2, n-1)) % MOD;
        if(n >= 2) ans += ( (n*(n-1)*7)%MOD * po(2, n-2) ) % MOD; ans %= MOD;
        if(n >= 3) ans += ( ( (n*(n-1)%MOD)*(n-2)*6 )%MOD * po(2, n-3) ) % MOD; ans %= MOD;
        if(n >= 4) ans += ( ( (n*(n-1)%MOD)*((n-2)*(n-3)%MOD) )%MOD * po(2, n-4) ) % MOD; ans %= MOD;

        printf("%lld\n", ans);
    }
}
