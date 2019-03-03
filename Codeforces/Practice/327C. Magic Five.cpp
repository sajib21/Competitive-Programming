#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define LIM 100005

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

string seq;
ll k;

int main() {
    cin >> seq;
    scanf("%lld", &k);

    //reverse(seq.begin(), seq.end());

    ll x = 0;

    for(int i=seq.size()-1; i >= 0; i--) {
        if(seq[i] == '0' || seq[i] == '5') {
            x += bigMod(2, i, MOD);
            x %= MOD;
        }
    }

    ll y = (bigMod(2, k*seq.size(), MOD ) - 1) % MOD;
    y %= MOD;

    ll z = (bigMod(2, seq.size(), MOD) - 1) % MOD;
    x %= MOD;

    ll ans = (x*y)%MOD;
    ans *= modInverse(z, MOD);
    ans %= MOD;

    cout << ans << endl;

}
