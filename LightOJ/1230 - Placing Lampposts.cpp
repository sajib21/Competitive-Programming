/// MINIMUM VERTEX COVER
/// YOU JUST HAVE TO KEEP AN EXTRA NUMBER, THE COUNT OF ROADS BETWEEN TWO LIGHTS
/// YOU CAN DO IT SIMPLY. JUST ADD ONE WHEN THE OP (PREVIOUS CONDITION OF LIGHT) IS 1 AND MVC RESULT CAN BE FOUND IF CURRENT POSITION IS TAKEN
/// JUST NEED A FEW MORE CONDITIONS

#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info{
    int mn, one;
    info() {}
    info(int mm, int oo) {
        mn = mm; one = oo;
    }
    info operator + (const info &b) const {
        return info(mn+b.mn , one+b.one);
    }
};

int n,m;
vii graph[1010];
int vis[1010], par[1010], comp[1010], cmp, compVis[1010];
info dp[1010][2], dr[1010][2];

void dfs(int u) {
    vis[u] = 1;
    comp[u] = cmp;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            par[v] = u;
            dfs(v);
        }
    }
}


info getMin(int u, int op) {

//    cout << "IN " << u << ' ' << op << endl;

    if(dp[u][op].mn != -1) return dp[u][op];
    info ansa , ansb;
    ansa.mn = 1;
    if(op && par[u] != -1) ansa.one = 1;
    else ansa.one = 0;
    ansb = info(0,0);

    int sz = graph[u].size();
    if(sz == 0) return info(0,0);
    if(sz == 1 && par[u] != -1) {
        return dp[u][op] = info(!op, 0);
    }
//    cout <<"BUGGY" << endl;

    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(v != par[u]) {
//            cout << "GOING " << v << endl;
            ansa = ansa + getMin(v, 1);
            if(op) ansb = ansb + getMin(v, 0);
//            cout << u << ' ' << v << ' ' << t << endl;
        }
    }
    if(!ansb.mn) return dp[u][op] = ansa;
    if(ansa.mn < ansb.mn) return dp[u][op] = ansa;
    else if(ansa.mn > ansb.mn) return dp[u][op] = ansb;
    else if(ansa.one > ansb.one) return dp[u][op] = ansa;
    else return dp[u][op] = ansb;
//    return dp[u][op] = ansa.mn < ansb.mn ? ansa : ansb;// min(ansa,ansb) ;
}

//int getOne(int u, int op, )

int main() {

//    freopen("1230i.txt", "r", stdin);
//    freopen("1230o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) graph[i].clear();
        cmp = 0;
        memset(vis, 0, sizeof(vis));
        memset(par, -1, sizeof(par));
        memset(compVis, 0, sizeof(compVis));
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        for(int u=0; u<n; u++) if(!vis[u]) {
            cmp++;
            dfs(u);
        }

        int ans1 = 0;
        info ans = info(0,0);
        for(int u=0; u<n; u++) {
            if(!compVis[ comp[u] ]) {
                compVis[ comp[u] ] = 1;
//                cout << "BUG" << endl;
//                ans1 += getMin(u, 1);
                ans = ans + getMin(u, 1);
            }
        }

        printf("Case %d: %d %d %d\n", t, ans.mn, ans.one, m-ans.one);
//        cout << "FIRST " << ans << endl;
    }
    return 0;
}
