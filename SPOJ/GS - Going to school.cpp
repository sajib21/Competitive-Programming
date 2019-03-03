///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     vdd             vector<double>
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

int n,st,ed, graph[110][110], u,v,c;
vector< vdd > co;

double gauss() {
    int row = co.size(), col = co[0].size();
    double ans = 0;
    int r,c;
    for(r=0, c=0; r<row && c<col-1; c++) {
        int cur = r;
        for(int i=cur; i<row; i++) if(abs(co[i][c]) > EPS) {
            cur = i; break;
        }
        if(abs(co[cur][c]) < EPS) continue; ///checking if zero
        if(cur != r) swap(co[r], co[cur]);

//        cout << "PIVOT AT " << r << ' ' << c << ' ' << co[r][c] << endl;
//        for(int i=0; i<col; i++) cout << co[r][i] << ' ' ; cout << endl;

        double div = co[r][c];
        for(int j=0; j<col; j++) co[r][j] /= div;

//        cout << "PIVOT AT " << r << ' ' << c << ' ' << div << endl;
//        for(int i=0; i<col; i++) cout << co[r][i] << ' ' ; cout << endl;

        for(int i=0; i<row; i++) if(i != r) {
            double mul = co[i][c];
            for(int j=0; j<col; j++) co[i][j] -= mul*co[r][j];
        }

//        cout << "AFTER " << r << ' ' << endl;
//        for(int i=0; i<co.size(); i++) {
//            for(int j=0; j<co[0].size(); j++) printf("%8.4lf ", co[i][j]);
//            cout << endl;
//        }


        r++;
    }

//    cout << "FINALLY " << endl;
//    for(int i=0; i<co.size(); i++) {
//        for(int j=0; j<co[0].size(); j++) printf("%8.4lf ", co[i][j]);
//        cout << endl;
//    }

    return co[st][col-1];
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &n, &st,&ed); st--; ed--;
        co.clear();
        memset(graph, 0, sizeof graph);
        for(int i=1; i<n; i++) {
            scanf("%d %d %d", &u,&v,&c); u--; v--;
            graph[u][v] = graph[v][u] = c;
        }
        for(int u=0; u<n; u++) {
            int total = 0;
            for(int v=0; v<n; v++) total += graph[u][v];
            vdd tmp(n+1);
            if(u != ed) {
                for(int v=0; v<n; v++) {
                    if(v == u) tmp[v] = total;
                    else tmp[v] = -graph[u][v];
                }
                tmp[n] = total;
            }
            else tmp[u] = 1;
            co.pb(tmp);
        }

//        for(int i=0; i<co.size(); i++) {
//            for(int j=0; j<co[0].size(); j++) printf("%8.4lf ", co[i][j]);
//            cout << endl;
//        }
        printf("%.5lf\n", gauss());
    }

    return 0;
}
