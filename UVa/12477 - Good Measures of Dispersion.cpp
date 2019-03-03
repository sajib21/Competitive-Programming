#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define MAX 1000000000000000018

using namespace std;

struct info {
    ll x,y,z, p; ///x = plain sum, y = squared sum, z = lazy, p = lazy type
    ll mx,mn;
    info() {} ///p : 0 = empty, 1 = change, 2 = add
    info(ll xx, ll yy, ll mxx, ll mnn, ll zz=0, ll pp=0) {
        x = xx; y = yy; z = zz; p = pp;
        mx = mxx; mn = mnn;
    }
    info operator + (const info &b) const {
        info ans;
        ans.x = x+b.x; ans.y = y+b.y; ans.mx = max(mx,b.mx); ans.mn = min(mn,b.mn);
        return ans;
    }
};

int n,q;
ll a[LIM];
info segTree[8*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = info(a[st], a[st]*a[st], a[st], a[st]);
//        cout << "INIT " << node << ' ' << st << ' ' << ed << ' ' << segTree[node].x << ' ' << segTree[node].y << ' ' << segTree[node].mx << ' ' << segTree[node].mn << endl;

        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = segTree[lft]+segTree[rgt];
//    cout << "INIT " << node << ' ' << st << ' ' << ed << ' ' << segTree[node].x << ' ' << segTree[node].y << ' ' << segTree[node].mx << ' ' << segTree[node].mn << endl;
}

void pushDown(int node, int st, int ed, int v, int type) {
    ll m = ed-st+1;
    segVar;
    if(type == 1) {
        segTree[node] = info(m*v, m*v*v, v,v, v, type);
    }
    else if(type == 2) {
        ll x = segTree[node].x, y = segTree[node].y, z = segTree[node].z;
        ll p = segTree[node].p, mx = segTree[node].mx, mn = segTree[node].mn;

        if(p == 1) {
            pushDown(lft,   st,md, z,p);
            pushDown(rgt, md+1,ed, z,p);
            z = p = 0;
        }
        segTree[node] = info(x+m*v, y+m*v*v+2*v*x, mx+v, mn+v, z+v, type);
    }
}

void update(int node, int st, int ed, int l, int r, int v=0, int vt=0, int c=0, ll ct=0) {
    pushDown(node, st,ed, c, ct);
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        pushDown(node, st,ed, v,vt);
        return;
    }
    segVar;
    ll z = segTree[node].z, p = segTree[node].p;
    segTree[node].z = segTree[node].p = 0;
    update(lft, st, md,  l,r, v,vt, z,p);
    update(rgt, md+1,ed, l,r, v,vt, z,p);
    segTree[node] = segTree[lft]+segTree[rgt];
//    cout << "UP " << node << ' ' << st << ' ' << ed << ' ' << segTree[node].x << ' ' << segTree[node].y << ' ' << segTree[node].mx << ' ' << segTree[node].mn << endl;

}

info query(int node, int st, int ed, int l, int r, int c=0, int ct=0) {
    pushDown(node, st,ed, c,ct);
    if(ed < l || st > r) return info(0,0,-MAX,MAX);
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    ll z = segTree[node].z, p = segTree[node].p;
    segTree[node].z = segTree[node].p = 0;
    return query(lft, st,md, l,r, z,p) + query(rgt, md+1,ed, l,r, z,p);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&q);
        for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
        init(1, 1,n);

//        for(int i=1; i<=40; i++) {
//            info xx = segTree[i];
//            cout << i << ' ' << xx.x << ' ' << xx.y << ' ' << xx.mx << ' ' << xx.mn << endl;
//        }

        printf("Case %d:\n", t);

        while(q--) {
            ll c,x,y,z;
            scanf("%lld", &c);
            if(c == 0) {
                scanf("%lld %lld %lld", &x,&y, &z);
                update(1, 1,n, x,y, z, 1);
            }
            else if(c == 1) {
                scanf("%lld %lld %lld", &x,&y, &z);
                update(1, 1,n, x,y, z, 2);
            }
            else if(c == 2) {

                scanf("%lld %lld", &x,&y);
                info ans = query(1, 1,n, x,y);

//                cout << ans.x << ' ' << ans.y << ' ' << ans.mx << ' ' << ans.mn << endl;

                ll m = (y-x+1);
                ans.y *= m;
                ans.x *= ans.x;

                ll num = ans.y - ans.x;;
                ll den = m*m;
                ll g = __gcd(num, den);
                num /= g;
                den /= g;


                printf("%lld/%lld %lld\n", num,den, ans.mx-ans.mn );
            }

        }
    }
}
