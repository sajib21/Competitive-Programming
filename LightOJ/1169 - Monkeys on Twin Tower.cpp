#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 1000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

int n, tim[2][LIM+10], j[2][LIM+10];
int dp[LIM+10][3];

int f(int flr, int side) {

    if(flr == n) return 0;

    if(dp[flr][side] != -1) return dp[flr][side];

    return dp[flr][side] = tim[side][flr] + min( f(flr+1, side) , j[side][flr]+f(flr+1, !side) );
}

int main() {

//    int x = 0;
//    cout << !(!x) << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &tim[0][i]);
        for(int i=0; i<n; i++) scanf("%d", &tim[1][i]);
        for(int i=0; i<n-1; i++) scanf("%d", &j[0][i]); j[0][n-1] = 0;
        for(int i=0; i<n-1; i++) scanf("%d", &j[1][i]); j[1][n-1] = 0;

//        for(int i=0; i<n; i++) printf("%d ", j[0][i]); printf("\n");
//
//        cout << f(0, 0) << ' ' << f(0, 1) << endl;

        printf("Case %d: %d\n", t, min( f(0, 0) , f(0, 1) ) );
    }

    return 0;
}

