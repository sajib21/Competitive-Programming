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

int n,m;
vii graph[105];

bool oddCycle = false;
int bfs() {
    int cntAll = 1, cntOdd = 0;
    int keys[105];
    memset(keys, -1, sizeof(keys));
    keys[1] = 0;
    queue<int>q;
    q.push(1);


    while(!q.empty()) {
        int u = q.front(); q.pop();
        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(keys[v] == -1) {
                keys[v] = keys[u] + 1;
                cntAll++;
                if(keys[v]&1) cntOdd++;
                q.push(v);
            }
            else if(keys[v] == keys[u]) oddCycle = true;
        }
    }
    if(oddCycle) return cntAll;
    if(cntAll == 1) return 0;
    else return cntAll-cntOdd;
}

int main() {

//    freopen("1185i.txt", "r", stdin);
//    freopen("1185o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        for(int i=1; i<=n; i++) graph[i].clear();
        oddCycle = false;
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        printf("Case %d: %d\n", t, bfs());
    }

    return 0;
}

