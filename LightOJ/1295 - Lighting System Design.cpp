#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
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

struct info{
    int v,k,c,l;
    info() {}
    info(int vv, int kk, int cc, int lll) {
        v = vv; k = kk; c = cc; l = lll;
    }
};
bool cmp (info x, info y) {
    return x.v < y.v;
}

int n;
info sob[LIM+10];
int cum[LIM+10], dp[1003][1003];

int getMin(int in, int pre) {
    if(pre == n) return 0;
    if(in  > n) return MAX;
    if(dp[in][pre] != -1) return dp[in][pre];
    return dp[in][pre] = min( (cum[in]-cum[pre])*sob[in].c + sob[in].k + getMin(in+1, in) , getMin(in+1, pre) );
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d %d %d %d", &sob[i].v, &sob[i].k, &sob[i].c, &sob[i].l );
        sort(sob+1, sob+n+1, cmp);
        for(int i=1; i<=n; i++) cum[i] = cum[i-1] + sob[i].l;
//        for(int i=1; i<=n; i++) cout << cum[i] << ' ' ; cout << endl;
        printf("Case %d: %d\n", t, getMin(1, 0));
    }

    return 0;
}

