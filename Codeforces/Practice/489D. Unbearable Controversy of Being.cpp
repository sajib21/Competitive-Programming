#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define LIM 3003

using namespace std;

int n,m;
vii graph[LIM];
int vis[LIM], cnt[LIM];

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
    }
    int ans = 0;
    for(int u=1; u<=n; u++) {
//        cout << u << endl;
        vii ff;
        for(int i=0; i<graph[u].size(); i++) {
            ff.pb(graph[u][i]);
        }
        for(int i=0; i<ff.size(); i++) {
            int v = ff[i];
            for(int j=0; j<graph[v].size(); j++) {
                int w = graph[v][j];
                if(w == u || w == v) continue;
//                cout << "BEFORE " << u << ' ' << v << ' ' << w << ' ' << vis[w] << ' ' << cnt[w] << endl;  //getchar();
                if(vis[w] != u) {
                    vis[w] = u;
                    cnt[w] = 0;
                }
                ans += cnt[w];
//                cout << "AFTER " << u << ' ' << v << ' ' << w << ' ' << vis[w] << ' ' << cnt[w] << endl; getchar();
                cnt[w]++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
