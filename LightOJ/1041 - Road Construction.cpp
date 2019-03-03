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

        map<string, int> mp;
        vector<edge>edges;

        n = 1;
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            int u,v, cost;
            string city1, city2;
            cin >> city1 >> city2 >> cost;
            if(!mp[city1]) mp[city1] = n, n++; //, cout << city1 << ' ' << mp[city1] << endl;
            if(!mp[city2]) mp[city2] = n, n++; //, cout << city2 << ' ' << mp[city2] << endl;
            u = mp[city1], v = mp[city2];
            edges.pb( edge(u,v,cost) );
//            cout << u << ' ' << v << ' ' << cost << endl;

        }
        sort(edges.begin(), edges.end());

//        for(int i=0; i<edges.size(); i++) {
//            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
//            cout << u << ' ' << v << ' ' << w << endl;
//        }

        for(int i=0; i<n; i++) par[i] = i;

        int sz = edges.size(), taken = 0, ans = 0;

        for(int i=0; i<sz && taken < n-2; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(findSet(u) != findSet(v)) {
                par[par[u]] = par[v];
                taken++;
                ans += w;
//                cout << u << ' ' << v << ' ' << w << endl;
            }
        }
        if(taken != n-2) printf("Case %d: Impossible\n", t);
        else printf("Case %d: %d\n", t,ans);
    }
    return 0;
}
