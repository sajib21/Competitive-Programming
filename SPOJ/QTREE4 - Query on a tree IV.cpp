///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             10000
#define     LOG             17
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

struct info{
    int w,x,y,z, c; /// w = total, x = prefix, y = suffix, z = best
    info() {w = x = y = z = c = 0;}
    info(int ww, int xx, int yy = 0, int zz = 0, int cc = 0) {
        w = ww; x = xx; y = yy; z = zz; c = cc;
    }
};

int n,q, ara[LIM+10];
vii graph[LIM+10], costs[LIM+10];

int lev[LIM+10], par[LIM+10][LOG+10], sub[LIM+10];
int dfs(int u) {
    if(u == 1) lev[u] = 0;
    else lev[u] = lev[ par[u][0] ] + 1;

    int sz = graph[u].size();
    int cnt = 1;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!lev[v] && v != 1) {
            par[v][0] = u;
            ara[v] = costs[u][i];
            cnt += dfs(v);
        }
    }
    return sub[u] = cnt;
}

void makeSparse() {
    for(int p=1; p<=LOG; p++) {
        for(int u=1; u<=n; u++) {
            if(par[u][p-1] != -1) par[u][p] = par[ par[u][p-1] ][ p-1 ];
        }
    }
}

int getLCA(int u, int v) {
    if(lev[u] < lev[v]) swap(u,v);

    int up = log2(lev[u]) ;
    while(up >= 0) {
        int sp = par[u][up];
        if( lev[u] - (1 << up) >= lev[v]) u = sp;
        up--;
    }

    up = log2(lev[u]) ;
    while(up >= 0) {
        if(par[u][up] != par[v][up]) {
            u = par[u][up];
            v = par[v][up];
        }
        up--;
    }

    if (u == v) return u;
    return par[u][0];
}

int chains = 0, ptr=0, chainHead[LIM+10], chainSize[LIM+10], whichChain[LIM+10], posInChain[LIM+10], posInBase[LIM+10], baseArray[LIM+10];
void makeHLD(int u) {
    if(chainHead[chains] == -1) chainHead[chains] = u;
    whichChain[u] = chains;
    posInChain[u] = chainSize[chains]++;
    ptr++;
    posInBase[u] = ptr;
    baseArray[ptr] = ara[u];
//    ptr++;

    int sz = graph[u].size();
    int specialSize=0, specialId = -1;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(v != par[u][0] && sub[v] > specialSize) {
            specialId = v;
            specialSize = sub[v];
        }
    }

    if(specialId == -1) return;

    makeHLD(specialId);

    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(v != par[u][0] && v != specialId) {
            chains++;
            makeHLD(v);
        }
    }
}

info segTree[8*LIM]; /// w = total, x = prefix, y = suffix, z = best
void segTreeInit(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = info(0, 0, 0, 0,0);
        return;
    }
    segVar; info ans;
    segTreeInit(lft, st,md); segTreeInit(rgt, md+1,ed);
    ans.w = segTree[lft].w + baseArray[md+1] + segTree[rgt].w;
    ans.x = max(segTree[lft].x , segTree[lft].w+segTree[rgt].x);
    ans.y = max(segTree[rgt].y , segTree[rgt].w+segTree[lft].y);
    ans.z = max( max(segTree[lft].z,segTree[rgt].z) , max( max(ans.x,ans.y) , segTree[lft].y+segTree[rgt].x ) );
    segTree[node] = ans;
}

void segTreeUpdate(int node, int st, int ed, int p, int v) { ///ASSUMING SINGLE UPDATE!!
    if(ed < p || st > p) return;
    if(st >= p && ed <= p) {
        if(segTree[node].c) segTree[node] = info(0,0,0,0,0);
        else segTree[node] = info(0,0,0,0,1);
//        segTree[node].c = !segTree[node].c;
        return;
    }
    segVar;
    info one,two, ans;
    segTreeUpdate(lft, st,md, p, v); segTreeUpdate(rgt, md+1, ed, p, v);
    one = segTree[lft];

    ans.w = segTree[lft].w + baseArray[md+1] + segTree[rgt].w;
    ans.x = max(segTree[lft].x , segTree[lft].w+segTree[rgt].x);
    ans.y = max(segTree[rgt].y , segTree[rgt].w+segTree[lft].y);
    ans.z = max( max(segTree[lft].z,segTree[rgt].z) , max( max(ans.x,ans.y) , segTree[lft].y+segTree[rgt].x ) );
    segTree[node] = ans;
}

