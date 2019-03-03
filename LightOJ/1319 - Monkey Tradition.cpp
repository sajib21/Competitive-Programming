#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}

ll n, p[15], r[15];
ll P, Pi[15], P1[15];



int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        P = 1;
        scanf("%lld", &n);
        for(int i=0; i<n; i++) {
            scanf("%lld %lld", &p[i], &r[i]);
            P *= p[i];
        }
        for(int i=0; i<n; i++) Pi[i] = P / p[i];
        for(int i=0; i<n; i++) P1[i] = bigMod(Pi[i], p[i]-2, p[i]) % p[i];

        ll ans = 0;
        for(int i=0; i<n; i++) ans += r[i] * Pi[i] * P1[i];

        printf("Case %d: %lld\n", t, ans%P);
    }
    return 0;
}

