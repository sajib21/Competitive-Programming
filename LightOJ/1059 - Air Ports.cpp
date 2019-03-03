#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

struct edge{
    int u,v, cost;
    edge() {}
    edge(int uu, int vv, int cc) {
        u = uu; v = vv; cost = cc;
    }
    bool operator < (const edge &b) const {
        return cost < b.cost;
    }
};

int n,m,a, par[LIM/10 + 10];
edge edges[LIM+10];

int findSet(int n) {
    if(par[n]==n) return n;
    return par[n] = findSet(par[n]);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &n,&m, &a);
        memset(edges, 0 ,sizeof(edges));

        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            edges[i] = edge(u,v,w);
        }
        sort(edges, edges+m);
        for(int i=1; i<=n; i++) par[i] = i;

        int mst = 0 , taken = 0;
        for(int i=0; i<m; i++) {
            edge e = edges[i];
            int u = e.u, v = e.v , c = e.cost;
            if(findSet(u) != findSet(v) && c < a) {
                par[ par[u] ] = par[v];
                taken++;
                mst += c;
            }
        }
        printf("Case %d: %d %d\n", t, mst+(n-taken)*a, n-taken );
    }

    return 0;
}
