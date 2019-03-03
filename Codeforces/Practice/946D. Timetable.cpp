#include<bits/stdc++.h>

using namespace std;

int n,m,k;
string seq;
int p[505], a[505], b[505][505];
int dp[505][505];

void prep(int in) {
    int c=0;
    memset(b[in], 127, sizeof b[in]);
    for(int i=0; i<m; i++) {
        if(seq[i] == '1') p[c++] = i;
    }
    b[in][0] = 0;
    for(int i=1; i<=a[in]; i++) {
        for(int j=0; j<=a[in]-i; j++) {
            b[in][i] = min(b[in][i], p[j+i-1]-p[j]+1);
        }
    }
}

int f(int in, int rem) {
//    cout << "IN " << in << ' ' << rem << endl; getchar();
    if(rem < 0) return 5000000;
    if(in == n) return 0;
    if(dp[in][rem] != -1) return dp[in][rem];
    if(!a[in]) return dp[in][rem] = f(in+1, rem);
    int ans = INT_MAX;
    for(int i=0; i<=a[in]; i++) {
        ans = min(ans, b[in][i] + f(in+1, rem-(a[in]-i)));
    }
    return dp[in][rem] = ans;
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        cin >> seq;
        for(int j=0; j<m; j++) a[i] += seq[j] == '1';
        if(a[i] == 0) continue;
        prep(i);
    }

//    for(int i=0; i<n; i++) {
//        for(int j=0; j<=a[i]; j++) {
//            cout << i << ' ' << j << " : " << b[i][j] << endl;
//        }
//    }

    memset(dp, -1, sizeof dp);
    cout << f(0, k) << endl;
}
