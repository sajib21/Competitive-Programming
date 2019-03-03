struct info{
    int x,y,z, s, p,q; ///x prefix, y suffix, z best, s sum
    info() {
        x = -MAX;
        y = -MAX;
        z = -MAX;
        s = 0;
        p = 0;
        q = 0;
    }
    info(int xx, int yy = 0, int zz = 0, int ss = 0, int pp = 0, int qq = 0) {
        x = xx; y = yy; z = zz; s = ss; p = pp; q = qq;
    }
    info operator + (const info &b) const {
        info ans;
        ans.x = max(x, s+b.x); ans.y = max(b.y, b.s+y); ans.z = max( max(z, b.z) , max( y+b.x , max(ans.x, ans.y) ) ); ans.s = s+b.s;
        return ans;
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

info getLCA(int u, int v) {
    bool f = false;
    if(lev[u] < lev[v]) {
        swap(u,v);
        f = true;
    }

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

    if(f) swap(u,v);

    if (u == v) return info(u,v, v);
    return info(u,v, par[u][0]);
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

info segTree[4*LIM];
void segTreeInit(int node, int st, int ed) {
    segTree[node] = info();
    if(st == ed) {
        segTree[node].x = segTree[node].y = segTree[node].z = segTree[node].s = baseArray[st];
        return;
    }
    segVar;
    segTreeInit(lft, st,md); segTreeInit(rgt, md+1,ed);
    segTree[node] = segTree[lft] + segTree[rgt]; ///ASSUMING PROBLEM WANTS SUM!!
}

info segTreeUpdate(int node, int st, int ed, int l, int r, int v, int c = 0, int cv = 0) { ///ASSUMING SINGLE UPDATE!!
    if(c) {
        int ch = (ed-st+1)*cv;
        segTree[node] = info(ch,ch,ch,ch);
        segTree[node].p = 1;
        segTree[node].q = cv;
    }
    if(ed < l || st > r) return info();
    if(st >= l && ed <= r) {
        int ch = (ed - st + 1)*v;
        segTree[node] = info(ch,ch,ch,ch);
        segTree[node].p = 1;
        segTree[node].q = v;
        return segTree[node];
    }
    segVar;
    segTreeUpdate(lft, st,md, l,r, v, segTree[node].p, segTree[node].q); segTreeUpdate(rgt, md+1, ed, l,r, v, segTree[node].p, segTree[node].q);
    segTree[node] = segTree[lft] + segTree[rgt];
    segTree[node].p = segTree[node].q = 0;
    return segTree[node];
}

info segTreeQuery(int node, int st, int ed, int l, int r, int c = 0, int cv = 0) { ///ASSUMING SINGLE UPDATE, RANGE QUERY!! ///for this problem actual l is l+1
    if(c) {
        int ch = (ed-st+1)*cv;
        segTree[node] = info(ch,ch,ch,ch);
        segTree[node].p = 1;
        segTree[node].q = cv;
    }
    if(ed < l || st > r) return info();
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    info ans = segTreeQuery(lft, st,md, l,r, segTree[node].p, segTree[node].q) + segTreeQuery(rgt, md+1,ed, l,r, segTree[node].p, segTree[node].q);
    segTree[node].p = segTree[node].q = 0;
    return ans;
}

info updateUp(int u, int v, int val) {
    int uchain = whichChain[u], vchain = whichChain[v], ubase = posInBase[u] , vbase = posInBase[v];
    info ans = info();
    if(u == v) return segTreeUpdate(1, 1,ptr, vbase , ubase, val );

    while(true) {
        uchain = whichChain[u];
        ubase = posInBase[u];
        int uhead = chainHead[uchain];
        int sz = chainSize[uchain];
        int utail = uhead + sz - 1;
        if(uchain == vchain) {
            ans = segTreeUpdate(1, 1,ptr, vbase , ubase, val ) + ans;
            break;
        }
        ans = segTreeUpdate(1, 1,ptr, posInBase[uhead], ubase, val ) + ans;
        info tmp = segTreeUpdate(1, 1,ptr, posInBase[uhead], ubase, val);
        u = par[uhead][0];
    }
    return ans;
}
info update(int a, int b, int val) {
    info lca = getLCA(a,b); int al = lca.x , bl = lca.y, lz = lca.z;
    if(al == bl) {
        if(al == a) return updateUp(b, bl, val);
        return updateUp(a, al, val);
    }
    info A = updateUp(a, al, val) , B = updateUp(b, bl, val), m = updateUp(lz,lz, val) ;
    swap(A.x, A.y);
    info ret = A + m + B;
    return ret;
}

info queryUp(int u, int v) {
    int uchain = whichChain[u], vchain = whichChain[v], ubase = posInBase[u] , vbase = posInBase[v];
    info ans = info();
    if(u == v) return segTreeQuery(1, 1,ptr, vbase , ubase );

    while(true) {
        uchain = whichChain[u];
        ubase = posInBase[u];
        int uhead = chainHead[uchain];
        int sz = chainSize[uchain];
        int utail = uhead + sz - 1;
        if(uchain == vchain) {
            ans = segTreeQuery(1, 1,ptr, vbase , ubase ) + ans;
            break;
        }
        ans = segTreeQuery(1, 1,ptr, posInBase[uhead], ubase ) + ans;
        info tmp = segTreeQuery(1, 1,ptr, posInBase[uhead], ubase);
        u = par[uhead][0];
    }
    return ans;
}

info query(int a, int b) {
    info lca = getLCA(a,b); int al = lca.x , bl = lca.y, lz = lca.z;
    if(al == bl) {
        if(al == a) return queryUp(b, bl);
        return queryUp(a, al);
    }
    info A = queryUp(a, al) , B = queryUp(b, bl), m = queryUp(lz,lz) ;
    swap(A.x, A.y);
    info ret = A + m + B;
    return ret;
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    for(int t=1; t<=1; t++) {
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
        }
        dfs(1);
        makeSparse();
        makeHLD(1);
        segTreeInit(1, 1,ptr);

        scanf("%d", &q);
        while(q--) {
            char cmd[100]; int x,y,z;
            scanf("%s %d %d", cmd, &x,&y);
            if(cmd[0] == '2') {
                scanf("%d", &z);
                update(x, y, z);
            }
            else printf("%d\n", max(0,query(x,y).z) );
        }

    }

    return 0;

}

