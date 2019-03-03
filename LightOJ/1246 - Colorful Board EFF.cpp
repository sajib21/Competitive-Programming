#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007LL
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int n,m,k, b,w;
ll dp[203][52];
ll comb[203][203];

ll getCnt(int remW, int remC) {
    if(remW < remC || remW == 0 || remC == 0) return 0;
    if(remC == 1) return 1;
    if(dp[remW][remC] != -1) return dp[remW][remC];

    ll ans = 0;
    for(int take=1; take<=remW; take++) {
        ans = (ans + comb[remW][take]*getCnt(remW-take, remC-1)%MOD) % MOD;
    }

    return dp[remW][remC] = ans;
}

int main() {

//    freopen("1246 in.txt", "r", stdin);
//    freopen("1246 out.txt", "w", stdout);

    memset(dp, -1, sizeof(dp));

    comb[0][0] = 1;
    for(int i=1; i<=200; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j=1; j<i; j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    }

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &n,&m,&k);
        int all = (n+1)*(m+1);
        b = (all+1) / 2;
        w = (all) / 2;
        ll ans = 0;

        if(b+w==1) {
            printf("Case %d: %d\n", t, k);
            continue;
        }

        for(int c1=1; c1<=k; c1++) {
            for(int c2=1; c2<=k-c1; c2++) {
                ans = (ans + (comb[k][c1]*getCnt(w,c1)%MOD) * (comb[k-c1][c2]*getCnt(b,c2)%MOD) % MOD) % MOD;
            }
        }

        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
