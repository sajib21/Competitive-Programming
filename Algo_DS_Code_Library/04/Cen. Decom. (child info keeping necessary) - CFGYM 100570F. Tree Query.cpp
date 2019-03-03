/*
    given weighted tree, query(u, w) : how many nodes reachable
    from u with <= distance w.
    decom. and calc. info for all centroid (nlogn memory).
    messy part: for each cen. subtracting results from children.
    in other problems this can be done easily by querying in children.
    but here, we need to keep track of info for
    each children of each centroid separately.
*/

/*
    Copy variables and these functions from library.

    DECOMPOSITION:
    void dfs(int u, int p=0);
    int getCentroid(int u, int p=0, int pc=0);
    void decom();
    void printCenTree();

    INFORMATION:
    void dfs2(int u, ll c=0, int l=0); // modify c problem wise
    void makeSparse();
    int getLCA(int u, int v);
    ll getDist(int u, int v); // modify function problem wise
    // add new function life getDist if necessary
*/

vl dis[LIM], tempv; /// all info
vector<int>id[LIM]; /// which index for each child
vector<vl>badd[LIM]; ///info of children to subtract

void update(int u, int cen, int p, int in) {
    ll d = getDist(u, cen);
    assert(d >= 0);
    dis[cen].pb(d);
    tempv.pb(d);

    for(int v : cg[u]) {
        if(v != p) update(v, cen, u, in);
    }
}

int query(int U, ll W) {
    int ans = upper_bound(dis[U].begin(), dis[U].end(), W) - dis[U].begin();
    int u = par[U], v = U;

    while(u) {
        int badid = lower_bound(id[u].begin(), id[u].end(), v) - id[u].begin();

        ans += ( upper_bound(dis[u].begin(), dis[u].end(), W-getDist(U,u) ) - dis[u].begin() ) -
               ( upper_bound(badd[u][badid].begin(), badd[u][badid].end(), W-getDist(U,u) ) - badd[u][badid].begin() );

        v = u;
        u = par[u];
    }
    return ans;
}

int brute(int u, ll w) {
    int ans = 0;
    for(int v=1; v<=n; v++) {
        ans += getDist(u,v) <= w;
    }
    return ans;
}


int main() {
    scanf("%d %d", &n,&q);
    for(int i=1; i<n; i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v, &w);
        g[u].pb(v); g[v].pb(u);
        wt[u].pb(w); wt[v].pb(w);
    }
    decom();
    for(int i=1; i<=n; i++) sort(cg[i].begin(), cg[i].end());
    makeSparse();

    for(int u=1; u<=n; u++) {
        dis[u].pb(0);
        for(int i=0; i<cg[u].size(); i++) {
            int v = cg[u][i];
            if(v != par[u]) {
                tempv.clear();
                update(v, u, u, i);
                sort(tempv.begin(), tempv.end());
                badd[u].pb(tempv);
                id[u].pb(v);

            }
        }
        sort(dis[u].begin(), dis[u].end());
    }

    while(q--) {
        int u;
        ll w;
        scanf("%d %lld", &u, &w);
        printf("%d\n", query(u, w));
    }

}

