#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }


int n, MOD;
map<int,int>koyta;

ll fact[100005];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int x;
        scanf("%d", &x);
        ase.insert(pii(x,i));
    }
    for(int i=1; i<=n; i++) {
        int x;
        scanf("%d", &x);
        ase.insert(pii(x,i));
    }

    scanf("%d", &MOD);

    fact[0] = 1;
    for(int i=1; i<=100000; i++) {
        fact[i] = (fact[i-1]*i) % MOD;
    }

    ll ans = 1;

    int cnt = 0;
    int last = -1;
    for(auto p : ase) {
        if(p.ff == last) cnt++;
        else {
            ans *= fact[cnt];
            ans %= MOD;
            cnt = 1;
            last = p.ff;
        }
    }
    ans *= fact[cnt];
    ans %= MOD;

    cout << ans << endl;

}
