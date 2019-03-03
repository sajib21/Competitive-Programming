#include<bits/stdc++.h>
#define LIM 50004
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n, k, ans=0;
int dp[LIM][505];
vi g[LIM];

void f(int u, int p) {
    dp[u][0] = 1;
    for(int v : g[u]) {
        if(v == p) continue;
        f(v, u);
        for(int i=0; i<k; i++) ans += dp[u][i]*dp[v][k-i-1];
        for(int i=0; i<k; i++) dp[u][i+1] += dp[v][i];
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    f(1, 0);
    cout << ans << endl;
}

