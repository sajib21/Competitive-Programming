#include<bits/stdc++.h>
#define LIM 100005
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,m, root;
vi g[LIM];
int col[LIM], sz[LIM], qu[LIM], qh[LIM];
int par[LIM][20], lev[LIM];
vi q[LIM], in[LIM];

vi* vec[LIM];
int res[LIM];
int ans[LIM];

void getSZ(int u, int p, int d) {
    sz[u]++; col[u] = d; lev[u] = d;
    for(auto v : g[u]) {
        if(v == p) continue;
        par[v][0] = u;
//        cout << "PAR SET " << v << ' ' << u << endl;
        getSZ(v, u, d+1);
        sz[u] += sz[v];
    }
}
void makeSparse() {
    int lim = 18;
    for(int p = 1; p <=lim; p++) { ///EI PART E LOG NILE PROBLEM HOY NA
        for(int u=1; u<=n; u++) {
            if(par[u][p-1] != -1) {
                par[u][p] = par[ par[u][p-1] ][p-1];
            }
        }
    }
}
int getPar(int u, int p) {
//    if(lev[u] < lev[v]) swap(u,v);

    int up = 18 ;
    while(up >= 0) {
        if(u < 0) break;
        int sp = par[u][up];
        if((1 << up) <= p) {
//            cout << "UP " << u << ' ' << up << ' ' << sp << endl;
            u = sp;
            p -= (1 << up);
        }
        up--;
    }
//    cout << "RET " << u << endl;
    return u;
}

void dfs(int u, int p, int keep) {
    int mx = -1, big = -1;
    for(auto v : g[u]) {
        if(v != p && sz[v] > mx) {
            mx = sz[v];
            big = v;
        }
    }

    for(auto v : g[u]) if(v != p && v != big) dfs(v, u, 0);

    if(big != -1) {
        dfs(big, u, 1);
        vec[u] = vec[big];
    }
    else vec[u] = new vi();
    vec[u]->pb(u);
    res[ col[u] ]++;
    ///or res[ col[u] ] += a[u];

//    cout << "INIT " << u << endl;
//    for(int i=1; i<=3; i++) cout << res[i] << ' ' ; cout << endl;
//    getchar();

    for(auto v : g[u]) {
        if(v != p && v != big) {
            for(auto x : *vec[v]) {
                vec[u]->pb(x);
                res[ col[x] ]++;
                ///or res[ col[x] ] += a[x]
            }
        }
    }

    ///QUERY OF SUBTREE OF V HERE!!
    for(int i=0; i<q[u].size(); i++) {
        int h = q[u][i];
        int cnt = res[h];
        ans[ in[u][i] ] = cnt;
    }

//    cout << "QUERY " << u << endl;
//    for(int i=1; i<=3; i++) cout << res[i] << ' ' ; cout << endl;
//    getchar();

    if(keep == 0) {
        for(auto x : *vec[u]) {
            res[ col[x] ]--;
            ///or res[ col[x] ] -= a[x]
        }
    }
}

int main() {
    memset(par, -1, sizeof par);
    scanf("%d", &n);
    for(int v=1; v<=n; v++) {
        int u;
        scanf("%d", &u);
        g[u].pb(v);
//        if(!u) root = v;
    }
//    scanf("%s", a);

    getSZ(0, -1, 1);
    makeSparse();
//    cout << "SPARSE " << endl;
//    for(int i=0; i<=6; i++) {
//        for(int j=0; j<3; j++) cout << par[i][j] << ' ';
//        cout << endl;
//    }

    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &qu[i], &qh[i]);

        int p;
        if(qh[i] < lev[ qu[i] ]) p = getPar(qu[i], qh[i]);
        else p = -1;
//        cout << "Q " << p << ' ' << qh[i] << endl;

        if(p <= 0) ans[i] = 1;
        else {
            q[ p ].pb(lev[ qu[i] ]);
            in[p].pb(i);
        }
    }

    dfs(0, -1, 0);

    bool f = false;
    for(int i=0; i<m; i++) {
        if(f) printf(" ");
        f = true;
        printf("%d", ans[i]-1);
    }
    printf("\n");
}

