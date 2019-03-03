///count a^b numbers in [l,r]

#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()

using namespace std;

vl po;

void gen() {
    ll mx = 1e18;
    vl v;
    for(ll i=2; i<=1e6; i++)
    {
        for(ll u = i*i*i; u<=mx; u*=i)
        {
            v.push_back(u);
            if(u > mx/i)
                break;
        }
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());

    for(int i=0; i<(int)v.size(); i++)
    {
        ll u = v[i];
        ll uu = sqrt(u);
        if(uu*uu == u)
            continue;
        po.push_back(u);
    }
//    for(int i=0; i<10; i++) cout << po[i] << ' ' ; cout << endl;
}

int main() {
    gen();

    int T; scanf("%d", &T);
    while(T--) {
        ll l,r;
        scanf("%lld %lld", &l, &r);
        ll ans = upper_bound(all(po), r) - lower_bound(all(po), l);
        ll t1,t2;
        t1 = sqrt(r);
        t2 = sqrt(l-1);
        ans += t1-t2;

        printf("%lld\n", ans);
    }
}

