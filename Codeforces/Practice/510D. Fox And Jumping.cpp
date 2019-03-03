#include<bits/stdc++.h>
#define LIM 310
#define INF 1000006

using namespace std;

int n, l[LIM], c[LIM];
unordered_map<int,int>dp[LIM];

int f(int in, int g) {
//    cout << "IN " << in << ' ' << g << ' ' << dp[in][g] << endl; getchar();
    if(g == 1) return 0;
    if(in == n) return INF;
    if(dp[in].find(g) != dp[in].end()) return dp[in][g];
//    cout << "BUG" << endl;

    return dp[in][g] = min( c[in]+f(in+1, __gcd(g, l[in]) ), f(in+1, g) );
}

int main() {
//    cout << dp[0][0] << endl;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &l[i]);
    for(int i=0; i<n; i++) scanf("%d", &c[i]);

    int gg = 0;
    for(int i=0; i<n; i++) gg = __gcd(gg, l[i]);

    if(gg != 1) {
        cout << -1 << endl;
        return 0;
    }

//    memset(dp, -1, sizeof dp);
    int ans = f(0, 0);
    if(ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
}
