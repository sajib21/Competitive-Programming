#include<bits/stdc++.h>

using namespace std;

int n,m, k;
string a,b;
int dp[1010][1010][12][3];

int f(int i, int j, int k, int c) {
    if(i == n || j == m || k < 0) {
        if(k == 0) return 0;
        return INT_MIN;
    }
    if(dp[i][j][k][c] != -1) return dp[i][j][k][c];

    int ans = INT_MIN;

    if(c == 0) {
        if(a[i] == b[j]) ans = max(ans, 1+f(i+1,j+1, k-1, 1) );
        ans = max(ans, f(i+1,j, k, 0) );
        ans = max(ans, f(i,j+1, k, 0) );
    }
    else {
        if(a[i] == b[j]) {
            ans = max(ans, 1+f(i+1,j+1, k  , 1) ); ///ager string ei
            ans = max(ans, 1+f(i+1,j+1, k-1, 1) ); ///notun string
        }
        ans = max(ans, f(i+1,j, k, 0) );
        ans = max(ans, f(i,j+1, k, 0) );
    }
    return dp[i][j][k][c] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &n,&m, &k);
    cin >> a >> b;
    cout << f(0, 0, k, 0) << endl;
}
