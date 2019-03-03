///YOU DON'T HAVE TO USE BOTH LEFT AND RIGHT CALLS IN SEGMENT TREE QUERY IF YOU ARE NOT UPDATING ANYTHING.
///BUT IF YOU ARE UPDATING IN QUERY FUNCTION THEN YOU MUST CALL IN BOTH DIRECTION.
///DON'T WASTE A FULL DAY ON THIS THING AGAIN. :)

/// PS: I THOUGHT THAT THIS PROBLEM NEEDED TO UPDATE EVERYWHERE BUT THE UPDATE IS A NORMAL RANGE UPDATE AS LAZY PROPAGATION.
/// THINK BEFORE YOU ACT YOU DUMBASS!!


#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 30000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int n,q, genies[LIM+10];
vii graph[LIM+10];

int vis[LIM+10], subTreeEnd[LIM+10], mask[LIM+10], msk;
int lev[LIM+10], sparse[LIM+10][20], cost[LIM+10];

struct info{
    int val, prop;
    info() {}
    info(int vv, int pp) {
        val = vv; prop = pp;
    }
};

info segTree[4*LIM+100];


void dfs(int u, int cst = 0, int l = 0) {
    vis[u] = 1;
    lev[ u ] = l;
    cost[ mask[u] ] = genies[u] + cst;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            mask[v] = ++msk;
            dfs(v, cost[ mask[u] ], l+1);
            sparse[ v ][0] = u;
        }
    }
    subTreeEnd[u] = msk;
}

void makeSparse() {
    int lim = log2(n) + 1;
    for(int par = 1; par <=lim; par++) { ///EI PART E LOG NILE PROBLEM HOY NA
        for(int u=1; u<=n; u++) {
            if(sparse[u][par-1] != -1) {
                sparse[u][par] = sparse[ sparse[u][par-1] ][par-1];
            }
        }
    }
}

int getLCA(int u, int v) {
    if(lev[u] < lev[v]) swap(u,v);

    int up = log2(lev[u]) ;
    while(up >= 0) {
        int sp = sparse[u][up];
        if( lev[u] - (1 << up) >= lev[v]) {
            u = sp;
        }
        up--;
    }

    up = log2(lev[u]) ;
    while(up >= 0) {
        if(sparse[u][up] != sparse[v][up]) {
            u = sparse[u][up];
            v = sparse[v][up];
        }
        up--;
    }

    if (u == v) return u;
    return sparse[u][0];
}

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node].val = cost[st];
        segTree[node].prop = 0;
        return;
    }
    segVar;
    init(lft, st,   md);
    init(rgt, md+1, ed);
}

int query(int node, int st, int ed, int pos, int carry = 0) {
    if(ed < pos || st > pos) return 0;
    if(st == pos && ed == pos) return segTree[node].val + carry;
    segVar;
    int q, x,y;
    x = query(lft, st, md, pos, segTree[node].prop+carry);
    y = query(rgt, md+1, ed, pos, segTree[node].prop+carry);
    if(pos <= md) q = x;
    else q = y;
    return q;
}

void update(int node, int st, int ed, int l, int r, int val) {
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node].val += val;
        segTree[node].prop += val;
        return;
    }
    segVar;
    update(lft, st, md, l,r, val); update(rgt, md+1, ed, l,r, val);
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) graph[i].clear();
        msk = 0;
        memset(sparse, -1, sizeof(sparse));
        memset(mask, 0, sizeof(mask));
        memset(vis, 0, sizeof(vis));
        memset(lev, 0, sizeof(lev));
        memset(cost, 0, sizeof(cost));
        memset(subTreeEnd, 0, sizeof(subTreeEnd));
        memset(segTree, 0, sizeof(segTree));

        for(int i=0; i<n; i++) scanf("%d", &genies[i]);
        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        mask[0] = ++msk;
        dfs(0);
        makeSparse();

        init(1, 1,n);
        scanf("%d", &q);
        printf("Case %d:\n", t);

        while(q--) {
            int a,b,c;
            scanf("%d %d %d", &c,&a,&b);
            if(!c) {
                int lca = getLCA(a,b);
                int xx,yy,zz;
                xx = query(1, 1,n, mask[a]), yy = query(1, 1,n, mask[b]), zz = query(1, 1,n, mask[lca]);
                int ans = query(1, 1,n, mask[a]) + query(1, 1,n, mask[b]) - 2*query(1, 1,n, mask[lca]) + genies[lca];
                printf("%d\n", ans);
            }
            else {
                update(1, 1,n, mask[a], subTreeEnd[a], b-genies[a]);
                genies[a] = b;
            }
        }
    }
    return 0;
}
