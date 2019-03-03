#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int row,col, target;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) {
    if(pos < 0 || pos == col) return mask;
    return mask ^ (1 << pos) ;
}
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }
void printBin(int n) {

    if(!n) return;
    printBin(n>>1);
    cout << n%2;
}


char grid[9][9];
int gridMask[9];
int dp[1 << 8][1 << 8][9];

int getMin(int preMask, int curMask, int r) ;
int backTrack(int preMask, int curMask, int nxtMask, int r, int c) ;

int backTrack(int preMask, int curMask, int nxtMask, int r, int c) {
//        printBin(preMask); cout << endl;
//        printBin(curMask); cout << endl;
//        printBin(nxtMask); cout << endl;
//        getchar();

//    if(curMask == 17 && preMask == target && r == 1) {
//        printBin(preMask); cout << endl;
//        printBin(curMask); cout << endl;
//    }
    if(c == col) {
        if(r == 0 || preMask == target) return getMin(curMask, nxtMask, r+1);
        else return MAX;
    }
    int ans = MAX;
    int pre, cur, nxt;

    if(r == 0 || c == 0) {
        pre =        togBit( togBit( togBit( preMask, c-1 ) , c ) , c+1 ); ///overflow handled in togBit() function
        cur =        togBit( togBit( togBit( curMask, c-1 ) , c ) , c+1 );
        nxt =        togBit( togBit( togBit( nxtMask, c-1 ) , c ) , c+1 );
//        printBin(pre); cout << endl;
//        printBin(cur); cout << endl;
//        printBin(nxt); cout << endl;
        int temp;
        ans = min(ans, temp = 1 + backTrack( pre, cur, nxt, r, c+1 ) );
//        if(r == 1 && c == 0) cout << temp << endl;
        ans = min(ans, temp = backTrack(preMask, curMask, nxtMask, r, c+1));
//        if(r == 1 && c == 0) cout << temp << endl;
    }

    ///toggle
    else if( (r == 0 || c == 0) || !chkBit(preMask, c-1) ) {
        pre =        togBit( togBit( togBit( preMask, c-1 ) , c ) , c+1 ); ///overflow handled in togBit() function
        cur =        togBit( togBit( togBit( curMask, c-1 ) , c ) , c+1 );
        nxt =        togBit( togBit( togBit( nxtMask, c-1 ) , c ) , c+1 );
//        printBin(pre); cout << endl;
//        printBin(cur); cout << endl;
//        printBin(nxt); cout << endl;
        ans = min(ans, 1 + backTrack( pre, cur, nxt, r, c+1 ) );
    }
    ///dont toggle
    else ans = min(ans, backTrack(preMask, curMask, nxtMask, r, c+1));

    return ans;
}

int getMin(int preMask, int curMask, int r) {
    if(r == row) {
        if(preMask == target) return 0;
        else return MAX;
    }
    if(dp[preMask][curMask][r] != -1) return dp[preMask][curMask][r];

    return dp[preMask][curMask][r] = backTrack(preMask, curMask, gridMask[r+1], r, 0);
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &row, &col);
        for(int i=0; i<row; i++) scanf("%s", grid[i]);

        if(row < col) { ///MAKING SURE ROW > COL
            for(int i=0; i<=max(row,col); i++) for(int j=i; j<=max(row,col); j++) {
                swap(grid[i][j], grid[j][i]);
            }
            swap(row,col);
        }

        memset(gridMask, 0, sizeof(0));
        for(int r=0; r<row; r++) {
            int tempMask = 0;
            for(int c=0; c<col; c++) {
                if(grid[r][c] == '*') tempMask = setBit(tempMask, c);
            }
            gridMask[r] = tempMask;
        }
//        cout << "MASK" << endl;
//        for(int i=0; i<row; i++) printBin(gridMask[i]) , cout << endl;
//        getchar(); getchar();


        target = (1 << col) - 1;
        memset(dp, -1, sizeof(dp));
        int ans = getMin(0, gridMask[0] , 0);
        if(ans != MAX) printf("Case %d: %d\n", t, ans);
        else printf("Case %d: impossible\n", t);
    }

    return 0;
}
