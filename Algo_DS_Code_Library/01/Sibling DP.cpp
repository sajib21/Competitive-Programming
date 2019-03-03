struct info{
    int x,y,z;
    info() {x = y = z = 0;}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};
bool cmpx(info x, info y) {
    return x.x < y.x;
}
bool cmpy(info x, info y) {
    return x.y < y.y;
}

int n,u,v;
vii graph[LIM+100];
int vis[LIM+100];
int binTree[LIM+100][2];

void dfs(int u) {
    vis[u] = 1;
    int sz = graph[u].size();
    int l = -1;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            par[v] = u;
            if(l == -1) binTree[u][0] = v;
            else binTree[l][1] = v ;
            l = v;

            dfs(v);
        }
    }
}

int main() {
    memset(vis, 0, sizeof vis);
    memset(binTree, -1, sizeof binTree);

    scanf("%d", &n); ///node 1...n
    for(int i=1; i<n; i++) {
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    for(int i=1; i<=n; i++)
    cout << i << " : " << binTree[i][0] << ' ' << binTree[i][1] << endl;



    return 0;
}
