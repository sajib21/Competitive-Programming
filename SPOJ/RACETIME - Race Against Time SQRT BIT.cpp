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
    char cmd;
    int x,y,z;
    info() {x = y = z = 0;}
    info(char c, int xx, int yy = 0, int zz = 0) {
        cmd = c; x = xx; y = yy; z = zz;
    }
};

int n,q,v, mxx,seg;
int a[LIM+10], val[2*LIM+10];
info qry[LIM + 10];
map<int, int> mp;
int BIT[400][LIM+100];

void update(int node, int pos, int val) {
    while(node <= seg+1) {
        int tp = pos;
        while(tp <= mxx) {
            BIT[node][tp] += val;
            tp += (tp & -tp);
        }
        node += (node & -node);
    }
}
int query(int node, int pos) {
    int ans = 0;
    while(node > 0) {
        int tp = pos;
        while(tp > 0) {
            ans += BIT[node][tp];
            tp -= (tp & -tp);
        }
        node -= (node & -node);
    }
    return ans;
}

int f(int x, int y, int z) {
    int ans = 0;
    while(x%seg) {
        if(a[x] <= z) ans++;
        x++;
    }
    while(y%seg != seg-1) {
        if(a[x] <= z) ans++;
        y--;
    }

//    cout << "PRE " << ans << endl;

    ans += query(y/seg+1, mp[z]) - (query(x/seg, mp[z]));

    return ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d %d", &n,&q);
    for(int i=0; i<n; i++) scanf("%d", &a[i]) , val[v++] = a[i] ;
    for(int i=0; i<q; i++) {
        char c; int x,y,z;
        getchar();
        scanf("%c", &c);
        if(c == 'M') {
            scanf("%d %d", &x,&y);
            x--;
            val[v++] = y;
            qry[i] = info(c, x, y);
        }
        else {
            scanf("%d %d %d", &x,&y,&z);
            val[v++] = z;
            x--; y--;
            qry[i] = info(c,x,y,z);
        }
    }
    sort(val, val+v);
    for(int i=0; i<v; i++) if(!mp[ val[i] ]) mp[ val[i] ] = ++mxx;

//    cout << mxx << endl;

    seg = sqrt(n);
    for(int i=0; i<n; i++) update(i/seg+1, mp[ a[i] ], 1);

//    for(int i=1; i<=seg; i++) {
//        cout << "INIT" << endl;
//        for(int j=1; j<=mxx; j++) cout << BIT[i][j] << ' ' ;
//        cout << endl;
//    }

    for(int i=0; i<q; i++) {
        char c; int x,y,z;
        c = qry[i].cmd ; x = qry[i].x; y = qry[i].y; z = qry[i].z;
        if(c == 'M') {
            update(x/seg+1, mp[ a[x] ], -1);
            a[x] = y;
            update(x/seg+1, mp[ y ], 1);
        }
        else printf("%d\n", f(x,y,z));
    }

    return 0;
}
