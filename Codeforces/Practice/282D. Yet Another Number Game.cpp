///TLE
#include<bits/stdc++.h>

using namespace std;

int n, a[5], dp[303][303][303];

int f(int a, int b, int c) {
//    cout << "IN " << a << ' ' << b << ' ' << c << endl;
//    getchar();
    if(dp[a][b][c] != -1) return dp[a][b][c];
    int ans = 0;

    int mn;
    if(n == 1) mn = a;
    if(n == 2) mn = min(a,b);
    if(n == 3) mn = min(a, min(b,c));
    if(mn) {
        if(n == 1) for(int d=1; !ans && d<=mn; d++) ans |= !f(a-d, b, c);
        if(n == 2) for(int d=1; !ans && d<=mn; d++) ans |= !f(a-d, b-d, c);
        if(n == 3) for(int d=1; !ans && d<=mn; d++) ans |= !f(a-d, b-d, c-d);
    }

    for(int d=1; !ans && d<=a; d++) ans |= !f(a-d, b, c);
    for(int d=1; !ans && d<=b; d++) ans |= !f(a, b-d, c);
    for(int d=1; !ans && d<=c; d++) ans |= !f(a, b, c-d);

//    cout << "OUT " << a << ' ' << b << ' ' << c << ' ' << ans << endl;
//    getchar();
    return dp[a][b][c] = ans;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);

    bool res;
    if(n == 1) res = f(a[0], 0, 0);
    if(n == 2) res = f(a[0], a[1], 0);
    if(n == 3) res = f(a[0], a[1], a[2]);

//    for(int i=0; i<=a[0]; i++) {
//        for(int j=0; j<=a[1]; j++) cout << dp[i][j][0] << ' ';
//        cout << endl;
//    }

    if(res) printf("BitLGM\n");
    else printf("BitAryo\n");
}
