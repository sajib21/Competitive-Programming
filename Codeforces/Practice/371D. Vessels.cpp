///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             200005
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

int n;
ll ara[LIM], nxt[LIM], val[LIM];

int update(int in, int v) {
    if(in > n) return n+1;
    int cap = ara[in] - val[in];
    if(cap > v) {
        val[in] += v;
        return in;
    }
    else {
        val[in] += cap;
        return nxt[in] = update(nxt[in], v-cap);
    }
    return in;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%I64d", &ara[i]);
    for(int i=1; i<=n; i++) nxt[i] = i+1;

    int q;
    scanf("%d", &q);
    while(q--) {
        int c, x; ll v;
        scanf("%d", &c);
        if(c == 1) {
            scanf("%d %I64d", &x, &v);
            update(x, v);
        }
        else {
            scanf("%d", &x);
            printf("%I64d\n", val[x]);
        }
    }

    return 0;
}
