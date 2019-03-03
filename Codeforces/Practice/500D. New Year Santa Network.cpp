///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     100000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

struct info{
    int x,y,z;
    ll c;
    info() {}
    info(int xx, int yy, int zz, ll cc = 0) {
        x = xx; y = yy; z = zz; c = cc;
    }
};

int n,q, sub[LIM+10], vis[LIM+10];
info edge[LIM+10];
vii graph[LIM+10];

int dfs(int u) {
    vis[u] = 1;
    int cnt = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            cnt += dfs(v);
        }
    }
    return sub[u] = cnt;
}

ll segTree[4*LIM+10];
void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = edge[st].z * edge[st].c;
        return;
    }
    segVar;
    init(lft, st,  md); init(rgt, md+1,ed);
    segTree[node] = segTree[lft] + segTree[rgt];
}
void update(int node, int st, int ed, int p, int val) {
    if(ed < p || st > p) return;
    if(st >= p && ed <= p) {
        segTree[node] = val * edge[st].c;
        return;
    }
    segVar;
    update(lft, st,  md, p, val); update(rgt, md+1,ed, p , val);
    segTree[node] = segTree[lft] + segTree[rgt];
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);
        edge[i] = info(u,v,w);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    for(int i=1; i<n; i++) {
        int u = edge[i].x , v = edge[i].y;
        int cnt = min(sub[u], sub[v]);
        edge[i].c =1LL* cnt * (n-cnt);
    }
    init(1, 1,n);
    scanf("%d", &q);
    while(q--) {
        int ch,val;
        scanf("%d %d", &ch,&val);
        update(1, 1,n, ch, val);
        ll sum = segTree[1];
        printf("%.10lf\n", 6.0*sum/( 1LL*n*(n-1) ));
    }


    return 0;
}
