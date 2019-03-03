#include<bits/stdc++.h>

using namespace std;

int m,n, grid[103][103];
int dp[103][103][103];

int getMax(int br, int bc, int dis) {

    //cout << br << ' ' << bc << ' ' << dis << endl;
    //getchar();

    if(br == m || bc+dis == n || dis < 0) return 0;
    if(!dis && (br || bc) ) return grid[br][bc];


    if(dp[br][bc][dis] != -1) return dp[br][bc][dis];

    int temp = 0;
    temp = max(temp, getMax(br+1, bc, dis));
    temp = max(temp, getMax(br+1, bc, dis+1));
    temp = max(temp, getMax(br, bc+1, dis));
    temp = max(temp, getMax(br, bc+1, dis-1));


    temp += grid[br][bc] + grid[br-dis][bc+dis];
    return dp[br][bc][dis] = temp;

}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d %d", &m,&n);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        printf("Case %d: %d\n", t, getMax(0,0, 0) - grid[0][0]);
    }

    return 0;
}
