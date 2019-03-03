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

int n;
ll ara[110];
vector< vii > co;

ll gauss() {
    int row = co.size(), col = co[0].size();
    for(int r=0, c=0; c<col-1 && r<row; c++) {
        int cur = r;
        for(int i=r; i<row; i++) if(co[i][c]) {
            cur = i;
            break;
        }
        if(!co[cur][c]) continue;
        if(cur != r) swap(co[cur], co[r]);

        for(int i=0; i<row; i++) if(i != r && co[i][c]) {
            for(int j=c; j<col-1; j++) co[i][j] ^= co[r][j];
        }
        r++;
    }
    ll ans = 0;
    for(int j=0; j<co[0].size()-1; j++) {
        int tmp = 0;
        for(int i=0; i<co.size(); i++) {
            tmp ^= co[i][j];
        }
        ans = 2*ans + tmp;
    }
    return ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        co.clear();
        for(int i=0; i<n; i++) scanf("%lld", &ara[i]);

        for(int i=0; i<n; i++) {
            vii temp(64);
            for(int j=0; j<63; j++) {
                temp[63-j-1] = ara[i] & 1;
                ara[i] >>= 1;
            }
            co.pb(temp);
        }

//        cout << "FINALLY " << endl;
//        for(int i=0; i<co.size(); i++) {
//            for(int j=0; j<co[0].size(); j++) cout << co[i][j] << ' ' ;
//            cout << endl;
//        }

        printf("Case %d: %lld\n", t, gauss());
    }

    return 0;
}
