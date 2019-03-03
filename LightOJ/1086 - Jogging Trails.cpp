#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000000LL
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int resBit(int mask, int pos) { return mask & ~(1 << pos); }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

int n,m, u,v, degree[17];
ll graph[17][17];
ll w, total;

ll dp[1 << 16];

ll getMin(int mask) {
    if(!mask) return 0;

    if(dp[mask] != -1) return dp[mask];
    ll ans = MAX;
    for(int u=1; u<=n; u++) if(chkBit(mask, u)) {
        for(int v=1; v<=n; v++) if(chkBit(mask, v)) {
            if(u != v) {
                ans = min(ans, graph[u][v]+getMin( resBit( resBit(mask, u) , v ) ) );
            }
        }
    }
    return dp[mask] = ans;
}

int main() {

//    memset(graph, 127, sizeof(graph));
//    cout << graph[0][0] << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &m);
        total = 0;
        memset(degree, 0, sizeof(degree));
        memset(dp, -1, sizeof(dp));
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) graph[i][j] = graph[j][i] = MAX;
//        memset(graph, 127, sizeof(graph));
        for(int i=0; i<m; i++) {
            scanf("%d %d %lld", &u,&v,&w);
            graph[u][v] = graph[v][u] = min(graph[u][v], w);
            degree[u]++; degree[v]++;
            total += w;
        }

        for(int k=1; k<=n; k++) {
            for(int u=1; u<=n; u++) {
                for(int v=1; v<=n; v++) {
                    graph[u][v] = min(graph[u][v] , graph[u][k]+graph[k][v]);
                }
            }
        }
        int mask = 0;
        for(int u=1; u<=n; u++) if(degree[u] & 1) mask |= (1 << u);

        printf("Case %d: %lld\n", t, total+getMin(mask));
    }
    return 0;
}
