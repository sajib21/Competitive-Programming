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

info queries[2*LIM+100];
int pt[2*LIM+100];
map<int,int>mp, up;

int n,Q;
int segTree[8*LIM+100];

void update(int node, int st, int ed, int p, int val) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[node] = val;
//        if(segTree[node] < 0) segTree[node] = 0;
        return;
    }
    segVar;
    update(lft, st,md, p, val); update(rgt, md+1,ed, p, val);
    segTree[node] = segTree[lft] + segTree[rgt];
}

int kquery(int node, int st, int ed, int k) {
//    cout << node << ' ' << st << ' ' << ed << ' ' << k << ' ' << segTree[node] << endl; getchar();
    if(segTree[node] < k) return -1;
    if(st == ed) return st;
    segVar;
    if(segTree[lft] >= k) return kquery(lft, st,md, k);
    else return kquery(rgt, md+1,ed, k-segTree[lft]);
}

int cquery(int node, int st, int ed, int l, int r) {
    if(!r) return 0;
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    return cquery(lft, st,md, l,r) + cquery(rgt, md+1,ed, l,r);
}

int main() {

    freopen("Fi.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    n = 0;
    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        getchar();
        char c; int x;
        scanf("%c %d", &c,&x);
        queries[i].x = c;
        queries[i].y = x;
        pt[i] = x;
    }
    sort(pt, pt+Q);
    for(int i=0; i<Q; i++) {
        if(!mp[pt[i] ]) mp[ pt[i] ] = ++n;
        up[ n ] = pt[i];
    }
//    for(int i=0; i<Q; i++) queries[i].y = mp[ queries[i].y ];
//    for(int i=0; i<Q; i++) cout << queries[i].y << ' '; cout << endl;
//    for(int i=0; i<Q; i++) cout << mp[pt[i]] << ' '; cout << endl;

    for(int i=0; i<Q; i++) {
//        cout << "Q " << i << " : " << (char) queries[i].x << ' ' << queries[i].y << endl;
        int p = queries[i].y;
        if(queries[i].x == 'I') update(1, 1,n, mp[p], 1);
        else if(queries[i].x == 'D') update(1, 1,n, mp[p], 0);
        else if(queries[i].x == 'K') {
            int t = kquery(1, 1,n, p);
            if(t == -1) printf("invalid\n");
            else printf("%d\n", up[t] );
        }
        else {
            printf("%d\n", cquery(1, 1,n, 1,mp[p]-1));
        }
    }

    return 0;
}
