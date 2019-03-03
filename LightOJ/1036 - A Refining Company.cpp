#include<bits/stdc++.h>

using namespace std;

int m,n, uranium[505][505], radium[505][505];
int dp[505][505];

int getMax(int row, int col) {

    if(!row || !col) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    return dp[row][col] = max( radium[row][col] + getMax(row, col-1), uranium[row][col] + getMax(row-1, col) );
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d %d", &m, &n);
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &uranium[i][j]);
                uranium[i][j] += uranium[i][j-1];
            }
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &radium[i][j]);
                radium[i][j] += radium[i-1][j];
            }
        }
        printf("Case %d: %d\n", t, getMax(m,n) );
    }

    return 0;
}
