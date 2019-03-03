#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define pb push_back

using namespace std;

int chkBit(int mask, int p) { return mask & (1 << p); }

char seq[10];
ll n, tar, ans, mul;

ll f(ll n, ll r) {
    if(!r) return 1;
    if(r&1) return (n*f(n,r-1)) % MOD;
    ll x = f(n, r/2);
    return (x * x) % MOD;
}

ll inv(ll b) {
    return f(b, MOD-2);
}

ll g(ll d) {
    ll r = n;
    ll ans = 1;

    while(d) {

    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %s", &n, seq);
        mul = f(10, n);
        tar = 1;
        for(int i=0; i<6; i++) if(seq[i] == '1') tar *= i+1;

//        ans = (mul * inv(tar)) % MOD;
        ans = mul / tar;

        vi rem;
        for(int i=0; i<6; i++) if(seq[i] == '0') rem.pb(i+1);
        int sz = rem.size();

//        cout << mul << ' ' << tar << ' ' << inv(tar) << ' ' << ans << endl;
//        cout << sz << endl;
//        for(int i=0; i<sz; i++) cout << rem[i] << ' ' ; cout << endl;

        for(int i=1; i < (1 << sz); i++) {
            ll temp = tar;
            for(int j=0; j<sz; j++) {
                if(chkBit(i,j)) temp *= rem[j];
            }
            if(__builtin_popcount(i)&1) {
//                ans -= (mul * inv(temp)) % MOD;
                ans -= mul / temp;
            }
            else {
//                ans -= (mul * inv(temp)) % MOD;
                ans += mul / temp;
            }
        }
        printf("%lld\n", ans);
    }
}
