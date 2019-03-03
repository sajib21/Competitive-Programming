#include<bits/stdc++.h>
#define LIM 100005
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n;
vi g[LIM];
int col[LIM], a[LIM], sz[LIM];

vi* vec[LIM];
int res[LIM];

void getSZ(int u, int p) {
    sz[u]++;
    for(auto v : g[u]) {
        if(v == p) continue;
        getSZ(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int p, int keep) {
    int mx = -1, big = -1;
    for(auto v : g[u]) {
        if(v != p && sz[v] > mx) {
            mx = sz[v];
            big = v;
        }
    }

    for(auto v : g[u]) if(v != p && v != big) dfs(v, u, 0);

    if(big != -1) {
        dfs(big, u, 1);
        vec[u] = vec[big];
    }
    else vec[u] = new vi();
    vec[u]->pb(u);
    res[ col[u] ]++;
    ///or res[ col[u] ] += a[u];

    for(auto v : g[u]) {
        if(v != p && v != big) {
            for(auto x : *vec[v]) {
                vec[u]->pb(x);
                res[ col[x] ]++;
                ///or res[ col[x] ] += a[x]
            }
        }
    }

    ///QUERY OF SUBTREE OF V HERE!!

    if(keep == 0) {
        for(auto x : *vec[u]) {
            res[ col[x] ]--;
            ///or res[ col[x] ] -= a[x]
        }
    }
}

int main() {
    getSZ(1, -1);
    dfs(1, -1, 0);
}
