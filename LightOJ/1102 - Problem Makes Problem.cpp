#include<bits/stdc++.h>
#define ll long long int
#define LIM 1000000
#define MOD 1000000007

using namespace std;

ll fact[2*LIM+100];

ll bigMod(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1)*n) % MOD;
    ll ans = bigMod(n, r/2);
    return (ans*ans) % MOD;
}

int main() {

    fact[0] = 1;
    for(int i=1; i<=2*LIM; i++) fact[i] = (fact[i-1]*i) % MOD;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ll n,k;
        scanf("%lld %lld", &n,&k);
        printf("Case %d: %lld\n", t, ( (fact[n+k-1] % MOD) *  (bigMod( ( fact[n]*fact[k-1] )%MOD , MOD-2 ) % MOD ) ) % MOD );
    }
    return 0;
}

///(n+k-1)C(k-1)
