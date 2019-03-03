///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     LOG             20
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

int chains = 0, ptr=0, chainHead[LIM+10], chainSize[LIM+10], whichChain[LIM+10], posInChain[LIM+10], posInBase[LIM+10], posInMain[LIM+10], baseArray[LIM+10];
void makeHLD(int u) {
    if(chainHead[chains] == -1) chainHead[chains] = u;
    whichChain[u] = chains;
    posInChain[u] = chainSize[chains]++;
    ptr++;
    posInBase[u] = ptr;
    posInMain[ptr] = u;
//    baseArray[ptr] = ara[u];
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

int segTree[4*LIM];
void segTreeInit(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = INT_MAX;
        return;
    }
    segVar;
    segTreeInit(lft, st,md); segTreeInit(rgt, md+1,ed);
    segTree[node] = INT_MAX; ///ASSUMING PROBLEM WANTS SUM!!
}

void segTreeUpdate(int node, int st, int ed, int p) { ///ASSUMING SINGLE UPDATE!!
    if(ed < p || st > p) return;
    if(st >= p && ed <= p) {
        if(segTree[node] == INT_MAX) segTree[node] = p;
        else segTree[node] = INT_MAX;
//        segTree[node] = v;
        return;
    }
    segVar;
    segTreeUpdate(lft, st,md, p); segTreeUpdate(rgt, md+1, ed, p);
    segTree[node] = min(segTree[lft], segTree[rgt]);
//    segTree[lft] + segTree[rgt];
}

int segTreeQuery(int node, int st, int ed, int l, int r) { ///ASSUMING SINGLE UPDATE, RANGE QUERY!!
    if(ed < l || st > r || segTree[node] == INT_MAX) return INT_MAX;
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    return min(segTreeQuery(lft, st,md, l,r) , segTreeQuery(rgt, md+1,ed, l,r) );
}

void update(int p) {
    int base = posInBase[p];
    segTreeUpdate(1, 1, ptr, base);
}

int queryUp(int u, int v) {
    int uchain = whichChain[u], vchain = whichChain[v], ubase = posInBase[u] , vbase = posInBase[v], ans = INT_MAX;
    if(u == v) {
        int temp = segTreeQuery(1, 1,ptr, vbase , ubase );
        if(temp <= ubase) return temp;
        else return INT_MAX;
    }

    while(true) {
        uchain = whichChain[u];
        ubase = posInBase[u];
        int temp;
        int uhead = chainHead[uchain];
        int sz = chainSize[uchain];
        int utail = uhead + sz - 1;
        if(uchain == vchain) {
            temp = segTreeQuery(1, 1,ptr, vbase , ubase );
            if(temp <= ubase) ans = temp;
//            if(temp != INT_MAX) ans = temp;
//            cout << "RET " << vbase << ' ' << ubase << ' ' << segTreeQuery(1, 1,ptr, vbase , ubase ) << ' ' << ans << endl;
            break;
        }
        temp = segTreeQuery(1, 1,ptr, posInBase[uhead], ubase );
        if(temp <= ubase) ans = temp;
        u = par[uhead][0];
    }
    return ans;
}

int query(int a) {
//    int lca = getLCA(a,b);
//    cout << "LCA " << a << ' ' << b << ' ' << lca << endl;
    return queryUp(a, 1);
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
//    scanf("%d", &T);
    for(int t=1; t<=1; t++) {
        scanf("%d %d", &n, &q);
//        for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
        for(int i=1; i<=n; i++) graph[i].clear();
        for(int i=1; i<=n; i++) costs[i].clear();
        memset(lev, 0, sizeof(lev));
        memset(par, 0, sizeof(par));
//        memset(sparse, -1, sizeof(sparse));
        memset(chainHead, -1, sizeof(chainHead));
        memset(chainSize, 0, sizeof(chainSize));
        chains = ptr = 0;
        for(int i=1; i<n; i++) {
            int u,v, w;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
//            costs[u].pb(w);
//            costs[v].pb(w);
        }

        ///ASSUMING 1 IS ROOT NODE!!
        dfs(1);
        makeSparse();

        makeHLD(1);
        segTreeInit(1, 1,ptr);
//                cout << "BUG" << endl;
//        segTreeInit(1, 1,ptr);

//        cout << "BASE " << endl;
//        for(int i=1; i<=n; i++) cout << i << ' ' << posInBase[i] << endl;
//        cout << "MAIN" << endl;
//        for(int i=1; i<=n; i++) cout << i << ' ' << posInMain[i] << endl;

//        cout << "TREE" << endl;
//        for(int i=1; i<=4*n; i++) cout << i << ' ' << segTree[i] << endl;

//        scanf("%d", &q);
        while(q--) {
            char cmd[100]; int x,y,z;
            scanf("%d %d", &x,&y);
            if(!x) {
                update(y);
//                for(int i=1; i<=20; i++) cout << segTree[i] << ' ' ; cout << endl;
            }
            else {
                int temp = query(y);
//                cout << temp << endl;
                if(temp == INT_MAX) printf("-1\n");
                else printf("%d\n", posInMain[temp]);
            }
        }

    }

    return 0;

}
