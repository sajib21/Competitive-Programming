#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

char cmd[20];
int n,m, c[110], csum[110];
pii a[110];
int dp[110][110][3];

int f(int i, int j, int con) {
    if(i < 0) {
        if(con == 1) return 0;
        return csum[j];
    }
    if(dp[i][j][con] != -1) return dp[i][j][con];
    int ans = 0;
    if(a[i].ss == 0) { ///attack
        if(a[i].ff <= c[j]) ans = max(ans, (c[j]-a[i].ff) + f(i-1,j-1, con) );
        ans = max(ans, f(i-1,j, 1) );
    }
    else {
        if(a[i].ff < c[j]) ans = max(ans, f(i-1,j-1, con) );
        ans = max(ans, f(i-1,j, 1) );
    }
    return dp[i][j][con] = ans;
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s %d", &cmd, &a[i].ff);
        if(cmd[0] == 'A') a[i].ss = 0;
        else a[i].ss = 1;
    }
    sort(a, a+n);

    for(int i=0; i<m; i++) scanf("%d", &c[i]);
    sort(c, c+m);
    csum[0] = c[0];
    for(int i=1; i<m; i++) csum[i] = csum[i-1] + c[i];

    memset(dp, -1, sizeof dp);
    printf("%d\n", f(n-1,m-1, 0));
}
