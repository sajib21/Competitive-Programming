#include<bits/stdc++.h>
#define vi vector<ll>
#define pb(x) push_back(x)
#define ll long long int

using namespace std;

int n,m;
ll k, a[22][22];
vi u[22],v[22];

int main() {
    scanf("%d %d %lld", &n,&m,&k); n--; m--;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

//    cout << "FIRST " << endl;
    for(int mask=0; mask<(1<<n); mask++) {
        int r=0,c=0;
        ll x = a[r][c];
        ll rgt = __builtin_popcount(mask);
        if(rgt > m) continue;

        for(int i=0; i<n; i++) {
            if(mask & (1<<i)) c++;
            else r++;
            x ^= a[r][c];
        }
        u[rgt].pb(x);
//        cout << mask << ' ' << x << endl;
    }

//    cout << "LAST" << endl;
    for(int mask=0; mask<(1<<m); mask++) {
        int r=n,c=m;
        ll x = a[r][c];
        ll lft = __builtin_popcount(mask);
        if(m-lft > n) continue;

        for(int i=0; i<m; i++) {
            if(mask & (1<<i)) c--;
            else r--;
            x ^= a[r][c];
        }
        x ^= a[r][c];
        v[lft].pb(x);
//        cout << mask << ' ' << x << endl;
    }
    for(int i=0; i<=20; i++) sort(u[i].begin(), u[i].end());
    for(int i=0; i<=20; i++) sort(v[i].begin(), v[i].end());

//    cout << "FI" << endl;
//    for(int i=0; i<20; i++) {
//        cout << i << " : ";
//        for(int j=0; j<u[i].size(); j++) cout << u[i][j] << ' ';
//        cout << endl;
//    }
//    cout << "SS" << endl;
//    for(int i=0; i<20; i++) {
//        cout << i << " : ";
//        for(int j=0; j<v[i].size(); j++) cout << v[i][j] << ' ';
//        cout << endl;
//    }


//    cout << "CALC" << endl;

    ll ans = 0;

    for(int i=0; i<=m; i++) { /// make 20
        for(int j=0; j<u[i].size(); j++) {
            ll x = u[i][j]^k;
//            for(int p=0; p<=m; p++) { ///make 20
            int p = m-i;
            ll temp = upper_bound(v[p].begin(), v[p].end(), x)
                    - lower_bound(v[p].begin(), v[p].end(), x);
            ans += temp;
//                cout << i << ' ' << j << ' ' << u[i][j]
//            }
        }
    }
    cout << ans << endl;
}
