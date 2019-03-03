///TLE
#include<bits/stdc++.h>

using namespace std;

int n, a[5];
bool dp[303][303][303], dr[303][303][303], dc[303][303][303], dd[303][303][303], dk[303][303][303];

int main() {
//    while(scanf("%d", &n)) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    bool res;

    if(n == 1) {
        if(!a[0]) res = 0;
        else res = 1;
    }
    else if(n == 2) {
        int dp[303][303], dr[303][303], dc[303][303], dk[303][303];
        memset(dp, 0, sizeof dp);
        memset(dk, 0, sizeof dk);
        memset(dr, 0, sizeof dr);
        memset(dc, 0, sizeof dc);

        for(int i=0; i<=a[0]; i++) {
            for(int j=0; j<=a[1]; j++) {
                if(i)       dp[i][j] |= !dr[i-1][j];
                if(j)       dp[i][j] |= !dc[i][j-1];
                if(i && j)  dp[i][j] |= !dk[i-1][j-1];

                if(i)       dr[i][j] = dr[i-1][j] & dp[i][j];
                else        dr[i][j] = dp[i][j];
                if(j)       dc[i][j] = dc[i][j-1] & dp[i][j];
                else        dc[i][j] = dp[i][j];
                if(i && j)  dk[i][j] = dk[i-1][j-1] & dp[i][j];
                else        dk[i][j] = dp[i][j];
            }
        }
        if(dp[ a[0] ][ a[1] ]) res = 1;
        else res = 0;

//        cout << "DP" << endl;
//        for(int i=0; i<=a[0]; i++) {
//            for(int j=0; j<=a[1]; j++) cout << dp[i][j] << ' ';
//            cout << endl;
//        }
    }
    else {
        for(int i=0; i<=a[0]; i++) {
            for(int j=0; j<=a[1]; j++) {
                for(int k=0; k<=a[2]; k++) {
                    if(i)           dp[i][j][k] |= !dr[i-1][j][k];
                    if(j)           dp[i][j][k] |= !dc[i][j-1][k];
                    if(k)           dp[i][j][k] |= !dd[i][j][k-1];
                    if(i && j && k) dp[i][j][k] |= !dk[i-1][j-1][k-1];

                    if(i)           dr[i][j][k] = dr[i-1][j][k] & dp[i][j][k];
                    else            dr[i][j][k] = dp[i][j][k];
                    if(j)           dc[i][j][k] = dc[i][j-1][k] & dp[i][j][k];
                    else            dc[i][j][k] = dp[i][j][k];
                    if(k)           dd[i][j][k] = dd[i][j][k-1] & dp[i][j][k];
                    else            dd[i][j][k] = dp[i][j][k];
                    if(i && j && k) dk[i][j][k] = dk[i-1][j-1][k-1] & dp[i][j][k];
                    else            dk[i][j][k] = dp[i][j][k];

                }
            }
        }
        if(dp[ a[0] ][ a[1] ][ a[2] ]) res = 1;
        else res = 0;
    }


    if(res) printf("BitLGM\n");
    else printf("BitAryo\n");

//    }
}
