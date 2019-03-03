#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct edge{

    int u,v,w;
    edge(int uu, int vv, int ww) {
        u = uu, v = vv, w = ww;
    }
    bool operator < (const edge b) const {
        return w < b.w;
    }
};

int n,m, par[105];

int findSet(int u) {

    if(u == par[u]) return u;
    return par[u] = findSet(par[u]);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        vector<edge>edges;
        scanf("%d", &n); n++;

        int u,v,w;
        while(scanf("%d %d %d", &u,&v,&w) && (u || v || w) ) {
            edges.pb( edge(u,v,w) );
        }
        sort(edges.begin(), edges.end());
//        for(int i=0; i<edges.size(); i++) {
//            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
//            cout << u << ' ' << v << ' ' << w << endl;
//        }
        int low = 0, high = 0;
        {
            for(int i=0; i<n; i++) par[i] = i;
            int sz = edges.size(), taken=0;
            for(int i=0; i<sz && taken < n-1; i++) {
                int u = edges[i].u, v = edges[i].v, w = edges[i].w;
                if(findSet(u) != findSet(v)) {
                    par[par[u]] = par[v];
                    taken++;
                    low += w;
    //                cout << u << ' ' << v << ' ' << w << endl;
                }
            }
        }
        {
            for(int i=0; i<n; i++) par[i] = i;
            int sz = edges.size(), taken = 0;
            for(int i=sz-1; i >= 0 && taken < n-1; i--) {
                int u = edges[i].u, v = edges[i].v, w = edges[i].w;
                if(findSet(u) != findSet(v)) {
                    par[par[u]] = par[v];
                    taken++;
                    high += w;
    //                cout << u << ' ' << v << ' ' << w << endl;
                }
            }
        }
        if((low+high)%2) printf("Case %d: %d/2\n", t, low+high);
        else printf("Case %d: %d\n", t,(low+high)/2);
    }
    return 0;
}
