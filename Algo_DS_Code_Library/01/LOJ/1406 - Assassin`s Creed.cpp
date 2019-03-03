int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

int n,m, target;
vii graph[17];
int dp[1 << 16];
bool graphMat[17][17];

void printBin(int n) {

    if(!n) return;
    printBin(n>>1);
    cout << n%2;
}

bool vis[16][1 << 16];
bool sub[1 << 16];

void dfs(int u, int mask) {
    vis[u][mask] = 1;
    sub[mask] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v][ setBit(mask,v) ]) dfs(v, setBit(mask, v));
    }
}

int getMin(int mask) {
    if(!mask) return 0;
    if(dp[mask] != -1) return dp[mask];

    int ans = 20;
    for(int vmask = mask; vmask; vmask = mask&(vmask-1)) {
        if(sub[vmask]) ans = min(ans, 1+getMin(mask ^ vmask) );
    }
    return dp[mask] = ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &m);
        for(int i=0; i<=n; i++) graph[i].clear();
        target = (1 << n) - 1;
        memset(dp, -1, sizeof dp);
        memset(sub, 0, sizeof sub);
        memset(vis, 0, sizeof vis);

        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            u--; v--;
            graph[u].pb(v);
        }
        for(int i=0; i<n; i++) dfs(i, setBit(0, i));
        printf("Case %d: %d\n", t, getMin(target));
    }
    return 0;
}
