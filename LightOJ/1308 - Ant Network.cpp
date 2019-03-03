///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

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

int n,m, dis[LIM+100], low[LIM+100], arti[LIM+100], tim, cnt, artiCnt, cmp;
vii graph[LIM+100], g[LIM+100];

void dfs(int u, int par = -1) {
//    cout << "IN " << u << ' ' << par << endl; getchar();
    low[u] = dis[u] = ++tim;
    int v, sz = graph[u].size(), comp = 0;

    for(int i = 0; i < sz; ++i) {
        v = graph[u][i];
        if(v == par) continue;
        else if(dis[v]) low[u] = min(low[u], dis[v]);
        else {
            ++comp;
            dfs(v, u);

//            cout << "DAMI " << par << ' ' << dis[u] << ' ' << low[v] << endl; getchar();
            if(par == -1 && comp > 1) arti[u] = true;
            if(par != -1 && low[v] >= dis[u]) {
                arti[u] = 1;
//                cout << "ARTI " << u << endl; getchar();
            }

            low[u] = min(low[u], low[v]);
        }
    }
}

void dfs1(int u) {
//    cout << u << endl; getchar();

    if(!arti[u]) cnt++;
    else {
        if(dis[u] != cmp) artiCnt++;
            dis[u] = cmp;
        //arti[u] = cmp;
//        cout << "GETTING " << u << ' ' << cnt << ' ' << artiCnt << endl;
        return;
    }
    dis[u] = cmp;

    int sz = graph[u].size(), v;
    for(int i=0; i<sz; i++) {
        v = graph[u][i];
        if(!dis[v] || arti[v]) dfs1(v);
    }
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        memset(graph, NULL, sizeof graph);
        memset(g, NULL, sizeof g);
        memset(arti, 0, sizeof arti);
        memset(dis, 0, sizeof dis);
        memset(low, 0, sizeof low);

        tim = 0;
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        for(int u=0; u<n; u++) if(!dis[u]) dfs(u);
        memset(dis, 0, sizeof dis);

//        for(int u=0; u<n; u++) cout << low[u] << ' ' ; cout << endl;
//        for(int u=0; u<n; u++) cout << arti[u] << ' ' ; cout << endl; getchar();

        ull a = 0, b = 1;
        cmp = 0;
        for(int u=0; u<n; u++) {
            if(!dis[u] && !arti[u]) {
                cnt = 0; artiCnt = 0; cmp++;
                dfs1(u);

//                cout << "DSU " << u << ' ' << cnt << ' ' << artiCnt << endl;

                if(artiCnt == 0) {
                    a += 2;
                    b *= cnt*(cnt-1) / 2;
                }
                else if(artiCnt == 1) {
                    a++;
                    b *= cnt;
                }
            }
        }
        printf("Case %d: %llu %llu\n", t, a,b);
    }

    return 0;
}
