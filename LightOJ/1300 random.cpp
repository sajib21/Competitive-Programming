///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             1000
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

int n,m, u,v, graph[LIM+100][LIM+100];
int lim = 10;

int main() {

    freopen("1300i.txt", "w", stdout);
//    freopen("o.txt", "w",stdout);

    srand(time(NULL));

    int T;
//    scanf("%d", &T);
    T = 10;
    cout << T << endl;
    for(int t=1; t<=T; t++) {
            memset(graph, 0, sizeof graph);
        n = rand() % lim + 3; //cout << n << endl;
        m = rand() % (n*(n-1)/2) + 1;
//        cout << n << endl;

        cout << endl;
        cout<< n << ' ' << m << endl;

        while(m) {
            u = rand() % n;
            v = rand() % n;
            if(!graph[u][v] && u != v) {
                graph[u][v] = graph[v][u] = 1;
                cout << u << ' ' << v << endl;
                m--;
            }
        }
//        cout << "END" << endl;
    }

    return 0;
}
