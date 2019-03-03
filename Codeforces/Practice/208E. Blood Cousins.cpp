#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define LIM 100005

using namespace std;

int n;
vi g[LIM], lv[LIM];
int tim = 0, vis[LIM], d[LIM], e[LIM], par[LIM][22];

void dfs(int u, int lev) {
    vis[u] = lev; d[u] = ++tim; lv[ lev ].pb(tim);
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        par[v][0] = u;
        dfs(v, lev+1);
    }
    e[u] = tim;
}

int getPar(int u, int p) {
    int up = 19;
    while(up >= 0) {
//        cout << u << ' ' << p << ' ' << (1 << up) <<  endl; getchar();
        if((1 << up) <= p) {
            u = par[u][up];
            p -= (1 << up);
        }
        up--;
    }
    return u;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int j;
        scanf("%d", &j);
        g[j].pb(i);
    }

//    for(int u=0; u<=n; u++) {
//        cout << u << " : ";
//        for(int i=0; i<g[u].size(); i++) cout << g[u][i] << ' ' ;
//        cout << endl;
//    }

    for(int u=0; u<=n; u++) if(!vis[u]) dfs(u,0);
    for(int p=1; p<20; p++) {
        for(int u=1; u<=n; u++) {
            par[u][p] = par[ par[u][p-1] ][ p-1 ];
        }
    }

//    cout << "bug" << endl;

    int m;
    scanf("%d", &m);
    for(int mm=0; mm<m; mm++) {
        int v,p;
        scanf("%d %d", &v, &p);
        int lev = vis[v];
        if(p >= lev) {
            if(mm) printf(" ");
            printf("0");
            continue;
        }
        int u = getPar(v,p);




//        for(int i=0; i<lv[lev].size(); i++) cout << lv[lev][i] << ' ' ; cout << endl;
        int x = lower_bound(lv[lev].begin(), lv[lev].end(), d[u]) - lv[lev].begin();
        int y = upper_bound(lv[lev].begin(), lv[lev].end(), e[u]) - lv[lev].begin();
//        cout << "par " << v << ' ' << lev << ' ' << u << ' ' << d[u] << ' ' << e[u] << ' ' << x << ' ' << y << endl;
        if(mm) printf(" ");
        printf("%d", y-x-1);
    }
    printf("\n");
    return 0;

}
