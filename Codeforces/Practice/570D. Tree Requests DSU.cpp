#include<bits/stdc++.h>
#define LIM 500005
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,m;
vi g[LIM];
int col[LIM], sz[LIM], qu[LIM], qh[LIM];
char a[LIM];
vi q[LIM], in[LIM];

vi* vec[LIM];
int res[LIM][30];
int ans[LIM];

void getSZ(int u, int p, int d) {
    sz[u]++; col[u] = d;
    for(auto v : g[u]) {
        if(v == p) continue;
        getSZ(v, u, d+1);
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
    res[ col[u] ][ a[u-1]-'a' ]++;
    ///or res[ col[u] ] += a[u];

//    cout << "INIT " << u << endl;
//    for(int i=1; i<=3; i++) {
//        for(int j=0; j<26; j++) cout << res[i][j] << ' ' ;
//        cout << endl;
//    }
//    getchar();

    for(auto v : g[u]) {
        if(v != p && v != big) {
            for(auto x : *vec[v]) {
                vec[u]->pb(x);
                res[ col[x] ][ a[x-1]-'a' ]++;
                ///or res[ col[x] ] += a[x]
            }
        }
    }

    ///QUERY OF SUBTREE OF V HERE!!
    for(int i=0; i<q[u].size(); i++) {
        int h = q[u][i];
        int cnt = 0;
        for(int j=0; j<26; j++) cnt += (res[ h ][ j ]&1);
        ans[ in[u][i] ] = (cnt < 2);
    }

//    cout << "QUERY " << u << endl;
//    for(int i=1; i<=3; i++) {
//        for(int j=0; j<26; j++) cout << res[i][j] << ' ' ;
//        cout << endl;
//    }
//    getchar();

    if(keep == 0) {
        for(auto x : *vec[u]) {
            res[ col[x] ][ a[x-1]-'a' ]--;
            ///or res[ col[x] ] -= a[x]
        }
    }
}

int main() {
    scanf("%d %d", &n,&m);
    for(int v=2; v<=n; v++) {
        int u;
        scanf("%d", &u);
        g[u].pb(v);
    }
    scanf("%s", a);


    for(int i=0; i<m; i++) {
        scanf("%d %d", &qu[i], &qh[i]);
        q[ qu[i] ].pb(qh[i]);
        in[ qu[i] ].pb(i);
    }

    getSZ(1, -1, 1);
    dfs(1, -1, 0);

    for(int i=0; i<m; i++) {
        if(ans[i]) printf("Yes\n");
        else printf("No\n");
    }
}