int segTreeQuery(int node, int st, int ed, int l, int r) { ///ASSUMING SINGLE UPDATE, RANGE QUERY!!
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node];
    segVar;

    return max( segTreeQuery(lft, st,md, l,r) , segTreeQuery(rgt, md+1,ed, l,r) );
}

void update(int p, int v) {
    int base = posInBase[p];
    segTreeUpdate(1, 1, ptr, base, v);
}

int queryUp(int u, int v) {
    int uchain = whichChain[u], vchain = whichChain[v], ubase = posInBase[u] , vbase = posInBase[v], ans = INT_MIN;
    if(u == v) return 0;

    while(true) {
        uchain = whichChain[u];
        ubase = posInBase[u];
        int uhead = chainHead[uchain];
        int sz = chainSize[uchain];
        int utail = uhead + sz - 1;
        if(uchain == vchain) {
            if(u == v) break;
            ans = max(ans, segTreeQuery(1, 1,ptr, vbase+1 , ubase ) );
//            cout << "RET " << vbase << ' ' << ubase << ' ' << segTreeQuery(1, 1,ptr, vbase+1 , ubase ) << ' ' << ans << endl;
            break;
        }
        ans = max(ans, segTreeQuery(1, 1,ptr, posInBase[uhead], ubase ) );
        u = par[uhead][0];
    }
    return ans;
}

int query(int a, int b) {
    int lca = getLCA(a,b);
//    cout << "LCA " << a << ' ' << b << ' ' << lca << endl;
    return max(queryUp(a, lca) , queryUp(b, lca) );
}

int edgeu[LIM+10], edgev[LIM+10];

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
//    scanf("%d", &T);
    for(int t=1; t<=1; t++) {
        scanf("%d", &n);
//        for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
        for(int i=1; i<=n; i++) graph[i].clear();
        for(int i=1; i<=n; i++) costs[i].clear();
        memset(lev, 0, sizeof(lev));
        memset(par, -1, sizeof(par));
//        memset(sparse, -1, sizeof(sparse));
        memset(chainHead, -1, sizeof(chainHead));
        memset(chainSize, 0, sizeof(chainSize));
        memset(segTree, 0, sizeof segTree);
        chains = ptr = 0;
        for(int i=1; i<n; i++) {
            int u,v, w;
            scanf("%d %d %d", &u,&v, &w);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(w);
            costs[v].pb(w);
//            edgeu[i] = u; edgev[i] = v;
        }

        ///ASSUMING 1 IS ROOT NODE!!
        dfs(1);
        makeSparse();

        makeHLD(1);
//                cout << "BUG" << endl;
        segTreeInit(1, 1,ptr);
//
//        for(int i=1; i<=n; i++) cout << i << ' ' << lev[i] << ' ' << par[i][0] << ' ' << sub[i] << endl;
//        for(int i=1; i<=n; i++) {
//            for(int j=0; j<5; j++) printf("%3d", par[i][j]);
//            cout << endl;
//        }
//
//        for(int i=1; i<=n; i++) cout << i << ' ' << whichChain[i] << endl;

//        cout << "BASE " << endl;
//        for(int i=1; i<=n; i++) cout << i << ' ' << posInBase[i] << endl;
//        cout << "TREE" << endl;
//        for(int i=1; i<=4*n; i++) cout << i << ' ' << segTree[i] << endl;

        scanf("%d", &q);
        while(true) {
            char cmd[100]; int x,y,z;
            scanf("%s", cmd);
            if(cmd[0] == 'D') break;
            scanf("%d %d", &x,&y);
            if(cmd[0] == 'C') {
                int u = edgeu[x], v = edgev[x];
                if(u == par[v][0]) update(v, y);
                else update(u, y);
            }
            else printf("%d\n", query(x,y));
        }
    }

    return 0;
}
