#include<bits/stdc++.h>
#define LIM 100005
#define vi vector<int>
#define pb push_back
#define ll long long int
#define MX 10000000000000000LL
using namespace std;

struct info {
    int x, z; ll y;
    info() {}
    info(int xx, ll yy, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        if(y == b.y) return z > b.z;
        return y > b.y;
    }
};

int n,m,k, mark[LIM], train[LIM];
vi g[LIM], c[LIM];
ll keys[LIM];

int main() {
    scanf("%d %d %d", &n,&m,&k);
    for(int i=0; i<m; i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);
        g[u].pb(v); c[u].pb(w);
        g[v].pb(u); c[v].pb(w);
    }
//    memset(keys, 127, sizeof keys);
    for(int i=1; i<=n; i++) keys[i] = MX;
    keys[1] = 0;

    priority_queue<info>pq;
    pq.push(info(1,keys[1]));

    while(!pq.empty()) {
        info U = pq.top();
        pq.pop();
        int u = U.x; ll k = U.y;
        if(k > keys[u]) continue;

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i], w = c[u][i];
            if(k+w < keys[v]) {
                keys[v] = k+w;
                pq.push(info(v,keys[v]));
            }
        }
    }

    for(int i=0; i<k; i++) {
        int u,x;
        scanf("%d %d", &u,&x);
        mark[u] = 1; train[u] = x;
        if(x < keys[u]) {
            pq.push(info(u,x, 1));
            keys[u] = x;
        }
    }

//    cout << "PRIMARY " << endl;
//    for(int i=1; i<=n; i++) cout << i << ' ' << keys[i] << endl;

    int ans = 0;
    while(!pq.empty()) {
        info U = pq.top();
        pq.pop();
        int u = U.x, t = U.z; ll k = U.y;
        if(k > keys[u]) continue;

//        cout << u << ' ' << k << ' ' << t << ' ' << keys[u] << endl;

        ans += t;
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i], w = c[u][i];
            if(k+w < keys[v]) {
                keys[v] = k+w;
                pq.push(info(v,keys[v]));
            }
        }
    }
    printf("%d\n", k-ans);
}



