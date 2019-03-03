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

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

struct info {
    bool flag;
    double val;
    info() {}
    info(bool bl, double vv) {
        flag = bl; val = vv;
    }
};

int n,m, MAXX;
const int lim = 1<<15;
vii graph[17], costs[17];
info dp[16][lim];



info getexp(int u, int mask) {
    if(mask == MAXX) return info(true, 0);


    if(dp[u][mask].val != -1.0) return dp[u][mask];

    int sz = graph[u].size();
    int rem = 0;

    double ans = 5;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!chkBit(mask, v)) {
            info temp = getexp(v, setBit(mask, v));
            if(!temp.flag) continue;

            ans += (costs[u][i] + temp.val);
            rem++;
        }
    }

    if(!rem) return dp[u][mask] = info(false, 0);
    return dp[u][mask] = info(true, 1.0 * ans / rem);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        for(int i=0; i<=15; i++) for(int j=0; j<lim; j++) dp[i][j].val = -1;
        for(int i=0; i<16; i++) graph[i].clear() , costs[i].clear();
//        cout << dp[0][0] << endl;
        scanf("%d %d", &n,&m);
        MAXX = ( (1 << n) - 1);
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(w);
            costs[v].pb(w);
        }
        printf("Case %d: %.10lf\n", t, getexp(0, 1).val);
    }
    return 0;
}
