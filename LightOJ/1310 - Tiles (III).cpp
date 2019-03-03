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

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

int getCnt(int row, int curMask, int nxtMask);
int backTrack(int cur, int nxt, int lat, int r, int c);

int n,m;
char grid[103][103];
int dp[103][1 << 8][1 << 8];

bool chk1(int r, int c, int cur, int nxt) {
    if( chkBit(cur, c) || chkBit(cur, c+1) || chkBit(cur, c+2) || chkBit(nxt, c) || chkBit(nxt, c+1) || chkBit(nxt, c+2) ) return false;
    if(grid[r][c] == '#' || grid[r][c+1] == '#' || grid[r][c+2] == '#' || grid[r+1][c] == '#' || grid[r+1][c+1] == '#' || grid[r+1][c+2] == '#' ) return false;
    return true;
}
bool chk2(int r, int c, int cur, int nxt, int lat) {
    if( chkBit(cur, c) || chkBit(cur, c+1) || chkBit(nxt, c) || chkBit(nxt, c+1) || chkBit(lat, c) || chkBit(lat, c+1) ) return false;
    if(grid[r][c] == '#' || grid[r][c+1] == '#' || grid[r+1][c] == '#' || grid[r+1][c+1] == '#' || grid[r+2][c] == '#' || grid[r+2][c+1] == '#' ) return false;
    return true;
}

int backTrack(int cur, int nxt, int lat, int r, int c) {
//    cout << "IN " << cur << ' ' << nxt << ' ' << lat << ' ' << r << ' ' << c << endl;
    if(c == m) return getCnt(r+1, nxt, lat);
    int ans = 0;

    if(c+3 <= m && r+2 <= n && chk1(r,c, cur,nxt)) {
//        cout << "CALLING 1" << endl;
        ans = max(ans, 1 + backTrack( setBit( setBit( setBit(cur, c), c+1 ), c+2 ) , setBit( setBit( setBit(nxt, c), c+1 ), c+2 ) , lat, r, c+3 ) );
//        if(!r && !c) cout << "OUT " << cur << ' ' << nxt << ' ' << lat << ' ' << r << ' ' << c << ' ' << ans << endl;
    }

    if(c+2 <= m && r+3 <= n && chk2(r,c, cur, nxt, lat)) {
//        cout << "CALLING 2" << endl;
        ans = max(ans, 1 + backTrack( setBit( setBit(cur, c), c+1 ), setBit( setBit(nxt, c), c+1 ), setBit( setBit(lat, c), c+1), r, c+2 ) );
//        if(!r && !c) cout << "OUT " << cur << ' ' << nxt << ' ' << lat << ' ' << r << ' ' << c << ' ' << ans << endl;
    }

//    cout << "CALLING 3" << endl;
    ans = max(ans, backTrack(setBit(cur, c), nxt, lat, r, c+1));
//    if(!r && !c) cout << "OUT " << cur << ' ' << nxt << ' ' << lat << ' ' << r << ' ' << c << ' ' << ans << endl;
    return ans;
}

int getCnt(int row, int curMask, int nxtMask) {

    if(row == n) {
//        cout << "DP " << row << ' ' << curMask << ' ' << nxtMask ;
        if(!curMask && !nxtMask) {
//            cout << " RETURNING 0" << endl;
            return 0;
        }
//        cout << " RETURNING MIN" << endl;
        return INT_MIN;
    }
    if(row > n) return INT_MIN;

    if(dp[row][curMask][nxtMask] != -1) return dp[row][curMask][nxtMask];

    return dp[row][curMask][nxtMask] = backTrack(curMask, nxtMask, 0, row, 0);
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++) scanf("%s", grid[i]);
        if(n < m) {
            for(int i=0; i<=max(n,m); i++) for(int j=i; j<=max(n,m); j++) {
                swap(grid[i][j], grid[j][i]);
            }
            swap(n,m);
        }

//        for(int i=0; i<n; i++) printf("%s\n", grid[i]);

        printf("Case %d: %d\n", t, getCnt(0,0,0));
    }

    return 0;
}

