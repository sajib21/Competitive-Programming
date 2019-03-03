#include<bits/stdc++.h>

using namespace std;

int n,m;
int dp[15][15];
int digit[15];

int getMax(int dpIndx, int digIndx) {

    if(dpIndx == n ) return 1;

    if(dp[dpIndx][digIndx] != -1) return dp[dpIndx][digIndx];

    int res = 0;
    for(int i=0; i<m; i++) {
        if(abs(digit[digIndx] - digit[i]) < 3) {
            res += getMax(dpIndx+1, i);
        }
    }
    return dp[dpIndx][digIndx] = res;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        //int m,n;
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &m, &n);
        for(int i=0; i<m; i++) scanf("%d", &digit[i]);

        int ans = 0;
        for(int i=0; i<m; i++) {
            ans += getMax(1, i);
        }

        printf("Case %d: %d\n", t, ans);
    }
}
