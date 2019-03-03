///NOW THIS IS SOMETHING VERY INTERESTING I'VE LEARNED TODAY : RECURSION OF TWO FUNCTIONS WHO CALLS EACH OTHER.
///I WAS THINKING ABOUT STUFF LIKE THIS SINCE I WAS A NOOB BUT NEVER HAD THE GUTS TO TRY IT OUT.
///HOWEVER, FOUND THIS PROBLEM AND SAW ON THE INTERNET THAT PEOPLE ARE USING THIS TECHNIQUE.

///THE RECURSION INSIDE THE DP IS LIKE I SAID BEFORE. THERE ARE TWO FUNCTIONS WHO ARE CALLING EACH OTHER.

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


int n,m;
char grid[110][110];
ull dp[110][(1 << 8) + 10];

ull getCnt(int r, int mask);
ull backTrack(int curMask, int nxtMask, int r, int c);

ull backTrack(int curMask, int nxtMask, int r, int c) {
    if(c == m) return getCnt(r+1, nxtMask); /// here is the beauty! :')
    if(c > m) return 0;
    if(grid[r][c] == '#' || chkBit(curMask, c)) return backTrack(setBit(curMask, c) , nxtMask, r, c+1);

    ull ans = 0;
    int cnt = 0;

    ///trying with tile 1
    if(r < n-1 && grid[r+1][c] != '#' && !chkBit(nxtMask, c)) ans += backTrack(setBit(curMask, c) , setBit(nxtMask, c), r, c+1);

    ///trying with tile 2
    if(c < m-1 && grid[r][c+1] != '#' && !chkBit(curMask, c+1)) ans += backTrack( setBit( setBit(curMask, c), c+1 ) , nxtMask, r, c+2 ); /// going outside grid case in handled in base case.

    ///trying with tile 3
    if(r < n-1 &&  c < m-1 && grid[r+1][c] != '#' && grid[r+1][c+1] != '#' && !chkBit(nxtMask, c) ) ans += backTrack( setBit(curMask, c), setBit( setBit(nxtMask, c), c+1 ) , r, c+1 );

    ///trying with tile 4
    if(r < n-1 && c < m-1 && grid[r][c+1] != '#' && grid[r+1][c] != '#' && !chkBit(nxtMask, c) && !chkBit(curMask, c+1) ) ans += backTrack( setBit( setBit(curMask, c), c+1 ) , setBit(nxtMask, c) , r, c+2 );

    ///trying with tile 5
    if(r < n-1 && c > 0 && grid[r+1][c-1] != '#' && grid[r+1][c] != '#' && !chkBit(nxtMask, c-1) && !chkBit(nxtMask, c)) ans += backTrack( setBit(curMask, c), setBit( setBit(nxtMask, c-1) , c ), r, c+1);

    ///trying with tile 6
    if(r < n-1 && c < m-1 && grid[r][c+1] != '#' && grid[r+1][c+1] != '#' && !chkBit(nxtMask, c+1) && !chkBit(curMask, c+1) ) ans += backTrack(setBit( setBit(curMask, c), c+1 ), setBit(nxtMask, c+1), r, c+2);

    return ans;
}

ull getCnt(int r, int mask) {
    if(r == n) return mask == 0;
    if(dp[r][mask] != -1) return dp[r][mask];

    return dp[r][mask] = backTrack(mask, 0, r, 0);
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

        printf("Case %d: %llu\n", t, getCnt(0,0));
    }

    return 0;
}

