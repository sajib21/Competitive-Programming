#include<bits/stdc++.h>
#define ll long long int
#define LIM 100000

///NEVER MEMSET 1 FOR LONG LONG INT, NO PROBLEM FOR -1

using namespace std;

int n, m, d;
ll ara[LIM+10];
ll cnt, dp[LIM+10];

int main() {

    int T, lines = 0;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&d);
        ara[0] = 0;
        for(int i=1; i<=n; i++) {
            ll x;
            scanf("%lld", &x);
            ara[i] = ara[i-1] + x;
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cnt = 0;
        for(int i=1; i<=n; i++) {
            if(dp[ ara[i]%d ]) cnt += dp[ ara[i]%d ];
            dp[ ara[i]%d ]++;
        }
        printf("Case %d: %lld\n", t, cnt);
    }
    return 0;
}
