#include <bits/stdc++.h>
#define ll long long int
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back
#define segVar  int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define LIM     100005
#define pii     pair<ll,ll>
#define ff      first
#define ss      second

using namespace std;

/// for minimum
struct CHT {
    int ptr,sz;
    vii id, M, C;

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

    void addLine(int in, ll m, ll c) {
        while(sz >= 2 && bad(m,c)) {
            id.pp(); M.pp(); C.pp(); sz--;
        }
        id.pb(in); M.pb(m); C.pb(c);
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
    pii BSQuery(ll x) {
        int lo = 0, hi = sz-2, md;
        if(sz == 1) return pii(M[sz-1]*x + C[sz-1], id[sz-1]);

        if(intersection(hi, hi+1) <= x) return pii(M[sz-1]*x + C[sz-1], id[sz-1]);
        while(lo < hi) {
            md = (lo+hi)/2;
            if(intersection(md,md+1) >= x) hi = md;
            else lo = md+1;
        }
        return pii(M[hi]*x + C[hi], id[hi]);
    }
};

int n,q, C[LIM], M[LIM];
CHT segTree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node].addLine(st, M[st], C[st]);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1, ed);

    int i=0, j=0;
    while(i < segTree[lft].sz && j < segTree[rgt].sz) {
        if(segTree[lft].M[i] == segTree[rgt].M[j]) {
            if(segTree[lft].C[i] > segTree[rgt].C[j]) j++;
            else i++;
        }
        else if(segTree[lft].M[i] < segTree[rgt].M[j]) {
            segTree[node].addLine(segTree[lft].id[i], segTree[lft].M[i], segTree[lft].C[i]);
            i++;
        }
        else {
            segTree[node].addLine(segTree[rgt].id[j], segTree[rgt].M[j], segTree[rgt].C[j]);
            j++;
        }
    }
    while(i < segTree[lft].sz) segTree[node].addLine(segTree[lft].id[i], segTree[lft].M[i], segTree[lft].C[i]), i++;
    while(j < segTree[rgt].sz) segTree[node].addLine(segTree[rgt].id[j], segTree[rgt].M[j], segTree[rgt].C[j]), j++;
}

pii query(int node, int st, int ed, int l, int r, int x) {
    if(ed < l || st > r) return pii(0,0);
    if(st >= l && ed <= r) return segTree[node].BSQuery(x);
    segVar;
    return max( query(lft, st,md, l,r, x) , query(rgt, md+1,ed, l,r, x) );
}

int main() {
    scanf("%d %d", &n,&q);
    for(int i=0; i<n; i++) scanf("%d %d", &C[i], &M[i]);
//    for(int i=0; i<n; i++) scanf("%d", &M[i]);

    init(1, 0,n-1);
    while(q--) {
        int x,y,t;
        scanf("%d %d %d", &x, &y, &t); x--; y--;
        pii ans = query(1, 0,n-1, x,y, t);
//        cout << ans.ff << ' ' << ans.ss << endl;
        printf("%lld\n", ans.ss+1);
    }
}

