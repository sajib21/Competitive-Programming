#include<bits/stdc++.h>
#define LIM 5003
#define ll long long int
#define MIN -1000000000000000LL

using namespace std;

int n,sz,x, a[LIM];
ll dp[LIM][LIM];

int main() {
    scanf("%d %d %d", &n, &sz, &x);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    for(int i=0; i<=5000; i++) {
        for(int j=0; j<=5000; j++) dp[i][j] = MIN;
    }
    dp[0][0] = 0;


    for(int i=1; i<=sz; i++) {
        dp[1][i] = a[i];
    }

    for(int k=2; k<=x; k++) {
//        for(int i=1; i<k; i++) cout << -1 << ' ';
        for(int i=k; i<=n; i++) {
            for(int j=max(0,i-sz); j<i; j++) {
                dp[k][i] = max(dp[k][i], a[i]+dp[k-1][j]);
            }
//            cout << dp[k][i] << ' ';
        }
//        cout << endl;
    }

    ll ans = MIN;
    for(int i=n-sz+1; i<=n; i++) ans = max(ans, dp[x][i]);

    if(ans < 0) cout << -1 << endl;
    else cout << ans << endl;

}

/*

8 3 3
10 2 3 10 6 13 15 8

*/
