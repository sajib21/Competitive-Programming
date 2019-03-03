#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000
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

int n,m;
int mh[55], ma[55], wh[55], wa[55];
int md[55], wd[55];
int prefer[110];
vii graph[55];
int match[110], vis[110];

bool findMatch(int u) {
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            vis[v] = 1;
            if(!match[v] || findMatch(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    memset(match, 0, sizeof(match));
    int ans = 0;
    for(int i=1; i<=m; i++) {
        memset(vis, 0, sizeof(vis));
        if(findMatch(i)) ans++;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &m,&n);
        for(int i=1; i<=m; i++) graph[i].clear();
        for(int i=1; i<=m; i++) scanf("%d %d %d", &mh[i], &ma[i], &md[i]);
        for(int i=1; i<=n; i++) scanf("%d %d %d", &wh[i], &wa[i], &wd[i]);

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(abs(mh[i]-wh[j]) <= 12 && abs(wa[j]-ma[i]) <= 5 && !(md[i]^wd[j]) ) graph[i].pb(m+j) ;
            }
        }
        printf("Case %d: %d\n", t, bpm());
    }
    return 0;
}

