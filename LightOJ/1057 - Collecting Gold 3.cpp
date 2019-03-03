#include<bits/stdc++.h>

using namespace std;

int m,n, grid[21][21], goldRow[18], goldCol[18], gold, lim;
char cell;
int dp[18][65600];

int setBit(int n, int pos) { return n | (1<<pos); }
int checkBit(int n, int pos) { return n & (1<<pos); }

int getMin(int lastIndex, int mask) {

    if(mask == lim) {
        return max( abs(goldRow[lastIndex] - goldRow[0]) , abs(goldCol[lastIndex] - goldCol[0]) );
    }

    if(dp[lastIndex][mask] != -1) return dp[lastIndex][mask];

    int ans = INT_MAX;
    for(int i=1; i < gold; i++) {
        if(!checkBit(mask, i)) {
            ans = min(ans, max( abs(goldRow[lastIndex] - goldRow[i]) , abs(goldCol[lastIndex] - goldCol[i]) )
            + getMin(i, setBit(mask, i)));
        }
    }

    return dp[lastIndex][mask] = ans;
}

int main() {

    int T;
    scanf("%d", &T);
    //getchar(); //getchar();

    for(int t=1; t<=T; t++) {

        gold = 1;
        memset(dp, -1, sizeof(dp));

        scanf("%d %d", &m, &n);
        getchar();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                scanf("%c", &cell);

                if(cell == 'x') {
                    goldRow[0] = i;
                    goldCol[0] = j;
                    //gold++;
                }
                else if(cell == 'g') {
                    goldRow[gold] = i;
                    goldCol[gold] = j;
                    gold++;
                }
            }
            getchar();
        }

        lim = (1<<gold) - 1;
        printf("Case %d: %d\n", t, getMin(0, 1));
    }

    return 0;
}
