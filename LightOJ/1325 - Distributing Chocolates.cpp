#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007LL
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

ll a,b;

ll disLog(ll base, ll num, ll mod) {
    map<ll, ll>mp;
    ll lim = ceil(sqrt(mod));
    ll temp = 1;
    for(ll rem=0; rem<lim; rem++) {
        if(!mp.count(temp)) mp[temp] = rem;
        temp = (temp * base) % mod;
    }

    ll co = modInverse(base, mod);
    co = bigMod(co, lim, mod);
    ll lft = num;

    for(ll m=0; m<lim; m++) {
        if(mp[lft]) return m*lim + mp[lft];
        lft = (lft * co) % mod;
    }
    return -1;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld %lld", &a,&b);
        printf("Case %d: %lld\n", t, disLog(a, b, MOD));
    }

}
