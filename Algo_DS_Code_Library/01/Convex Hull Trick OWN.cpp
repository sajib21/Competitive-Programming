#include <bits/stdc++.h>
#define ll long long int
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back

using namespace std;

/// for minimum
struct CHT {
    int ptr,sz;
    vii M, C;

    CHT() {
        ptr = sz = 0;
        M.clear(); C.clear();
    }

    bool bad(ll m, ll c) { ///minimization
        return (C[sz-2] - C[sz-1]) * 1.0 / (C[sz-1] - c) >= (M[sz-1] -M[sz-2]) * 1.0 / (m - M[sz-1]);
    }
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
        if(sz == 1) return M[sz-1]*x + C[sz-1];

        if(intersection(hi, hi+1) <= x) return M[sz-1]*x + C[sz-1];
        while(lo < hi) {
            md = (lo+hi)/2;
            if(intersection(md,md+1) >= x) hi = md;
            else lo = md+1;
        }
        return M[hi]*x + C[hi];
    }
};


int main() {
    CHT cht = CHT();

    ///any number of groups
    ll dp = 0;
    for(int i=0; i<in; i++) {
        dp = cht.sortedQuery(pure[i].ff);
        cht.addLine(pure[i+1].ss, dp);
    }

    ///divide in exactly k groups
    ll dp[3][LIM];
    for(int i=2; i<=k; i++) {
        cht = CHT();
        for(int j=i; j<=n; j++) {
            cht.addLine(-S[j-1], M[j-1]+dp[(i-1)%2][j-1]);
            dp[i%2][j] = x[j]*S[j] + cht.sortedQuery(x[j]) - M[j];
        }
    }
    printf("%lld\n", dp[k%2][n]);
}
