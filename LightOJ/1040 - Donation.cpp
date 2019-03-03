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
        scanf("%d", &n);

        int u,v,w;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &w);
                if(w) edges.pb( edge(i,j,w) );
            }
        }
//        cout << "bug" << endl;
        sort(edges.begin(), edges.end());
//        for(int i=0; i<edges.size(); i++) {
//            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
//            cout << u << ' ' << v << ' ' << w << endl;
//        }
        int low = 0;

            for(int i=0; i<n; i++) par[i] = i;
            int sz = edges.size(), taken=0;
            for(int i=0; i<sz; i++) {
                int u = edges[i].u, v = edges[i].v, w = edges[i].w;
                if(u == v) low += w;
                else if(findSet(u) != findSet(v)) {
                    par[par[u]] = par[v];
                    taken++;
    //                cout << u << ' ' << v << ' ' << w << endl;
                }
                else low += w;
            }


        if(taken == n-1) printf("Case %d: %d\n", t, low);
        else printf("Case %d: -1\n", t);
    }
    return 0;
}
