#include<bits/stdc++.h>
#define ll long long int
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

int n;
ll xa,xb, k,b;
pll y[100005];

int main() {
    scanf("%d", &n);
    scanf("%lld %lld", &xa, &xb);

    for(int i=0; i<n; i++) {
        scanf("%lld %lld", &k,&b);
        y[i].ff = k*xa + b;
        y[i].ss = k*xb + b;
    }
//cout << "DATA" << endl;
//    for(int i=0; i<n; i++) cout << y[i].ff << ' ' << y[i].ss << endl;
    sort(y, y+n);



    ll last = y[0].ss;
    for(int i=1; i<n; i++) {
        if(y[i].ss < last) {
            cout << "YES" << endl;
            return 0;
        }
        else {
            last = y[i].ss;
        }
    }
    cout << "NO" << endl;
}
