#include<bits/stdc++.h>
#define MX 100005
#define pb push_back
using namespace std;

vector<int>graph[MX];
int val[MX];
int n,q;
int lev[MX];
int sparse[MX][17];

void bfs(int root) {

    memset(lev, -1, sizeof(lev));
    lev[0] = 0;

    queue<int>q;
    q.push(0);

    while(!q.empty()) {

        int u = q.front();
        q.pop();
        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(lev[v] == -1) {
                lev[v] = lev[u] + 1;
                sparse[v][0] = u;
                q.push(v);
            }
        }
    }
}

void makeSparse() {

    memset(sparse, -1, sizeof(sparse));
    bfs(0);
    for(int par=1; (1 << par) < n; par++) {
        for(int i=1; i<n; i++) {
            if(sparse[i][par-1] != -1) sparse[i][par] = sparse[ sparse[i][par-1] ][par-1];
        }
    }
}

int greatestParent(int v, int least) {

    int up = log2(lev[v]);
    while(up >= 0) {
        int par = sparse[v][up];
//        cout << "check " << par << ' ' << val[par] << endl;
        if(par != -1 && val[par] >= least) {
//            cout << par << " tomo " << val[par] << endl;
            v = par;
        }
        up--;
    }
    return v;
}


int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

//        memset(sparse, -1, sizeof(sparse));
        scanf("%d %d", &n,&q);
        for(int i=0; i<=n; i++) graph[i].clear();

        for(int i=1; i<n; i++) {
            int p,s;
            scanf("%d %d", &p,&s);
            graph[i].pb(p);
            graph[p].pb(i);
            val[i] = s;
        }
        val[0] = 1;

        makeSparse();

        printf("Case %d:\n", t);

        while(q--) {
            int k,v;
            scanf("%d %d", &k,&v);
            printf("%d\n", greatestParent(k,v) );
        }
    }

    return 0;
}
