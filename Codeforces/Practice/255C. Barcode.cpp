#include<bits/stdc++.h>
#define MX 2000000
using namespace std;

int n,m,x,y, black[1010];
char grid[1010][1010];
int dp[1010][1010][2];

int f(int in, int last, int col) {
    if(in == m) {
        if(last >= x) return 0;
        return MX;
    }
//    cout << in << ' ' << last << ' ' << col << endl; getchar();
    if(dp[in][last][col] != -1) return dp[in][last][col];
    int ans = MX;
    if(col == 0) {
        if(last <  y) ans = min(ans, black[in] + f(in+1, last+1, 0));
        if(last >= x) ans = min(ans, n-black[in] + f(in+1, 1, 1) );
    }
    else {
        if(last <  y) ans = min(ans, n-black[in] + f(in+1, last+1, 1));
        if(last >= x) ans = min(ans, black[in] + f(in+1, 1, 0) );
    }
//    cout << "FROM " << in << ' ' << last << ' ' << col << ' ' << ans << endl;
    return dp[in][last][col] = ans;
}

int main() {
    scanf("%d %d %d %d", &n,&m,&x,&y);
    for(int i=0; i<n; i++) scanf("%s", grid[i]);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) if(grid[j][i] == '#') black[i]++;
    }

//    for(int i=0; i<m; i++) cout << black[i] << ' ' ; cout << endl;

    memset(dp, -1, sizeof dp);
    cout << min(f(0, 0, 1), f(0,0,0)) << endl;


}
