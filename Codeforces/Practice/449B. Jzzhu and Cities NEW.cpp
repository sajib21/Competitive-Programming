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
vi g[LIM], c[LIM], d[LIM];
ll keys[LIM];

int main() {
    scanf("%d %d %d", &n,&m,&k);
    for(int i=0; i<m; i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);
        g[u].pb(v); c[u].pb(w); d[u].pb(0);
        g[v].pb(u); c[v].pb(w); d[v].pb(0);
    }
    for(int i=0; i<k; i++) {
        int u,x;
        scanf("%d %d", &u,&x);
        g[1].pb(u); c[1].pb(x); d[1].pb(1);
    }

//    memset(keys, 127, sizeof keys);
    for(int i=1; i<=n; i++) keys[i] = MX;
    keys[1] = 0;

    priority_queue<info>pq;
    pq.push(info(1,keys[1], 0));

    int ans = 0;
    while(!pq.empty()) {
        info U = pq.top();
        pq.pop();
        int u = U.x, t = U.z; ll k = U.y;
        if(mark[u]) continue;

        mark[u] = 1;

//        cout << "OUT " << u << ' ' << k << ' ' << t << ' ' << keys[u] << endl; getchar();

        ans += t;
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i], w = c[u][i], x = d[u][i];
//            cout << "TRY " << u << ' ' << k << ' ' << x << " : " << v << ' ' << keys[v] << ' ' <<  w << endl; getchar();
            if(k+w <= keys[v]) {
                keys[v] = k+w;
//                cout << "PUSH " << u << " : " << v << ' ' << keys[v] << ' ' << x << endl; getchar();
                pq.push(info(v,keys[v], x));
            }
//            else if(k+w == keys[v] && )
        }
    }
    printf("%d\n", k-ans);
}



