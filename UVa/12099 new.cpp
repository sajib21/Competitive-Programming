#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define MX 10000000
#define pii pair<int,int>
#define pxi pair<pii,pii>

using namespace std;

int t,n, fl;
pii book[100];
int dp[71][2101][2101][3];

pxi dp;

int f(int in, int a, int b, int c) {
    if(in < 0) {
        if(a == 0 && b == 0 && c == 0) return 0;
        return MX;
    }
    if(dp[in][a][b][c] != -1) return dp[in][a][b][c];

    int ans = MX;
    ans = min(ans, f(in-1, a,b,c));

    if(c == 2) {
        if(book[in].ss <= a) ans = min(ans, book[in].ff + f(in-1, a-book[in].ss, b, c-1) );
    }
    else if(c == 1) {
        if(book[in].ss <= a) ans = min(ans, f(in-1, a-book[in].ss, b, c));
        if(book[in].ss <= b) ans = min(ans, book[in].ff + f(in-1, a, b-book[in].ss, c-1));
    }
    else {
        if(book[in].ss <= a) ans = min(ans, f(in-1, a-book[in].ss, b, c));
        if(book[in].ss <= b) ans = min(ans, f(in-1, a, b-book[in].ss, c));
    }
    dp[in][a][b][c] = ans;
    return dp[in][a][b][c];
}

int main() {
    t = 1;
    scanf("%d", &t);

    while(t--) {
        fl = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &book[i].ff, &book[i].ss) , fl += book[i].ss;
        sort(book, book+n);
        memset(dp, -1, sizeof dp);

        int ans = INT_MAX;
        for(int i=0; i<=fl-book[n-1].ss; i++) {
            for(int j=0; j<=fl-book[n-1].ss; j++) {
                int temp = f(n-2, i,j, 2);
                if(temp == -1 || temp == MX) continue;

                int h = book[n-1].ff + temp;
                int w = max( (fl-i-j), max(i,j) );
                ans = min(ans, h*w);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/// 4 24 35 2
