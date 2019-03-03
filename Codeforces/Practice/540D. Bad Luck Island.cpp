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

using namespace std;

int r,s,p;
double dpr[110][110][110];
bool pr[110][110][110];

double f(int rr, int rs, int rp) {
    if(!rr) return 0;
    if(!rp) return 1;
    if(pr[rr][rs][rp]) return dpr[rr][rs][rp];
    pr[rr][rs][rp] = 1;
    int all = rr+rs+rp;
    double ans = 0;

    if(rr && rs) ans += 2.0 * rr/all * rs/(all-1) * f(rr, rs-1, rp);
    if(rr && rp) ans += 2.0 * rr/all * rp/(all-1) * f(rr-1, rs, rp);
    if(rs && rp) ans += 2.0 * rs/all * rp/(all-1) * f(rr, rs, rp-1);

    double co = 0;
    if(rr > 1) co += 1.0* rr/all * (rr-1)/(all-1);
    if(rs > 1) co += 1.0* rs/all * (rs-1)/(all-1);
    if(rp > 1) co += 1.0* rp/all * (rp-1)/(all-1);
    co = 1.0 - co;
    ans /= co;
    return dpr[rr][rs][rp] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    memset(pr, 0, sizeof pr);
//    memset(ps, 0, sizeof ps);
//    memset(pp, 0, sizeof pp);

    scanf("%d %d %d", &r,&s,&p);

//    printf("%.10lf\n", f(s,p,r) );
    printf("%.10lf %.10lf %.10lf\n", f(r,s,p), f(s,p,r), f(p,r,s) );

    return 0;
}
