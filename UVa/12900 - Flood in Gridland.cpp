#include<bits/stdc++.h>

using namespace std;

int n,m, mn, mx;
char seq[6] = "-12";
int grid[100][100], fau[110][110];
int dp[80][80][80][80];
int dr[80][80][80][80];

int f(int r, int c, int ru, int cu) {
    if(r == n && c == m) return 0;
    if(dr[r][c][ru][cu]) return dp[r][u][ru][cu];

    int ans = -1000000000;

    ans = max(ans, )

}

int main() {
//    int temp = atoi(seq);
//    printf("%d", temp);



    int T;
    scanf("%d", &T);



    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %d", &n, &m, &mn, &mx);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%s", seq);
                if(seq[0] == 'X') {
                    grid[i][j] = 0;
                    fau[i][j] = 1;
                }
                else {
                    grid[i][j] = atoi(seq);
                    fau[i][j] = 0;
                }
            }
        }


//        memset(dp, -1, sizeof dp);
        memset(dr, 0, sizeof dr);

        int ans = f(0,0,0,0);
    }


}
