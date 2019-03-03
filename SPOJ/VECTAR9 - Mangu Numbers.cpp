#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define pb(x) push_back(x)
#define MAX 304250263527210LL

using namespace std;

int chkBit(int mask, int p) { return mask & (1<<p); }

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int target;
vi divi;

ll f(ll x) {
    ll ans = 0;
    for(int i=0; i<divi.size(); i++) ans += x/divi[i];
    return ans;
}

int main() {
    target = 1<<13;

    for(int mask=1; mask<target; mask++) {
        ll vag = 1;
        for(int i=0; i<13; i++) if(chkBit(mask, i)) {
            vag *= primes[i];
        }
        if(__builtin_popcount(mask)&1) divi.pb(vag);
        else divi.pb(-vag);
    }
//    cout << divi.back() << endl;


//    cout << f(10) << endl;

    int T;
    scanf("%d", &T);
    while(T--) {
        ll k;
        scanf("%lld", &k);

        ll lo = 1, hi = MAX+1;
        while(lo < hi) {
            ll md = (lo+hi)/2;
            if(f(md) >= k) hi = md;
            else lo = md+1;
        }

        printf("%lld\n", hi);
    }
}
