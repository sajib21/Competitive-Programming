/*
Maximum Manhattan distance:

dist(P1, P2) = |x1 - x2| + |y1 - y2|
             = max(  x1 - x2 +  y1 - y2,
                    -x1 + x2 +  y1 - y2,
                     x1 - x2 + -y1 + y2,
                    -x1 + x2 + -y1 + y2) )
             = max(  ( x1 + y1) - ( x2 + y2),
                     (-x1 + y1) - (-x2 + y2),
                     ( x1 - y1) - ( x2 - y2),
                     (-x1 - y1) - (-x2 - y2) )
             = max( f1(P1) - f1(P2),
                    f2(P1) - f2(P2),
                    f3(P1) - f3(P2),
                    f4(P1) - f4(P2) )
where f1(P) = x+y, f2(P) = -x+y, f3(P) = x-y, f4(P) = -x-y

max(P1,P2){dist(P1,P2)}
    = max(P1,P2){max(f1(P1)-f1(P2),f2(P1)-f2(P2),f3(P1)-f3(P2),f4(P1)-f4(P2))}
    = max( maxP{f1(P)}-minP{f1(P)} , maxP{f2(P)}-minP{f2(P)} ,
           maxP{f3(P)}-minP{f3(P)} , maxP{f4(P)}-minP{f4(P)} )

Now, for range query, use segment tree!!
*/

#include<bits/stdc++.h>
#define LIM 200005
#define segVar int lft=2*node, rgt=2*node+1, md=(st+ed)/2
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long int


using namespace std;

int n,k, q;
char cmd[123];
pii segTree[40][4*LIM]; ///ff : max, ss : min

int f(int in, int x[]) {
    int ans = 0;
    for(int i=0; i<5; i++) {
        if(in%2==0) ans += x[i];
        else ans -= x[i];
        in /= 2;
    }
    return ans;
}

void update(int node, int st, int ed, int p, int x[]) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        for(int i=0; i<32; i++) {
            segTree[i][node] = pii( f(i, x), f(i, x) );
        }
        return;
    }
    segVar;
    update(lft, st,md, p, x); update(rgt, md+1,ed, p, x);
    for(int i=0; i<32; i++) segTree[i][node] =
        { max(segTree[i][lft].ff, segTree[i][rgt].ff) , min(segTree[i][lft].ss, segTree[i][rgt].ss) };

}

pii query(int in, int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return {INT_MIN, INT_MAX};
    if(st >= l && ed <= r) return segTree[in][node];
    segVar;
    pii p,q, ans;
    p = query(in, lft, st,md, l,r);
    q = query(in, rgt, md+1,ed, l,r);
    ans = { max(p.ff, q.ff) , min(p.ss, q.ss) };
    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int in=0; in<32; in++)
        for(int i=0; i<4*n; i++)
            segTree[in][i].ff = INT_MIN, segTree[in][i].ss = INT_MAX;

    for(int i=1; i<=n; i++) {
        int x[10] = {0};
        for(int i=0; i<k; i++) scanf("%d", &x[i]);
        update(1, 1,n, i, x);
    }

    scanf("%d", &q);
    while(q--) {
        int t, p, x[10] = {0}, u,v;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d", &p);
            for(int i=0; i<k; i++) scanf("%d", &x[i]);
            update(1, 1,n, p, x);
        }
        else {
            scanf("%d %d", &u, &v);
            int ans = INT_MIN;
            for(int i=0; i<32; i++) {
                pii temp = query(i, 1, 1,n, u,v);
                ans = max(ans, temp.ff-temp.ss );
            }
            printf("%d\n", ans);
        }
    }

}

/*
2
1000000000 1000000000
-1000000000 -1000000000
1
Q 0 1
*/
