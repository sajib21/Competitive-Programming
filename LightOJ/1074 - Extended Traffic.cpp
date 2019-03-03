#include<bits/stdc++.h>
#define IM 8080

using namespace std;

struct edge{
    int u,v,w;
    edge(int uu, int vv, int ww) {
    u = uu; v = vv; w = ww;
    }
};

//vector<int>graph[202], cost[202];
vector<edge>edges;
int n,m;
int key[202], par[202];

void bellMan() {

    //memset(key, -129, sizeof(key));
    for(int i=1; i<=n; i++) key[i] = IM;
    for(int i=1; i<=n; i++) par[i] = i;
    key[1] = 0;

    for(int i=1; i<=n; i++) {

        for(int j=0; j<m; j++) {
            edge e = edges[j];
            int u = e.u, v = e.v, w = e.w;
            if(key[u]+w < key[v]) {
                key[v] = key[u]+w;
                par[v] = u;
                //cout << "par of " << v << " is " << u << endl;
            }
        }
    }
}

int findPar(int u) {

    if(par[u] == u) return u;
    return findPar(par[u]);
}

int main() {

    int t,T;
    cin >> T;
    for(t=1; t<=T; t++) {

        edges.clear();
        //getchar();
        //int n,m;
        int nodeWeight[202] = {0};
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> nodeWeight[i];
        }
        cin >> m;
        for(int i=0; i<m; i++) {
            int u,v;
            cin >> u >> v;
            //graph[u].push_back(v);
            //cost[u].push_back( (nodeWeight[v]-nodeWeight[u])*(nodeWeight[v]-nodeWeight[u])*(nodeWeight[v]-nodeWeight[u]) );
            edges.push_back(edge(u,v, (nodeWeight[v]-nodeWeight[u])*(nodeWeight[v]-nodeWeight[u])*(nodeWeight[v]-nodeWeight[u])));

        }

        bellMan();
        printf("Case %d:\n", t);
        int q, d;
        cin >> q;
        for(int i=0; i<q; i++) {
            cin >> d;
            if(key[d] < 3 || key[d] == IM) cout << '?' << endl;
            else if(findPar(d) != 1) cout << '?' << endl;
            else cout << key[d] << endl;
        }
    }

    return 0;
}
