#include<bits/stdc++.h>
#define WHITE 0
#define BLACK 1
#define IM 1000000

#define ll long long int

using namespace std;

int n,m,x,y;
int grid[1010][1010];
int white[1010];

ll dp[1010][3];

ll getMin(int col, int lastColor) {

    if(col > m) return IM;
    if(col == m) return 0;

    if(dp[col][lastColor] != -1) return dp[col][lastColor];

    //int w = 0;
    //for(int i=)
    ll temp = IM;
    for(int i=x; i<=y; i++) {

        int w = 0;
        for(int p=col, q=0; q<i; q++, p++ ) {
            w += white[p];
        }

        if(lastColor != WHITE) {
            temp = min(temp, w + getMin(col+i, WHITE) );
        }
        else {
            temp = min(temp, n*i - w + getMin(col+i, BLACK));
        }
    }

    return dp[col][lastColor] = temp;
}

int main() {

    memset(dp, -1, sizeof(dp));

    scanf("%d %d %d %d", &n, &m, &x,&y);
    getchar();
    char c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%c", &c);
            if(c == '.') {
                grid[i][j] = WHITE;
                white[j]++;
            }
//            else grid[i][j] =
        }
        getchar();
    }

//    for(int i=0; i<m; i++) cout << white[i] << ' ';
//    cout << endl;

    cout <<  min( getMin(0, 1), getMin(0,0) ) << endl;

    return 0;

}
