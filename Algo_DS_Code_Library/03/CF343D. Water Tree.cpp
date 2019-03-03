/**
1.  filling a whole subtree of v
2.  making v and all ancestor empty
3.  is v full or empty

1 means empty, init with 1

1.  query if any 1 in subtree.
    make whole subtree count 0, keep prop
    if query was nonzero, do 2. with par[v]
2.  make v 1
3.  query subtree of v. if count > 0, empty
    otherwise filled
**/

int n,q;
vi g[LIM];
int par[LIM], id[LIM], lim[LIM], tim=0;
pii segTree[4*LIM];

void dfs(int u) {
    id[u] = ++tim;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(id[v]) continue;
        par[v] = u;
        dfs(v);
    }
    lim[u] = tim;
}

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node].ff = 1;
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node].ff = segTree[lft].ff+segTree[rgt].ff;
}
void update(int node, int st, int ed, int l, int r, int v, int prop=0) {
    if(prop) segTree[node] = pii(0, 1);
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        if(v) {
            segTree[node].ff = 0;
            segTree[node].ss = 1;
        }
        else {
            segTree[node].ff = 1;
            segTree[node].ss = 0;
        }
        return;
    }
    segVar;
    update(lft,  st,md, l,r, v, segTree[node].ss);
    update(rgt, md+1,ed,l,r, v, segTree[node].ss);
    segTree[node] = pii(segTree[lft].ff+segTree[rgt].ff, 0);

}
int query(int node, int st, int ed, int l, int r, int prop=0) {
    if(prop) segTree[node] = pii(0, 1);

    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node].ff;
    segVar;
    int pp = segTree[node].ss;
    segTree[node].ss = 0;
    return query(lft, st,md, l,r, pp) + query(rgt, md+1,ed, l,r, pp);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1);

    init(1, 1,tim);

    scanf("%d", &q);
    while(q--) {
        int c,u;
        scanf("%d %d", &c,&u);
        int U = id[u], V = lim[u], PU = id[ par[u] ];
        if(c == 1) {
            int t = query(1, 1,tim, U,V);
            update(1, 1,tim, U,V, 1);
            if(t > 0) update(1, 1,tim, PU, PU, 0);
        }
        else if(c == 2){
            update(1, 1,tim, U,U, 0);
        }
        else {
            int t = query(1, 1,tim, U,V);
            if(t) printf("0\n");
            else printf("1\n");
        }
    }
}
