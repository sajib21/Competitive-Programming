#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,mod, total = 0, c;

ll power(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (power(n, r-1) * n) % mod;
    ll ans = power(n, r/2);
    return (ans*ans) % mod;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        total = 0;
        scanf("%d %d %d", &n,&k,&mod);
        for(int i=0; i<n; i++) {
            scanf("%lld", &c);
            total += c;
        }
        ll ans = ( ((k*power(n, k-1))%mod) * total ) % mod;
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
