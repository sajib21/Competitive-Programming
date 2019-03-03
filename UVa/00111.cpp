#include<bits/stdc++.h>

using namespace std;

int t1[22], t2[22];
int dp[23][23];
int n;

int main() {

    int t=1, x;
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        t1[x] = i;
    }

    while(scanf("%d", &x) != EOF) {

        t2[x] = 1;

        memset(dp, 0, sizeof(dp));

        for(int i=2; i<=n; i++) {
            scanf("%d", &x);
            t2[x] = i;
        }

        for(int j=1; j<=n; j++) {
            for(int i=1; i<=n; i++) {

                if(t1[i] == t2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        printf("%d\n", dp[n][n]);
        //printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", t++, maxLcs(0,0));
    }

    return 0;


}
