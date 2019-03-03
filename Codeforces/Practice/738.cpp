#include<bits/stdc++.h>

using namespace std;
int n,m, grid[1010][1010], sums[1010][1010], sumCol[1010][1010];
int main() {


    memset(grid, 0, sizeof(grid));
    memset(sums, 0, sizeof(sums));
    memset(sumCol, 0, sizeof(sumCol)); //cout << "bug" << endl;
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &grid[i][j]);
            sums[i][j] = sums[i][j-1] + grid[i][j];
            sumCol[i][j] = sumCol[i-1][j] + grid[i][j];
        }
    }
//    for(int i=1; i<= n; i++) {
//        for(int j=1; j<=m; j++) {
//            cout << sumCol[i][j] << ' ';
//        }
//        cout << endl;
//    }

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(!grid[i][j]) {
                if(sums[i][j-1]) cnt++;
                if(sums[i][j] < sums[i][m]) cnt++;
                if(sumCol[i-1][j]) cnt++;
                if(sumCol[i][j] < sumCol[n][j]) cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
