#include<bits/stdc++.h>
#define ll long long int
#define LIM 505
#define MOD 998244353
#define MAX 2000000000000000000LL
#define sqr(x) (x) * (x)

using namespace std;

int n, ok[LIM];
ll x;
vector<ll>v;
map<ll,ll>koyta;
map<ll,ll>xtra;

ll sqrty(ll x) {
    ll lo=0, hi=2000000000LL, md;
    while(lo < hi) {
        md = (lo+hi)/2;
//        cout << lo << ' ' << hi << ' ' << md << ' ' << sqr(md) << endl;
        if(sqr(md) >= x) hi = md;
        else lo = md+1;
    }
    if(hi*hi > x) hi--;
    return hi;
}
ll cbrty(ll x) {
    ll lo=0, hi=1500000LL, md;
    while(lo < hi) {
        md = (lo+hi)/2;
//        cout << lo << ' ' << hi << ' ' << md << ' ' << sqr(md) << endl;
        if(sqr(md)*md >= x) hi = md;
        else lo = md+1;
    }
    if(hi*hi*hi > x) hi--;
    return hi;
}

int main() {
//    cout << sqrty(4606061759128693) << endl;
//    cout << 1LL*67867973*67867973 << endl;


//    cout << cbrty(8) << endl;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &x);

        ll sq = sqrty(x);
        ll sq2 = sqrty(sq);

//        printf("sq %lld %lld\n", sq, sq*sq );

//        cout << "SQRT " << sqrty(x) << ' ' << sq*sq << endl;

        if(sqr( sqr(sq2) ) == x) {
            koyta[sq2] += 4;
            continue;
        }
        if(sq*sq == x) {
            koyta[sq] += 2;
            continue;
        }

        ll cr = cbrty(x);
        if(cr*cr*cr == x) {
            koyta[cr] += 3;
            continue;
        }

        v.push_back(x);
    }

//    cout << "EX " << endl;
//    for(auto p : v) cout << p << endl;

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(i == j || v[i] == v[j]) continue;

            ll g = __gcd(v[i], v[j]);
            if(g == 1 || g == v[i]) continue;


            if(!ok[j]) {
                koyta[ g ]++;
                koyta[ v[j]/g ]++;
                ok[j] = 1;
            }
            if(!ok[i]) {
                koyta[ g ]++;
                koyta[ v[i]/g ]++;
                ok[i] = 1;
            }

        }
    }

    for(int i=0; i<v.size(); i++) if(!ok[i]) {
        ll x = v[i];
        for(auto p : koyta) {
            ll cur = p.first;
            if(x%cur == 0) {
//                cout << "PAI " << x << ' ' << cur << endl;
                koyta[cur]++;
                koyta[ x/cur ]++;
                ok[i] = 1;
                break;
            }

        }

        if(!ok[i]) xtra[ v[i] ]++;
    }

//    cout << "BUG" << endl;



    ll ans = 1;
    for(auto it : koyta) {
        ans *= it.second+1;
        ans %= MOD;
//        cout << "PRIME " << it.first << ' ' << it.second << endl;
    }

//    cout << ans << endl;

    for(auto it : xtra) {
        ans *= ((it.second+1)*(it.second+1)) % MOD;
        ans %= MOD;
//        cout << "EXTRA " << it.first << endl;
    }

    cout << ans << endl;

}
