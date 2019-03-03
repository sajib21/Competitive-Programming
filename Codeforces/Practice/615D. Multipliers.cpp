#include<bits/stdc++.h>
#define vi      vector<int>
#define pb(x)   push_back(x)
#define LIM     200005
#define MOD     1000000007
#define ll      long long int


using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }
ll sum(ll x) {
    return x*(x+1)/2;
}

int n,x;
map<int,int>koyta;
vi primes, counts;
ll lft[LIM], rgt[LIM];
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        koyta[x]++;
    }

    for(auto it : koyta) {
        primes.pb(it.first);
        counts.pb(it.second);
    }
    n = primes.size();

    lft[0] = counts[0]+1;
    for(int i=1; i<counts.size(); i++) {
        lft[i] = (counts[i]+1)*lft[i-1];
        lft[i] %= (MOD-1);
    }
    rgt[n-1] = counts[n-1]+1;
    for(int i=n-2; i>=0; i--) {
        rgt[i] = (counts[i]+1)*rgt[i+1];
        rgt[i] %= (MOD-1);
    }


    ll ans = 1;

    for(int i=0; i<primes.size(); i++) {
        ll p = primes[i];
        ll c = counts[i];



        ll po = 1;
        if(i) po *= lft[i-1];
        if(i<n-1) po *= rgt[i+1];
        po %= (MOD-1);

//        cout << "IN " << p << ' ' << c << ' ' << sum(c) << ' ' << bigMod(p, sum(c), MOD ) << ' ' << po << ' ' << bigMod( bigMod(p, sum(c), MOD ) , po , MOD ) << endl;

        ans *= bigMod( bigMod(p, sum(c), MOD ) , po , MOD );
        ans %= MOD;
    }

    cout << ans << endl;


}
