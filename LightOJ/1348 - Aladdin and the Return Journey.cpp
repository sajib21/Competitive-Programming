///YOU DON'T HAVE TO USE BOTH LEFT AND RIGHT CALLS IN SEGMENT TREE QUERY IF YOU ARE NOT UPDATING ANYTHING.
///BUT IF YOU ARE UPDATING IN QUERY FUNCTION THEN YOU MUST CALL IN BOTH DIRECTION.
///DON'T WASTE A FULL DAY ON THIS THING AGAIN. :)

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

int vis[LIM+10], subTreeEnd[LIM+10], mask[LIM+10], msk = 2;
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
//    lev[ mask[u] ] = l;
    lev[ u ] = l;
//    mask[u] = msk++;
    cost[ mask[u] ] = genies[u] + cst;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            mask[v] = msk++;
            dfs(v, cost[ mask[u] ], l+1);
//            sparse[ mask[v] ][0] = mask[u];
            sparse[ v ][0] = u;
//            sparseCost[ mask[v] ][0] =
        }
    }
    subTreeEnd[u] = msk-1;
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
    segTree[node].prop = -1;
}

int query(int node, int st, int ed, int pos, int carry = -1) {

    if(carry != -1) segTree[node].val += carry;
    if(carry != -1) segTree[node].prop += carry;
//    if(st == ed) segTree[node].prop = 0;
//    cout << node << ' ' << st << ' ' << ed << ' ' << pos << ' ' << carry << ' ' << segTree[node].val << ' ' << segTree[node].prop << endl;
//    cout << "SEG IN "  << endl;
    if(ed < pos || st > pos) return 0;
    if(st == pos && ed == pos) {
//        segTree[node].prop = -1;
//        if(carry != -1) segTree[node].val += carry;
//        segTree[node].prop = 0;
//        cout << "SEG FOUND " << st << ' ' << ed << ' ' << segTree[node].val << ' ' << segTree[node].prop << endl;
        return segTree[node].val;
    }
    segVar;
    int q, x,y;
    x = query(lft, st, md, pos, segTree[node].prop);
    y = query(rgt, md+1, ed, pos, segTree[node].prop);
    if(pos <= md) q = x;
    else q = y;
    segTree[node].prop = 0;
    return q;
}

void update(int node, int st, int ed, int l, int r, int val, int pre=-1) {
    cout << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << val << ' ' << pre << endl;
    if(pre != -1) segTree[node].val  += pre;
    if(pre != -1) segTree[node].prop += pre;
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node].val += val;
        segTree[node].prop += val;
        cout << "UPDATE SEG FOUDN " << node << ' ' << st << ' ' << ed << ' ' << segTree[node].val << ' ' << segTree[node].prop << endl;
        return;
    }
    segVar;
    update(lft, st, md, l,r, val, segTree[node].prop); update(rgt, md+1, ed, l,r, val, segTree[node].prop);
    segTree[node].prop = 0;
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) graph[i].clear();
        msk = 1;
        memset(sparse, -1, sizeof(sparse));
        memset(mask, 0, sizeof(mask));
        memset(vis, 0, sizeof(vis));
        memset(lev, 0, sizeof(lev));
        memset(cost, 0, sizeof(cost));
        memset(subTreeEnd, 0, sizeof(subTreeEnd));

        for(int i=0; i<n; i++) scanf("%d", &genies[i]);
        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        mask[0] = msk++;
        dfs(0);
        makeSparse();

        init(1, 1,n);
        scanf("%d", &q);
        printf("Case %d:\n", t);
//        for(int i=0; i<n; i++) cout << mask[i] << ' ' ; cout << endl;
//        for(int i=0; i<n; i++) cout << cost[ mask[i] ] << ' ' ; cout << endl;
        while(q--) {
            int a,b,c;
            scanf("%d %d %d", &c,&a,&b);
            if(!c) {
                int lca = getLCA(a,b);
//                cout << "LCA " << lca << endl;
//                int xx,yy,zz;
//                xx = query(1, 1,n, mask[a]), yy = query(1, 1,n, mask[b]), zz = query(1, 1,n, mask[lca]);
//                cout << "QUERYING " << xx << ' ' << yy << ' ' << zz << ' ' << genies[lca] << endl;
//                xx = query(1, 1,n, mask[a]), yy = query(1, 1,n, mask[b]), zz = query(1, 1,n, mask[lca]);
//                cout << "QUERYING " << xx << ' ' << yy << ' ' << zz << ' ' << genies[lca] << endl;

                int ans = query(1, 1,n, mask[a]) + query(1, 1,n, mask[b]) - 2*query(1, 1,n, mask[lca]) + genies[lca];
                printf("%d\n", ans);
            }
            else {
//                cout << "UPDATING " << mask[a] << ' ' << subTreeEnd[a] << endl;
                update(1, 1,n, mask[a], subTreeEnd[a], b-genies[a]);
//                query(1, 1,n, mask[a]);
//                query(1, 1,n, mask[a]) ; query(1, 1,n, mask[b]) ; query(1, 1,n, getLCA(a,b));
                genies[a] = b;
            }
        }
    }
    return 0;
}
