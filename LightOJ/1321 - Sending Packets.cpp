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

using namespace std;

struct info {
    int id;
    double yes, no;
    info() {}
    info(int i, double y, double n) {
        id = i; yes = y; no = n;
    }
    bool operator < (const info &b) const {
        return yes < b.yes;
    }
};

int N,m,s,k;
vii graph[110], costs[110];

double dijkstra() {

    double keys[110];
    for(int i=0; i<N; i++) keys[i] = 0.0;
    keys[0] = 10000.0;
    priority_queue<info>pq;
    pq.push(info(0, 1, 0));

    while(!pq.empty()) {
        info nd = pq.top();
        pq.pop();
        int u = nd.id;
        double y = nd.yes , n = nd.no;

//        cout << "IN " << u << ' ' << y << ' ' << n << endl;

        if(u == N-1) {
//            cout << "ANS " << 2.0*k * (y+n) / (1-n) << endl;
            return 2.0*k * (y+n) / (1-n);
        }

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            double c = costs[u][i]/100.0;
            if(y*c > keys[v]) {
                keys[v] = y*c;
                pq.push(info(v, keys[v], y*(1.0-c) + n));
            }
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %d", &N,&m,&s,&k);
        for(int i=0; i<N; i++) graph[i].clear(), costs[i].clear();
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(w);
            costs[v].pb(w);
        }
        printf("Case %d: %.10lf\n", t, s*dijkstra());
//        cout << "BUG" << endl;
    }
    return 0;
}
