#include <bits/stdc++.h>
#define ll long long int
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back
#define LIM     200005

using namespace std;

/// for minimum
struct CHT {
    int ptr,sz;
    vii M, C;

    CHT() {
        ptr = sz = 0;
        M.clear(); C.clear();
    }

//    bool bad(ll m, ll c) { ///minimization
//        return (C[sz-2] - C[sz-1]) * 1.0 / (C[sz-1] - c) >= (M[sz-1] -M[sz-2]) * 1.0 / (m - M[sz-1]);
//    }
    bool bad(ll m, ll c) { ///max
        return (long double) (c - C[sz-2]) / (1.0*M[sz-2] - m) < (long double) (C[sz-1] - C[sz-2]) / (1.0*M[sz-2] - M[sz-1]);
    }
    void addLine(ll m, ll c) {
        while(sz >= 2 && bad(m,c)) {
            M.pp(); C.pp(); sz--;
        }
        M.pb(m); C.pb(c);
        sz++;
    }

    void printHull() {
        cout << "HULL" << endl;
        for(int i=0; i<sz; i++) cout << i << " : " << M[i] << ' ' << C[i] << endl;
    }

    ll getY(int pos, ll x) {
        return M[pos]*x + C[pos];
    }

    ll sortedQuery(ll x) {
        /// first e mone hoy ptr kn sz er boro hobe
        /// but vitore line dhukar somoy sz, ptr er choto hoya jaite pare
        if(ptr >= sz) ptr = sz - 1;
        while(ptr < sz-1 && getY(ptr+1, x) <= getY(ptr, x)) ptr++;
        return M[ptr]*x + C[ptr];
    }

    double intersection(int a, int b) {
        return -1.0 * (C[a]-C[b])/(M[a]-M[b]);
    }
    ll BSQuery(ll x) {
        int lo = 0, hi = sz-2, md;
        if(sz == 1) {
//            cout << "YES " << M[sz-1] << ' ' << C[sz-1] << ' ' << x << ' ' << getY(sz-1, x) << endl;
            return getY(sz-1, x);
        }

        if(intersection(hi, hi+1) <= x) return M[sz-1]*x + C[sz-1];
        while(lo < hi) {
            md = (lo+hi)/2;
            if(intersection(md,md+1) >= x) hi = md;
            else lo = md+1;
        }
        return M[hi]*x + C[hi];
    }
};

int n;
ll a[LIM], lft[LIM], rgt[LIM], M[LIM], S[LIM], ans;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=n; i++) lft[i] = lft[i-1] + i*a[i];
    for(int i=n; i>=1; i--) rgt[i] = rgt[i+1] + i*a[i];
    for(int i=1; i<=n; i++) M[i] = M[i-1] + i*a[i];
    for(int i=1; i<=n; i++) S[i] = S[i-1] + a[i];

    CHT cht = CHT();
    ans = lft[n];

    for(int i=1; i<=n; i++) {
        cht.addLine(i, lft[i-1]-M[i-1]-S[i-1]);
//        cht.printHull();
//        cout << cht.BSQuery(a[i]) << endl;
        ans = max(ans, cht.BSQuery(a[i]) + rgt[i+1] + M[i-1] + S[i-1]);
    }

    cht = CHT();
    for(int i=n; i>=1; i--) {
        cht.addLine(-i, rgt[i+1]+M[i]-S[i]);
        ans = max(ans, cht.BSQuery(-a[i]) + lft[i-1] - M[i] + S[i]);
    }

    printf("%lld\n", ans);
}
