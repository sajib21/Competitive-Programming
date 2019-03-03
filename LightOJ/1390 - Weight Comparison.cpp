#include<bits/stdc++.h>
#define LIM 100005
#define pii pair<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define vp vector<pii>
#define pb(x) push_back(x)
using namespace std;

struct info {
    int x,y,z;
    info() {}
    info(int xx, int yy, int zz=0) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        return y > b.y;
    }
};

vi g[5005];
int n,m, in[5005], lev[5005];

int main() {
//    freopen("1390i.txt", "r", stdin);
//    freopen("1390o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(g, NULL, sizeof g);
        memset(in, 0, sizeof in);
//        memset(key, 127, sizeof key);

        scanf("%d %d", &n,&m);
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            g[u].pb(v);
            in[v]++;
        }

        for(int i=1; i<=n; i++) sort(g[i].begin(), g[i].end());

        vp sol;
        priority_queue<info>q;

        for(int u=1; u<=n; u++) if(!in[u]) {
            q.push(info(u,0, 0) );
            lev[u] = 0;
        }

        while(!q.empty()) {
            info cur = q.top(); q.pop();
            int u = cur.x, k = cur.y, p = cur.z;
            if(k > in[u]) continue;

            cout << "LEV " << u << ' ' << lev[u] << endl;
//            if(p) sol.pb(pii(p, u));

            for(int i=0; i<g[u].size(); i++) {
                int v = g[u][i];
                in[v]--;
                q.push(info(v, in[v], u));
                lev[v] = lev[u] + 1;
            }
        }

        for(int u=1; u<=n; u++) {
            for(int i=0; i<g[u].size(); i++) {
                int v = g[u][i];
                if(lev[u]+1 == lev[v]) sol.pb(pii(u,v));
            }
        }

        printf("Case %d: %d\n", t, sol.size());
        for(int i=0; i<sol.size(); i++) printf("%d %d\n", sol[i].ff, sol[i].ss);
    }
}
/*
1
6 8
1 2
1 4
1 3
2 4
3 4
4 6
4 5
5 6


*/
