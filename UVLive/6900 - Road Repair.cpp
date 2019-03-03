/**
if no updates, one approach is:
for each centroid calculate pairs whose path contains this node,
means for each node calculate all pairs from its subtree.
Then remove this node and go on.

If the problem implies that we need to keep O(N) memory in each node,
we still won't need N^2 memory as we are focusing on only one centroid at a time.
**/

///CENTROID DECOMPOSITION CODE HERE!!!

///make similar ds/arrays as cost[]
int getDist(int u, int v) {
    return cost[u] + cost[v] - 2*cost[ getLCA(u,v) ];
}
int getProf(int u, int v) {
    return prof[u] + prof[v] - 2*prof[ getLCA(u,v) ];
}

///problem specific
int COST;
set<pii>dis;
int ANS = 0;

void update(int u, int p) {
    int ds = getDist(u, p);
    int pf = getProf(u, p);

    if(ds <= COST) {
        ANS = max(ANS, pf);
        dis.insert(pii(ds,pf));

        set<pii>::iterator it, temp;
        it = dis.find(pii(ds,pf));
        bool ok = true;

        if(it != dis.begin()) {
            temp = it;
            temp--;
            if(temp->second >= it->second) {
                dis.erase(it);
                ok = false;
            }
        }

        while(ok) {
            temp = it;
            temp++;
            if(temp == dis.end() || it->second < temp->second) break;
            dis.erase(temp);
        }
    }

    for(int v : cg[u]) {
        if(v != par[u]) update(v, p);
    }
}

int query(int u, int p) {
    int ds = getDist(u, p);
    int pf = getProf(u, p);
    int nds = COST-ds;

    if(ds <= COST) {
        ANS = max(ANS, pf);
        dis.insert(pii(nds, MAX));
        set<pii>::iterator it = dis.find(pii(nds, MAX)), temp;

        if(it != dis.begin()) {
            temp = it; temp--;
            ANS = max(ANS, pf + temp->second );
        }

        dis.erase(it);
    }

    for(int v : cg[u]) {
        if(v != par[u]) query(v, p);
    }
}

void printmap() {
    cout << "CURRENT MAP " << endl;
    for(auto it : dis) {
        cout << "( " << it.first << " , " << it.second << " )";
    }
    cout << endl;
}

void process(int u) {
    dis.clear();
    dis.insert(pii(0,0));
    for(int v : cg[u]) {
        if(v == par[u]) continue;
        query(v, u);
        update(v, u);
    }
}

void clr() {
    for(int i=1; i<=n; i++) {
        g[i].clear();
        w[i].clear();
        p[i].clear();
        cg[i].clear();
        centroid[i] = 0;
        vis[i] = 0;
        par[i] = 0;
        sub[i] = 0;
    }
    memset(sparse, 0, sizeof sparse);
    ANS = 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        clr();
        for(int i=1; i<n; i++) {
            int u,v, c,b;
            scanf("%d %d %d %d", &u,&v, &c, &b);
            g[u].pb(v); g[v].pb(u);
            w[u].pb(c); w[v].pb(c);
            p[u].pb(b); p[v].pb(b);
        }
        decom();
//        printCenTree();
        makeSparse();

        scanf("%d", &COST);

        for(int u=1; u<=n; u++) process(u);

        printf("%d\n", ANS);
    }
}
