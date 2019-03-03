#include<bits/stdc++.h>
#define LIM 3003

using namespace std;

int n, a[LIM], b[LIM], c[LIM], dp[LIM][3];

int f(int in, int last) { /// last: 0 = nei nai, 1 = nisi ; cur: 0 = no condition, 1 = nwa jabe na, 2 = nitei hobe
    if(in == n) {
        if(!last)  return a[in];
        return b[in];
        return 0;
    }
    if(dp[in][last] != -1) return dp[in][last];
    int ans = 0;

    if(!last) {
        ans = max( a[in]+f(in+1, 1) , b[in]+f(in+1, 0) );
    }
    else {
        ans = max( b[in]+f(in+1, 1) , c[in]+f(in+1, 0) );
    }

    return dp[in][last] = ans;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) scanf("%d", &b[i]);
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);

    memset(dp, -1, sizeof dp);
    cout << f(1, 0) << endl;
}
