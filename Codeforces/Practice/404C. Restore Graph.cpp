///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
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
 info node[LIM+10];
int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int n,k;

    scanf("%d %d", &n,&k);
    for(int i=1; i<=n; i++) scanf("%d", &node[i].y) , node[i].x = i;
    sort(node+1, node+n+1, cmpy);

    if(n == 1) {
        if(!node[1].y) printf("0\n");
        else printf("-1\n");
        return 0;
    }

    if((!node[2].y || node[1].y) ) {
        printf("-1\n");
        return 0;
    }

    vii graph[LIM+10];
    queue<info>q;
    q.push(info(node[1]));

    for(int i=2; i<=n; i++) {
//        info cur = q.front();
        while(!q.empty() && (node[i].y - q.front().y > 1 || graph[q.front().x].size() == k ) ) q.pop();
        if(q.empty() || node[i].y == q.front().y) {
            printf("-1\n");
            return 0;
        }
        int u = q.front().x , v = node[i].x;
        graph[u].pb(v);
        graph[v].pb(u);
        q.push(node[i]);
    }

    printf("%d\n", n-1);
    for(int i=1; i<=n; i++) {
        int sz = graph[i].size();
        for(int j=0; j<sz; j++) {
            if(graph[i][j] < i) continue;
            printf("%d %d\n", i, graph[i][j]);
        }
    }

    return 0;
}
