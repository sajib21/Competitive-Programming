#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,k;

bool f(ll x) {
    ll ans = 0;
    for(int i=1; i<=min(x, n); i++) {
        ans += min( m, x/i );
        if(ans >= k) return true;
    }
    return false;
}

int main() {
    cin >> n >> m >> k;
//    scanf("%I64d %I64d %I64d", &n,&m,&k);
    ll hi = n*m;
    ll lo = 1;

    while(lo < hi) {
        ll md = (lo+hi)/2;
//        cout << lo << ' ' << hi << ' ' << md << endl;
        if(f(md)) hi = md;
        else lo = md+1;
    }
//    printf("%I64d\n", hi);
    cout << hi << endl;
}
