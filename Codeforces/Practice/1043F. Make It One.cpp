#include<bits/stdc++.h>
#define LIM 300005
#define INF 1000006

using namespace std;

int n, a[LIM];
int dp[LIM][20];

int f(int in, int cur) {
//    cout << "IN " << in << ' ' << g << ' ' << dp[in][g] << endl; getchar();
    if(in == n || cur == 0) return 0;
    if(dp[in][cur] != -1) return dp[in][cur];

    int ans = INT_MAX;
    int temp;

    temp = f(in+1, cur);
    if(temp) ans = min(ans, temp);

    temp = __gcd(a[in], f(in+1, cur-1));
    if(temp) ans = min(ans, temp);

    return dp[in][cur] = ans;

}

int main() {
//    cout << dp[0][0] << endl;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    int gg = 0;
    for(int i=0; i<n; i++) gg = __gcd(gg, a[i]);
    if(gg != 1) {
        cout << -1 << endl;
        return 0;
    }

    memset(dp, -1, sizeof dp);

    f(0, 10);

    int ans = INT_MAX;

    for(int j=1; j<=10; j++) {
        if(f(0, j) == 1) ans = min(ans, j);
    }


//    for(int i=0; i<=n; i++) {
//        for(int j=0; j<=10; j++) {
//            cout << dp[i][j] << ' ';
//        }
//        cout << endl;
//    }

    cout << ans << endl;
}
