#include<bits/stdc++.h>
#define pii     pair<int,int>
#define ff      first
#define ss      second
#define vi      vector<int>
#define pb(x)   push_back(x)
#define ll      long long int
#define LIM     2020
#define MOD     1000000007

using namespace std;

int n,d, a[LIM], ok[LIM];
vi g[LIM];

ll dfs(int u, int p, int mx) {
    ll ans = 1;
    for(auto v : g[u]) {
        if(v == p || ok[v] || mx-a[v] > d) continue;
        ans *= 1+dfs(v, u, mx);
        ans %= MOD;
    }
    return ans;
}

ll f(int u) {
    ll ans = 1;
    for(auto v : g[u]) {
        ans *= (1+dfs(v, u, a[u]));
        ans %= MOD;
    }
    return ans;
}

int main() {
    scanf("%d %d", &d,&n);
    priority_queue<pii>pq;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        pq.push(pii(a[i], i));
    }
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }


    ll ans = 0;

    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int u = cur.ss, k = cur.ff;
        ans += dfs(u, u, a[u]);
        ans %= MOD;
        ok[u] = 1;
    }

    cout << ans << endl;
}
