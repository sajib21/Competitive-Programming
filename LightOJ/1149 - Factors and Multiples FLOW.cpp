#include<bits/stdc++.h>

using namespace std;

int n,m,tot, setA[110], setB[110], ans;
vector<int>graph[220];
int mat[220][220];
int vis[220], par[220];

int pfs(int root, int dest) {

//    cout << root << ' ' << dest << endl;

    int ans = -1;
    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));
    queue<int>q;
    vis[root] = 1;
    q.push(root);

    while(!q.empty()) {

        int u = q.front();
        q.pop();

//        cout << "NOW " << u << endl;

        if(u == dest) {
            ans = 1;
//            cout << "YES" << endl;
            break;
        }

        int sz = graph[u].size();
//        cout << "BUG " << sz << endl;
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(!vis[v] && mat[u][v] == 1) {
                vis[v] = 1;
                par[v] = u;
//                mat[u][v] = 0;
//                mat[v][u] = 1;
//                cout << "PUSHING " << endl;
                q.push(v);
            }
        }
    }
    int u,v;
    v = dest;
    u = par[dest];

    while(u != -1) {
//        cout << v << " -> " << u << ' ';
        mat[u][v] = 0;
        mat[v][u] = 1;
        u = par[u];
        v = par[v];



//        cout << "BUG" << u << ' ' << v << endl;
    }
//    cout << endl;
    return ans;
}

int flow(int root, int dest) {

    int ans = 0, temp = -1;
    while(true) {
        temp = pfs(root, dest);
        if(temp == -1) break;
        ans++;
    }
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(mat, 0, sizeof(mat));
        for(int i=0; i<=220; i++) graph[i].clear();

        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &setA[i]);
        scanf("%d", &m);
        for(int i=1; i<=m; i++) scanf("%d", &setB[i]);

        tot = n+m;

        for(int i=1; i<=n; i++) {
            mat[0][i] = 1;
            graph[0].push_back(i);
            for(int j=1; j<=m; j++) {
                mat[n+j][tot+1] = 1;
                if( abs(setB[j]) % abs(setA[i]) == 0) {
                    mat[i][n+j] = 1;
                    graph[i].push_back(n+j);
                    graph[n+j].push_back(i);
                }
            }
        }
        for(int j=1; j<=m; j++) graph[n+j].push_back(tot+1);

//        for(int i=0; i<=13; i++) {
//            for(int j=0; j<=13; j++) {
//                cout << mat[i][j] << ' ';
//            }
//            cout << endl;
//        }
//        for(int i=0; i<tot; i++) {
//            for(int j=0; j<graph[i].size(); j++) {
//                cout << graph[i][j] << ' ';
//            }
//            cout << endl;
//        }
        printf("Case %d: %d\n", t, flow(0, tot+1) );
    }
    return 0;
}
