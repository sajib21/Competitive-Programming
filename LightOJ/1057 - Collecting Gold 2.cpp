#include<bits/stdc++.h>

using namespace std;

int n,m;
char grid[22][22];
int xRow, xCol;
int gold;

int dirR[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dirC[] = {-1, 0, +1, -1, +1, -1, 0, +1};

int colorMask, color[22][22];
//int dp[19][19][2000];
int dp[19][19][400][20];
int ans;

int getMin(int uR, int uC, int colorMask, int mov, int goldCount) {

    if(goldCount == gold) {
//        cout << mov << ' ' << max( abs(uR - xRow) , abs(uC - xCol) ) << endl;
        ans = min(ans, mov + max(abs(uR - xRow), abs(uC - xCol)));
        return mov + max(abs(uR - xRow), abs(uC - xCol));
    }

    //if(dp[uR][uC][colorMask] != -1) return dp[uR][uC][colorMask];
    if(dp[uR][uC][mov][goldCount] != -1) return dp[uR][uC][mov][goldCount];
    color[uR][uC] = 1;

    int ans = INT_MAX;
    for(int i=0; i<8; i++) { ///8 places in directional array
        int newR = uR+dirR[i], newC = uC+dirC[i];
        if(newR >= 0 && newR < n && newC >= 0 && newC < m) {
            if(color[newR][newC] == 0) {
                color[newR][newC] = 1;
                if(grid[newR][newC] == '.') {
                    ans = min(ans, getMin(newR, newC, colorMask , mov+1, goldCount) );
                }
                else{
                    ans = min(ans, getMin(newR, newC, colorMask | ( 1 << grid[newR][newC] ), mov+1, goldCount+1));
                }

                color[newR][newC] = 0;
                //int newColor[22][22]; for(int p=0; p<n; p++) for(int q=0; q<m; q++) newColor[p][q] = color[p][q];
//                cout << "ager ans " << ans << " call jay " << newR << ' ' << newC << " GOLD " << endl;
//
//                cout << "ekhn ans " << ans << " ferot ay " << newR << ' ' << newC << " GOLD " << endl;
            }
        }
    }
//    cout << uR << ' ' << uC << " cell e ans " << ans << endl;
////    return dp[uR][uC][colorMask] = ans;
    return dp[uR][uC][mov][goldCount] = ans;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        gold = 0;
        ans = INT_MAX;
        memset(dp, -1, sizeof(dp));

        scanf("%d %d",&n, &m);
        int goldIndx=0;
        for(int i=0; i<n; i++) {
            getchar();
            for(int j=0; j<m; j++) {
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == 'x') xRow = i, xCol = j, grid[i][j] = '.';
                else if(grid[i][j] == 'g') grid[i][j] = goldIndx++, gold++;
            }
        }

        int color[22][22]; memset(color, 0, sizeof(color));

        ans = min(ans,getMin(xRow, xCol, 0, 0, 0));
        printf("Case %d: %d\n", t, ans);
        //getMin(xRow, xCol,);
    }
}
