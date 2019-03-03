/**
update(st,ed, v, 0) := range update; make a[i] = v;
update(st,ed, v, 1) := range update; make a[i] += v;
query(st,ed) := ( plain_sum(st,ed), square_sum(st,ed),
                 max(a[st..ed]), min(a[st..ed]) )

make sure the update types can either be merged or
one can totally nullify the other. otherwise,
you have to keep variable number of lazy propagations,
which gives huge complexity.

**/

#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int
#define segVar int lft=2*node, rgt=2*node+1, md=(st+ed)/2
#define sqr(x) ( (x) * (x) )
#define MAXX 1000000000000000000

using namespace std;

struct Real {
    ll p,q;
    Real() {p=0, q=1;}
    Real(ll pp) {p = pp; q = 1;}
    Real(ll pp, ll qq) {
        ll g = __gcd(pp,qq);
        p = pp/g;
        q = qq/g;
    }
    Real operator - (const Real &b) const {
        ll GCD = __gcd(q, b.q);
        ll LCM = q/GCD * b.q;

        Real ANS;
        ANS.q = LCM;
        ANS.p = LCM / q * p - LCM / b.q * b.p;
        ll g = __gcd(ANS.p, ANS.q);
        ANS.p /= g;
        ANS.q /= g;

        return ANS;
    }
};

struct info {
    ll x, y,z; int p; /// x=plain, y=sqr, z=prop, p = type
    ll mx, mn;
    info() {
        x=y=z=0;
        p = -1;
        mx = LLONG_MIN;
        mn = LLONG_MAX;
    }
    info(ll xx) {
        x = xx; y = xx*xx;
        z = 0; p = -1;
        mn = mx = x;
    }
    info(ll xx, ll yy, ll mxx, ll mnn) {
        x = xx; y = yy;
        mx = mxx; mn = mnn;
        z = 0; p = -1;
    }
    info(ll xx, ll yy, ll mxx, ll mnn, ll zz, int pp) {
        x = xx; y = yy;
        mx = mxx;
        mn = mnn;
        z = zz; p = pp;
    }
    info operator + (const info &b) const {
        return info(x+b.x, y+b.y, max(mx, b.mx), min(mn, b.mn) );
    }
};

int n,m; ll a[LIM];
info segTree[4*LIM], ranTree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = info(a[st]);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = segTree[lft] + segTree[rgt];
}

///called when actual update is done on data (lazy/main)
void balance(int node, int st, int ed, ll cv, int ct) {
    int M = ed-st+1;
    ll agerplain = segTree[node].x;
    ll agersquar = segTree[node].y;
    if(ct == 0) {
        ///if 0 type update, previous info are erased
        segTree[node] = info(M*cv, M*sqr(cv), cv, cv, cv, 0);
    }
    else if(ct == 1) {
        ///otherwise value added
        segTree[node].x += M*cv;
        segTree[node].y += 2*cv*agerplain + M*sqr(cv);
        segTree[node].z += cv;
        segTree[node].mx += cv;
        segTree[node].mn += cv;

        if(segTree[node].p == 0) {
            ///if previously 0 type update was in lazy, then,
            ///after a[st..ed] += v, it still remains 0 type
            ///(this was the trickiest part for me)
            segTree[node].p = 0;
        }
        else {
            ///otherwise 1 type update
            segTree[node].p = 1;
        }
    }
}

void update(int node, int st, int ed, int l, int r, ll uv, int ut, ll cv=0, int ct=-1) {
    balance(node, st,ed, cv, ct);

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        balance(node, st,ed, uv,ut);
        return;
    }
    segVar;
    cv = segTree[node].z; ct = segTree[node].p;
    segTree[node].z = 0, segTree[node].p = -1;

    update(lft,   st,md, l,r, uv,ut, cv,ct);
    update(rgt, md+1,ed, l,r, uv,ut, cv,ct);
    segTree[node] = segTree[lft] + segTree[rgt];
}

info query(int node, int st, int ed, int l, int r, ll cv=0, int ct=-1) {
    balance(node, st,ed, cv, ct);

    if(ed < l || st > r) return info();
    if(st >= l && ed <= r) {
        return info(segTree[node].x, segTree[node].y, segTree[node].mx, segTree[node].mn);
    }
    segVar;
    cv = segTree[node].z; ct = segTree[node].p;
    segTree[node].z = 0, segTree[node].p = -1;

    return query(lft, st,md, l,r, cv,ct) + query(rgt, md+1,ed, l,r, cv,ct);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
        init(1, 1,n);

        printf("Case %d:\n", t);
        while(m--) {
            int c, l,r; ll v;
            scanf("%d %d %d", &c, &l, &r);
            if(c < 2) scanf("%lld", &v);

            if(c == 2) {
                info temp = query(1, 1,n, l,r);
                ll M = (r-l+1);
//                cout << "RAW " << temp.x << ' ' << temp.y << ' ' << temp.mx << ' ' << temp.mn << endl;
                Real SQ = Real(temp.y, M);
                Real PL = Real(sqr(temp.x), sqr(M));
                Real ans = SQ - PL;
                printf("%lld/%lld %lld\n", ans.p, ans.q, temp.mx - temp.mn);
            }
            else update(1, 1,n, l,r, v,c);
        }
    }
}
