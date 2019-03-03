#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int
#define vl vector<ll>
#define pb push_back
#define pp pop_back

using namespace std;

struct CHT {
    int ptr,sz;
    vl M, C;

    CHT() {
        ptr = sz = 0;
        M.clear(); C.clear();
    }

    bool bad(ll m, ll c) {
        return (C[sz-2] - C[sz-1]) * 1.0 / (C[sz-1] - c) >= (M[sz-1] -M[sz-2]) * 1.0 / (m - M[sz-1]);
    }
    void addLine(ll m, ll c) {
        while(sz >= 2 && bad(m,c)) {
            M.pp(); C.pp(); sz--;
        }
        M.pb(m); C.pb(c);
        sz++;
    }

    void printHull() {
        cout << "HULL" << endl;o
        for(int i=0; i<sz; i++) cout << i << " : " << M[i] << ' ' << C[i] << endl;
    }

    ll getY(int pos, ll x) {
        return M[pos]*x + C[pos];
    }

    ll sortedQuery(ll x) {
        while(ptr < sz-1 && getY(ptr+1, x) <= getY(ptr, x)) ptr++;
        return M[ptr]*x + C[ptr];
    }
};

int n;
ll a[LIM], b[LIM];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%I64d", &a[i]);
    for(int i=0; i<n; i++) scanf("%I64d", &b[i]);
//    a[n-1]--;

//    for(int i=1; i<n; i++) a[i] += a[i-1];

    CHT cht;

    cht.addLine(b[0], 0);

//    cht.printHull();

    ll ans = 0;
    for(int i=1; i<n; i++) {
//        cht.printHull();
        ans = cht.sortedQuery(a[i]);
        cht.addLine(b[i], ans);
//        cout << "QYERY " << i << ' ' << cht.ptr << ' ' << cht.M[cht.ptr] << ' ' << cht.C[cht.ptr] << ' ' << ans << endl;

    }
    printf("%I64d\n", ans);
}
