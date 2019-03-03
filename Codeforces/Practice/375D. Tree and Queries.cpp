
#include<bits/stdc++.h>
#define LIM 100005
#define vi vector<int>
#define pb(x) push_back(x)
#define ll long long int
#define pii pair<ll,ll>

//#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


typedef tree< pair<ll,ll> ,null_type,less< pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//using namespace std;

int n, m;
vi g[LIM], q[LIM], in[LIM];
int col[LIM], a[LIM], sz[LIM];

vi* vec[LIM];
int cnt[LIM];
ordered_set res;
//map<int,ll> res;
ll ans[LIM];

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

    if(cnt[ col[u] ]) res.erase(res.lower_bound(pii(cnt[ col[u] ], col[u])));
    cnt[ col[u] ]++;
    res.insert(pii(cnt[ col[u] ], col[u]));
    ///or res[ col[u] ] += a[u];

//    cout << "INIT " << u << endl;
//    for(auto it : res) cout << it.first << ' ' << it.second << endl;
//    getchar();

    for(auto v : g[u]) {
        if(v != p && v != big) {
            for(auto x : *vec[v]) {
                vec[u]->pb(x);
//                cout << "SETTING " << v << ' ' << x << ' ' << col[x] << ' ' << cnt[ col[x] ] << ' ' << res[ cnt[ col[x] ] ] << endl; getchar();
                if(cnt[ col[x] ]) res.erase(res.lower_bound(pii(cnt[ col[x] ], col[x])));
//                if(cnt[ col[x] ]) res[ cnt[ col[x] ] ]--;
//                if(!res[ cnt[ col[x] ] ]) res.erase( cnt[ col[x] ] );
                cnt[ col[x] ]++;
                res.insert(pii(cnt[ col[x] ], col[x]));
//                res[ cnt[ col[x] ] ]++;
                ///or res[ col[x] ] += a[x]
            }
        }
    }

    ///QUERY OF SUBTREE OF V HERE!!
//    cout << "QUERY " << u << endl;
//    for(auto it : res) cout << it.first << ' ' << it.second << endl;
//    getchar();

    for(int i=0; i<q[u].size(); i++) {
        int k = q[u][i], id = in[u][i];
        ans[id] = res.size() - res.order_of_key(pii(k,0));
    }

//    cout << "Paisi " << u << ' ' << it->first << ' ' << it->second << endl;
//    getchar();

    if(keep == 0) {
//            res.clear();
        for(auto x : *vec[u]) {

            if(cnt[ col[x] ]) res.erase(res.lower_bound(pii(cnt[ col[x] ], col[x])));
            cnt[ col[x] ]--;
            if(cnt[ col[x] ]) res.insert(pii(cnt[ col[x] ], col[x]));
//            cnt[x] = 0;
//            res[ cnt[ col[x] ] ]--;
//            if(res[ cnt[ col[x] ] ] == 0) {
//                res.erase(cnt[ col[x] ]);
//            }
//            cnt[ col[x] ]--;
//            if(cnt[ col[x] ]) res[ cnt[ col[x] ] ]++;

//            ///or res[ col[x] ] -= a[x]
        }
    }

//    cout << "FIN " << u << endl;
//    for(auto it : res) cout << it.first << ' ' << it.second << endl;
//    getchar();

}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &col[i]);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }

    getSZ(1, -1);

    for(int i=0; i<m; i++) {
        int v,k;
        scanf("%d %d", &v,&k);
        q[v].pb(k);
        in[v].pb(i);
    }

    dfs(1, -1, 0);

    for(int i=0; i<m; i++) printf("%d\n", ans[i]);
}
