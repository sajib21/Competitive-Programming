#include<bits/stdc++.h>

using namespace std;

char str1[65], str2[65];
string a,b;
int dp[63][63][63][63];

int f(int i, int j, int k, int l) {
    if(i > k || j > l) return 0;

    if(dp[i][j][k][l] != -1) return dp[i][j][k][l];

    int ans = 0;
    if(a[i] == b[j] && a[i] == a[k] && b[j] == b[l]) {
        if(i == k || j == l) ans = max(ans, 1 + f(i+1,j+1, k-1, l-1) );
        else ans = max(ans, 2 + f(i+1,j+1, k-1, l-1) );

    }
    ans = max(ans, f(i+1,j,k,l) );
    ans = max(ans, f(i,j+1,k,l) );
    ans = max(ans, f(i,j,k-1,l) );
    ans = max(ans, f(i,j,k,l-1) );
    return dp[i][j][k][l] = ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%s %s", str1, str2);
        a = str1; b = str2;

        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", t, f(0,0,a.size()-1,b.size()-1) );
    }
}
