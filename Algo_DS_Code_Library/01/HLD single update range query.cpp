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

int chains = 0, ptr=0, chainHead[LIM+10], chainSize[LIM+10], whichChain[LIM+10], posInChain[LIM+10], posInBase[LIM+10], baseArray[LIM+10];
void makeHLD(int u) {
    if(chainHead[chains] == -1) chainHead[chains] = u;
    whichChain[u] = chains;
    posInChain[u] = chainSize[chains]++;
    ptr++;
    posInBase[u] = ptr;
    baseArray[ptr] = ara[u];

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
        segTree[node] = baseArray[st];
        return;
    }
    segVar;
    segTreeInit(lft, st,md); segTreeInit(rgt, md+1,ed);
    segTree[node] = segTree[lft] + segTree[rgt];
    ///ASSUMING PROBLEM WANTS SUM!!
}

void segTreeUpdate(int node, int st, int ed, int p, int v) {
    if(ed < p || st > p) return;
    if(st >= p && ed <= p) {
        segTree[node] = v;
        return;
    }
    segVar;
    segTreeUpdate(lft, st,md, p, v); segTreeUpdate(rgt, md+1, ed, p, v);
    segTree[node] = segTree[lft] + segTree[rgt];
}

int segTreeQuery(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    return segTreeQuery(lft, st,md, l,r) + segTreeQuery(rgt, md+1,ed, l,r);
}

void update(int p, int v) {
    int base = posInBase[p];
    segTreeUpdate(1, 1, ptr, base, v);
}

int queryUp(int u, int v) {
    int uchain = whichChain[u], vchain = whichChain[v], ubase = posInBase[u] , vbase = posInBase[v], ans = 0;
    if(u == v) return segTreeQuery(1, 1,ptr, vbase , ubase );

    while(true) {
        uchain = whichChain[u];
        ubase = posInBase[u];
        int uhead = chainHead[uchain];
        int sz = chainSize[uchain];
        int utail = uhead + sz - 1;
        if(uchain == vchain) {
            ans += segTreeQuery(1, 1,ptr, vbase , ubase );
            break;
        }
        ans += segTreeQuery(1, 1,ptr, posInBase[uhead], ubase );
        u = par[uhead][0];
    }
    return ans;
}

int query(int a, int b) {
    int lca = getLCA(a,b);
    return queryUp(a, lca) + queryUp(b, lca) - queryUp(lca,lca);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
        for(int i=1; i<=n; i++) graph[i].clear();
        for(int i=1; i<=n; i++) costs[i].clear();
        memset(lev, 0, sizeof(lev));
        memset(par, 0, sizeof(par));
        memset(chainHead, -1, sizeof(chainHead));
        memset(chainSize, 0, sizeof(chainSize));
        chains = ptr = 0;
        for(int i=1; i<n; i++) {
            int u,v, w;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(w);
            costs[v].pb(w);
        }

        dfs(1);
        makeSparse();
        makeHLD(1);
        segTreeInit(1, 1,ptr);

        scanf("%d", &q);
        while(q--) {
            char cmd[100]; int x,y,z;
            scanf("%s %d %d", cmd, &x,&y);
            if(cmd[0] == 'C') update(x, y);
            else printf("%d\n", query(x,y));
        }
    }
    return 0;
}
