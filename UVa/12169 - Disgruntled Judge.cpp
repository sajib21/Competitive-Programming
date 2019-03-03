#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll MOD = 10001;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }


int main() {
    ll x1 = 17, x2, x3 = 822, x4, x5 = 3014, x6;
    ll a = ( (x5-x3+MOD)%MOD * modInverse( (x3-x1+MOD)%MOD, MOD ) ) % MOD;
    ll b;
    for(int i=0; i<10000; i++) {
        int temp = ( a*( a*x1+i )%MOD + i ) % MOD;
        if(temp == x3) {
            b = i;
            break;
        }
    }

    x2 = (a*x1 + b) % MOD;
    x4 = (a*x3 + b) % MOD;
    x6 = (a*x5 + b) % MOD;

    cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << ' ' << x5 << ' ' << x6 << endl;
}
