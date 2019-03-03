#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define LIM 2003
#define ll long long int

using namespace std;

int n, x[LIM], y[LIM];

pii dhal(int i, int j) {
    int dx = x[i]-x[j];
    int dy = y[i]-y[j];
//    if(dx < 0) {
//        dx = -dx; dy = -dy;
//    }

    int g = __gcd(dx,dy);
    return pii(dy/g, dx/g);
}

int main() {
//    cout << __gcd(-2, -4) << endl;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);

    ll ans = 1LL*n*(n-1)*(n-2);

    for(int i=0; i<n; i++) {
        map<pii,int>koyta;
        for(int j=0; j<n; j++) if(i != j) {
//            pii temp = dhal(i,j);
//            cout << "DHAL " << i << ' ' << j << ' ' << temp.ff << ' ' << temp.ss << endl;
            koyta[dhal(i,j)]++;
        }
//        cout << i << " BUG" << endl;

        for(auto it : koyta) {
            int x = it.ss;
            ans -= 1LL*x*(x-1);
//            cout << ' ' <<
        }
    }

    cout << ans/6 << endl;
}
