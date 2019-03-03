#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info{
    int x,y;
    info() {}
    info(int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator < (const info &b) const {
        return y > b.y;
    }
};

int n,m,s, shop[505];
vii graph[505], costs[505];
int keys[505];
int dist[18][18];

void dijkstra(int root) {
    memset(keys, -1, sizeof(keys));
    keys[root] = 0;
    priority_queue<info>pq;
    pq.push(info(root, 0));

    while(!pq.empty()) {
        info nd = pq.top(); pq.pop();
        int u = nd.x , k = nd.y;
        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i] , c = costs[u][i];
            if(keys[v] == -1 || k+c < keys[v]) {
                keys[v] = k+c;
                pq.push(info(v, keys[v]));
            }
        }
    }
}

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

info dp[18][1 << 17];
info get(int u, int mask) {
//    cout << u << ' ' << mask << endl; getchar();
    if(u == s+1) return info(0, 0);

    if(dp[u][mask].x != -1) return dp[u][mask];

    info ans = info(-1, MAX);
    for(int v=1; v<=s+1; v++) {
        info temp;
        if(!chkBit(mask, v) && dist[u][v] != -1) {
            temp = get(v, setBit(mask, v));
            if(temp.x+1 > ans.x || (temp.x+1 == ans.x && temp.y+dist[u][v] < ans.y) ) {
                ans = temp;
                ans.x++; ans.y += dist[u][v];
            }
        }

    }
//    cout << "OUT " << u << ' ' << mask << ' ' << ans.x << ' ' << ans.y << endl;
    return dp[u][mask] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        memset(dist, -1, sizeof(dist));
        scanf("%d %d %d", &n,&m, &s);
        for(int i=0; i<=n; i++) graph[i].clear() , costs[i].clear() ;
        for(int i=1; i<=s; i++) scanf("%d", &shop[i]);
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u].pb(v);
            costs[u].pb(w);
        }
//        fo

        ///
        dijkstra(0);
        for(int i=1; i<=s; i++) dist[ 0 ][ i ] = keys[ shop[i] ]; dist[0][s+1] = keys[n-1];
        ///
        for(int i=1; i<=s; i++) {
            int sh = shop[i];
            dijkstra(sh);
            for(int j=1; j<=s; j++) {
                dist[ i ][ j ] = keys[ shop[j] ];
            }
            dist[i][s+1] = keys[n-1];
        }
        ///
//        dijkstra(n-1);
//        for(int i=1; i<=s; i++) dist[ s+1 ][ i ] = keys[ shop[i] ];

//        for(int i=0; i<=s+1; i++) {
//            for(int j=0; j<=s+1; j++) {
//                cout << dist[i][j] << ' ' ;
//            }
//            cout << endl;
//        }


        info ans = get(0, 0);
        if(ans.y >= MAX) printf("Case %d: Impossible\n", t);
        else printf("Case %d: %d %d\n",t, ans.x-1, ans.y );
    }

    return 0;
}

