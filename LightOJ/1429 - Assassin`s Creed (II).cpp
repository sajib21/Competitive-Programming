#include<bits/stdc++.h>
#define LIM 1010
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,m, cm;
vi g[LIM], r[LIM], sg[2*LIM];
int com[LIM], vis[2*LIM];
bitset<LIM>mat[LIM];
stack<int>stk;

void dfs(int u) {
    vis[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

void dfs2(int u) {
    vis[u] = 1; com[u] = cm;
    for(int i=0; i<r[u].size(); i++) {
        int v = r[u][i];
        if(!vis[v]) dfs2(v);
    }
}

void scc() {
    memset(vis, 0, sizeof vis);
//    memset(com, 0, sizeof com);
    while(!stk.empty()) stk.pop();

    for(int u=1; u<=n; u++) if(!vis[u]) dfs(u);

    memset(vis, 0, sizeof vis);
    cm = 0;
    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if(vis[u]) continue;
        cm++;
        dfs2(u);
    }

    memset(mat, 0, sizeof mat);
    for(int u=1; u<=n; u++) {
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if(com[u] != com[v]) mat[ com[u] ][ com[v] ] = 1;
        }
    }

//    cout << "COM " << endl;
//    for(int u=1; u<=n; u++) cout << u << ' ' << com[u] << endl;
//    cout << "MAT " << endl;
//    for(int i=1; i<=cm; i++) {
//        for(int j=1; j<=cm; j++) cout << mat[i][j] << ' ';
//        cout << endl;
//    }

    ///SCC DAG
    for(int u=1; u<=n; u++) {
        for(int v=1; v<=n; v++) {
            if(mat[u][v]) {
                sg[u].pb(v);
            }
        }
    }
}

int root;

void dfs3(int u) {
    vis[u] = 1;
    if(u != root) mat[root][u] = 1;
    for(int i=0; i<sg[u].size(); i++) {
        int v = sg[u][i];
        if(vis[v]) continue;
        dfs3(v);
    }
}

int match[2*LIM+10], visl[2*LIM+10], visr[2*LIM+10];

bool bfs() {
    int dis = INT_MAX;
    memset(visl, -1, sizeof(visl));
    memset(visr, -1, sizeof(visr));
    queue<int>q;

    for(int i=1; i<=n; i++) {
        if(!match[i]) {
            visl[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        int sz = sg[u].size();
        if(visl[u] > dis) break;
        for(int V=1; V<=cm; V++) {
            if(!mat[u][V]) continue;
            int v = V+cm;
            if(visr[v] == -1) {
                visr[v] = visl[u] + 1;
                if(!match[v]) dis = visr[v];
                else {
                    int w = match[v];
                    visl[w] = visr[v] + 1;
                    q.push(w);
                }
            }
        }
    }
    return dis != INT_MAX;
}

bool findMatch(int u) {
    int sz = sg[u].size();
    for(int V=1; V<=cm; V++) {
        if(!mat[u][V]) continue;
        int v = V+cm;
        if(visr[v] == visl[u]+1) {
            visr[v] = 0;
            if(!match[v] || findMatch(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bpm() { ///HOPCROFT
    memset(match, 0, sizeof(match));
    int ans = 0;
    while(bfs()) {
        for(int i=1; i<=cm; i++) {
            if(!match[i] && findMatch(i)) ans++;
        }
    }
    return ans;
}

int main() {
//    freopen("1429i.txt", "r", stdin);
//    freopen("1429o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(g, NULL, sizeof g);
        memset(r, NULL, sizeof r);
        memset(sg, NULL, sizeof sg);
//        memset(sg, NULL, sizeof sg);

        scanf("%d %d", &n,&m);
        for(int i=1; i<=m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            g[u].pb(v);
            r[v].pb(u);
        }
        scc();

        for(int u=1; u<=cm; u++) {
            memset(vis, 0, sizeof vis);
            root = u;
            dfs3(u);
        }

//        memset(sg, NULL, sizeof sg);
//
//        for(int u=1; u<=cm; u++) {
//            for(int v=1; v<=cm; v++) {
//                if(mat[u][v]) sg[u].pb(cm+v);
//            }
//        }

//        cout << "FINAL GRAPH" << endl;
//        for(int i=1; i<=2*cm; i++) {
//            cout << i << " : " ;
//            for(int j=0; j<fg[i].size(); j++) cout << fg[i][j] << ' '; cout << endl;
//        }

//        cout << bpm() << endl;
        printf("Case %d: %d\n", t, cm-bpm());
    }
}
