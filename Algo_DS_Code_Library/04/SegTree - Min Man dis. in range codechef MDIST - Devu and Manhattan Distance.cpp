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
#define LIM 100005
#define segVar int lft=2*node, rgt=2*node+1, md=(st+ed)/2
#define pii pair<ll,ll>
#define ff first
#define ss second
#define ll long long int


using namespace std;

int n,q, x,y,p;
ll a[5][LIM];
char cmd[123];
pii segTree[5][4*LIM]; ///ff : max, ss : min

ll f1(int x, int y) { return + x + y; }
ll f2(int x, int y) { return - x + y; }
ll f3(int x, int y) { return + x - y; }
ll f4(int x, int y) { return - x - y; }

void init(int node, int st, int ed) {
    if(st == ed) {
        for(int i=1; i<=4; i++) segTree[i][node] = pii(a[i][st], a[i][st]);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    for(int i=1; i<=4; i++) segTree[i][node] =
        { max(segTree[i][lft].ff, segTree[i][rgt].ff) , min(segTree[i][lft].ss, segTree[i][rgt].ss) };

}
void update(int node, int st, int ed, int p, int x, int y) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[1][node] = pii( f1(x,y), f1(x,y) );
        segTree[2][node] = pii( f2(x,y), f2(x,y) );
        segTree[3][node] = pii( f3(x,y), f3(x,y) );
        segTree[4][node] = pii( f4(x,y), f4(x,y) );

        return;
    }
    segVar;
    update(lft, st,md, p, x,y); update(rgt, md+1,ed, p, x,y);
    for(int i=1; i<=4; i++) segTree[i][node] =
        { max(segTree[i][lft].ff, segTree[i][rgt].ff) , min(segTree[i][lft].ss, segTree[i][rgt].ss) };

}

pii query(int in, int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return {LLONG_MIN, LLONG_MAX};
    if(st >= l && ed <= r) return segTree[in][node];
    segVar;
    pii p,q, ans;
    p = query(in, lft, st,md, l,r);
    q = query(in, rgt, md+1,ed, l,r);
    ans = { max(p.ff, q.ff) , min(p.ss, q.ss) };
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d %d", &x,&y);
        a[1][i] = +x +y;
        a[2][i] = -x +y;
        a[3][i] = +x -y;
        a[4][i] = -x -y;
    }

    init(1, 0,n-1);

    scanf("%d", &q);
    while(q--) {
        scanf("%s", cmd);
        if(cmd[0] == 'U') {
            scanf("%d %d %d", &p, &x,&y);
            update(1, 0,n-1, p, x,y);
        }
        else {
            scanf("%d %d", &x, &y);
            ll ans = LLONG_MIN;
            for(int i=1; i<=4; i++) {
                pii temp = query(i, 1, 0,n-1, x,y);
                ans = max(ans, 1LL*temp.ff-temp.ss );
            }
            assert(ans >= 0);
            printf("%lld\n", ans);
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
