#include<bits/stdc++.h>

using namespace std;

int n,m, af[303], al[303], bf[303], bl[303];
char a[5050], b[5050];
int dp[5050][5050];
bool dr[5050][5050];
int MX;

int f(int ai, int bi) {

//    cout << "STATE " << ai << ' ' << a[ai] << ' ' << bi << ' ' << b[bi] << endl; getchar();
//    cout << af[ a[ai] ] << ' ' << al[ a[ai] ]

    if(ai == n && bi == m) return 0;
    if(dr[ai][bi]) {
//        cout << "DP  " << ai << ' ' << bi << ' ' << dp[ai][bi] << endl; getchar();
        return dp[ai][bi];
    }
    int ans = INT_MAX;

    if(ai < n && af[ a[ai] ] == al[ a[ai] ] && bf[ a[ai] ] == MX) ans = min(ans, f(ai+1, bi));
    else {
        if(ai < n) {
            if(af[ a[ai] ] == ai && bf[ a[ai] ] >= bi) ans = min(ans, -(ai+bi+1) + f(ai+1, bi) );
            else if(al[ a[ai] ] == ai && bl[ a[ai] ] < bi) ans = min(ans, +(ai+bi+1) + f(ai+1, bi) );
            else ans = min(ans, f(ai+1, bi));
        }
    }
    if(bi < m && bf[ b[bi] ] == bl[ b[bi] ] && af[ b[bi] ] == MX) ans = min(ans, f(ai, bi+1));
    else {
         if(bi < m) {
            if(bf[ b[bi] ] == bi && af[ b[bi] ] >= ai) ans = min(ans, -(ai+bi+1) + f(ai, bi+1) );
            else if(bl[ b[bi] ] == bi && al[ b[bi] ] < ai) ans = min(ans, +(ai+bi+1) + f(ai, bi+1) );
            else ans = min(ans, f(ai, bi+1));
        }
    }
    dr[ai][bi] = 1;
//    cout << "OUT " << ai << ' ' << bi << ' ' << ans << endl; getchar();
    return dp[ai][bi] = ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%s", a);
        scanf("%s", b);

        n = strlen(a); m = strlen(b);

        memset(af, 127, sizeof af); memset(al, -1, sizeof al);
        memset(bf, 127, sizeof bf); memset(bl, -1, sizeof bl);
        MX = af[0];

        for(int i=n-1; i>=0; i--) af[ a[i] ] = i; for(int i=0; i<n; i++) al[ a[i] ] = i;
        for(int i=m-1; i>=0; i--) bf[ b[i] ] = i; for(int i=0; i<m; i++) bl[ b[i] ] = i;

        memset(dr, 0, sizeof dr);
        printf("%d\n", f(0,0));
    }
    return 0;
}
