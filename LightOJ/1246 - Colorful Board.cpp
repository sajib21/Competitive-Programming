#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
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
ll dp[203][203][52];
ll comb[203][203];

ll getCnt(int remW, int remB, int remC) {
    if(remW + remB == 0) return 1;
    if(!remC) return 0;
    if(dp[remW][remB][remC] != -1) return dp[remW][remB][remC];

    ll ans = 0;
    for(int i=1; i<=remW; i++) ans = (ans + (comb[remW][i]*getCnt(remW-i, remB, remC-1)) % MOD ) % MOD;
    for(int i=1; i<=remB; i++) ans = (ans + (comb[remB][i]*getCnt(remW, remB-i, remC-1)) % MOD ) % MOD;
    ans = (ans + getCnt(remW, remB, remC-1)) % MOD;

    return dp[remW][remB][remC] = ans;
}

int main() {
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
        w = (all-1) / 2;
        printf("Case %d: %lld\n", t, getCnt(w,b,k));
    }
    return 0;
}
