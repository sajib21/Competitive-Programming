///DP Trick:  knuth's optimization
/// Problem: breaking strings at different points in min cost
#include<bits/stdc++.h>
#define LIM 1010
#define ll long long int

using namespace std;

int n,m, b[LIM];
ll dp[LIM][LIM], A[LIM][LIM];

int cost(int i, int j) {
    return b[j+1]-b[i-1];
}

ll f(int i, int j) {
    if(j < i) return 0;
    if(i == j) {
        A[i][j] = i;
        return dp[i][j] = cost(i,j);
    }
    if(dp[i][j] != -1) return dp[i][j];

    f(i, j-1);
    f(i+1,j);
    int l = A[i][j-1], r = A[i+1][j];

    ll ans = 10000000000000000LL;
    for(int k=l; k<=r; k++) {
        int temp = f(i,k-1)+f(k+1,j) + cost(i,j);
        if(temp < ans) {
            ans = temp;
            A[i][j] = k;
        }
    }
    return dp[i][j] = ans;
}

void g(int i, int j) {
    if(j < i) return;
    if(i == j) {
        cout << i << ' ';
        return;
    }
    int a = A[i][j];
    cout << a << ' ';
    g(i, a-1);
    g(a+1,j);
}

int main() {
    while(scanf("%d %d", &n,&m) != EOF) {
        for(int i=1; i<=m; i++) scanf("%d", &b[i]);
        b[m+1] = n;
        memset(dp, -1, sizeof dp);
        printf("%lld\n", f(1,m) );
        g(1,m);
        cout << endl;
    }
}
