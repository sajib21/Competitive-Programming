#include<bits/stdc++.h>
#define ll      long long int
#define vl      vector<ll>
#define pll     pair<ll,ll>
#define vp      vector<pll>
#define pb(x)   push_back(x)

using namespace std;

int main() {
    int n;
    ll x,y;
    vl pts;
    vp seg;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld %lld", &x,&y);
        pts.pb(r*x-y); pts.pb(r*x+y);
        seg.pb(pll(r*x-y, r*x+y));
    }
    sort(pts.begin(), pts.end());
    sort(seg.begin(), seg.end());

    stack<int>
}
