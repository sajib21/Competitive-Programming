#include<bits/stdc++.h>
#define ll long long int
#define MAX 500000

using namespace std;

int n, h[55], sum;
int dp[2][MAX+100];
// dr[55][2*MAX+100];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        sum = 0;

        for(int i=1; i<=n; i++) {
            scanf("%d", &h[i]);
            sum += h[i];
        }

        sum /= 2;

        int ans1 = 0;

        for(int in=1; in<=n; in++) {
            for(int mk=0; mk <= sum; mk++) {
                int l=-1,r=-1;
                int tl = h[in] - mk , tr = mk - h[in];

                if(tl >= 0) if(dp[0][tl] != -1) l = dp[0][ tl ] - tl + h[in];
                else if(dp[0][ tr ] != -1) l = dp[0][ tr ] + h[in];
                r = dp[0][ mk + h[in] ];

                if(max( dp[0][mk], max( l,r ) ) >= 0) dp[1][mk] = max( dp[0][mk], max( l,r ) );
            }

            for(int mk=0; mk <= sum; mk++) dp[0][mk] = dp[1][mk];
        }

//        cout << ans1 - MAX << endl;

        if(dp[0][0] == 0) printf("Case %d: impossible\n", t);
        else printf("Case %d: %d\n", t, dp[0][0]);
    }
    return 0;
}
