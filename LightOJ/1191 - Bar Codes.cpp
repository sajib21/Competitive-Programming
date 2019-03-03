#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

int n,k,m;
ll dp[55][55][55];

ll bc(int barLeft, int sumLeft, int w) {

    if(barLeft == 0) {
        if(sumLeft==0) return 1;
        else return 0;
    }
    if(sumLeft == 0) 0;

    if(dp[barLeft][sumLeft][w] != -1) return dp[barLeft][sumLeft][w];

    ll ans = 0;
    for(int i=1; i<=min(m,sumLeft); i++) {
        ans += bc(barLeft-1, sumLeft-i, w);
    }
    return dp[barLeft][sumLeft][w] = ans;
}

int main() {

    memset(dp, -1, sizeof(dp));

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d %d", &n,&k,&m);
        printf("Case %d: %lld\n",t, bc(k, n, m) );
    }
    return 0;

}

