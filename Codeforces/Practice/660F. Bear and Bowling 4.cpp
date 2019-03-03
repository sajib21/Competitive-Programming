#include <bits/stdc++.h>
#define ll long long int
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back
#define LIM     200005


using namespace std;

/// for minimum
struct CHT {
//    bool f = false;
    int ptr,sz;
    vii M, C;

    CHT() {
        ptr = sz = 0;
        M.clear(); C.clear();
    }

//    bool bad(ll m, ll c) { /// min
//        return (long double) (C[sz-2] - C[sz-1]) * 1.0 / (C[sz-1] - c) > (long double) (M[sz-1] -M[sz-2]) * 1.0 / (m - M[sz-1]);
//    }
    bool bad(ll m, ll c) { ///max
        return (long double) (c - C[sz-2]) / (1.0*M[sz-2] - m) < (long double) (C[sz-1] - C[sz-2]) / (1.0*M[sz-2] - M[sz-1]);
    }

    void addLine(ll m, ll c) { ///desc slopes, desc cons for min
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

    ll sortedQuery(ll x) { /// <= : min; >= max;
        if(ptr >= sz) ptr = sz - 1;
        while(ptr < sz-1 && getY(ptr+1, x) >= getY(ptr, x)) ptr++;
        return M[ptr]*x + C[ptr];
    }

    double intersection(int a, int b) {
        return -1.0 * (C[a]-C[b])/(M[a]-M[b]);
    }

    ll BSQuery(ll x) {
        int lo = 0, hi = sz-2, md;

        if(sz == 1) return M[sz-1]*x + C[sz-1];
//        if(sz == 2)

        if(intersection(hi, hi+1) <= x) return M[sz-1]*x + C[sz-1];
//        cout << "BUG x " << x << ' ' << lo << ' ' << hi << endl;
        while(lo < hi) {
            md = (lo+hi)/2;

//            if(f) cout << lo << ' ' << hi << ' ' << md << ' ' << intersection(md,md+1) << ' ' << x << endl;

            if(intersection(md,md+1) >= x) hi = md;
            else lo = md+1;
        }
        return M[hi]*x + C[hi];
    }
};

ll n, a[LIM], S[LIM], M[LIM];

int main() {//freopen("in.txt", "r", stdin);
//    int T;
//    scanf("%d", &T);
//    for(int t=1; t<=T; t++) {
        scanf("%lld", &n);
        for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
        for(int i=1; i<=n; i++) S[i] = S[i-1] + a[i];
        for(int i=1; i<=n; i++) M[i] = M[i-1] + i*a[i];

//        for(int i=1; i<=n; i++) cout << S[i] << ' '; cout << endl;
//        cout << a << ' ' << b << ' ' << c << endl;

        CHT cht = CHT();
        ll dp = 0;
        ll ans = 0;

        cht.addLine(0,0);

        for(int i=1; i<=n; i++) {
//            if(i == n) cht.f = true;
            dp = max(dp, M[i] + cht.BSQuery(-S[i]));
            cht.addLine(i, -M[i]+i*S[i]);
//            cout << M[i] << ' ' << cht.BSQuery(-S[i]) << endl;

        }
        printf("%lld\n", dp);
//        cht.printHull();
//    }
}
