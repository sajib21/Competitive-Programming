#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define ll long long int
#define MOD 1000000007
#define LIM 505

using namespace std;

int n,m;
char grid[LIM][LIM];
vector< vector< vi> > dp;

int f(int i, int j, int k) {
    int l = m-1 - (i+j - (n-1-k) );

//    cout << "IN " << i << ' ' << j << ' ' << k << ' ' << l << endl; getchar();

    if(i == k && j == l) return 1;
    if(abs(i-k)+abs(j-l) == 1) return 1;
    if(i > k || j > l) return 0;

    if(dp[i][j][k] != -1) return dp[i][j][k];

    ll ans = 0;
    if(grid[i+1][j] == grid[k-1][l]) ans += f(i+1,j, k-1);
    if(grid[i+1][j] == grid[k][l-1]) ans += f(i+1,j, k);
    if(grid[i][j+1] == grid[k-1][l]) ans += f(i,j+1, k-1);
    if(grid[i][j+1] == grid[k][l-1]) ans += f(i,j+1, k);

//    cout << "OUT " << i << ' ' << j << ' ' << k << ' ' << l << ' ' << ans << endl;
//    getchar();

    return dp[i][j][k] = (int) (ans % MOD);
}

int main() {

    vector< vi > a;
    vi b;
    for(int i=0; i<LIM; i++) b.pb(-1);

    for(int i=0; i<LIM; i++) a.pb(b);

    for(int i=0; i<LIM; i++) {
        dp.pb(a);
        a.pop_back();
    }

//    for(int i=0; i<LIM; i++) {
//        vector< vi > a;
//        for(int j=0; j<LIM-i; j++) {
//            vi b;
//            for(int k=0; k<LIM; k++) {
//                b.pb(-1);
//            }
//            a.pb(b);
//        }
//        dp.pb(a);
//    }

    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) scanf("%s", grid[i]);

    if(grid[0][0] != grid[n-1][m-1]) cout << 0 << endl;
    else cout << f(0,0, n-1) << endl;
}
