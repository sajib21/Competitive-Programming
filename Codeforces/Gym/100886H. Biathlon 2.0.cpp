#include <bits/stdc++.h>
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back
#define LIM     500005
#define pii     pair<ll,ll>
#define ff      first
#define ss      second
#define ll      long long int
#define EPS     1e-9

using namespace std;

bool cmp(pii a, pii b) {
    return (a.ff == b.ff && a.ss < b.ss) || a.ff > b.ff;
}

/// for minimum
struct CHT {
    int ptr, sz;
    vii M, B; /// y = Mx + C

    CHT() {
        ptr = sz = 0;
        M.clear(); B.clear();
    }

    bool bad(ll m, ll b) {
        return (b-B[sz-2])*(M[sz-2]-M[sz-1]) < (B[sz-1]-B[sz-2])*(M[sz-2]-m);
    }
    void addLine(int m, int b) {
        if(!M.empty() && M.back() == m) return;
        while(M.size() >= 2 && bad(m,b)) {
            M.erase(M.end()-1); B.erase(B.end()-1); sz--;
        }
        M.pb(m); B.pb(b);
        sz++;
    }

    void printHull() {
        for(int i=0; i<sz; i++) cout << i << " : " << M[i] << ' ' << B[i] << endl;
    }

    double getY(int pos, double x) {
        return M[pos]*x + B[pos];
    }
    ll sortedQuery(ll c, ll d) { /// pointer
        double x = 1.0*c/d;
        while(ptr < M.size()-1 && getY(ptr+1, x) <= getY(ptr, x) + EPS ) ptr++;
        ll ans = M[ptr]*c + B[ptr]*d;
        return ans;
    }
    int BSQuery(int x) { /// binary search

    }
};

bool cmpx(pair<pii,pii>a, pair<pii,pii> b) {
    return 1.0*a.ss.ff/a.ss.ss <= 1.0*b.ss.ff/b.ss.ss ;
}
bool cmpy(pair<pii,pii>a, pair<pii,pii>b) {
    return a.ff.ff < b.ff.ff;
}

int n,m;
pii lines[LIM];
pair<pii,pii> q[LIM];

int main() {
    CHT cht;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld %lld", &q[i].ss.ff, &q[i].ss.ss);
        q[i].ff.ff = i;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%lld %lld", &lines[i].ff, &lines[i].ss);
    sort(lines, lines+m, cmp);
    sort(q, q+n, cmpx);

    for(int i=0; i<m; i++) cht.addLine(lines[i].ff, lines[i].ss);

    for(int i=0; i<n; i++) q[i].ff.ss = cht.sortedQuery(q[i].ss.ff, q[i].ss.ss);
    sort(q, q+n, cmpy);

    for(int i=0; i<n; i++) {
        if(i) printf(" ");
        printf("%lld", q[i].ff.ss );
    }
    printf("\n");

    return 0;
}
