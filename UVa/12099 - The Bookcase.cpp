#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define MX 100000

using namespace std;

int t,n, fl;
pii book[100];
int dp[11][2101][2101][2];
int IN,A,B,C;
int f(int in, int a, int b, int c) {
//    cout << "IN " << in << ' ' << a << ' ' << b << ' ' << c << endl; getchar();
    if(in < 0) {
        if(a == 0 && b == 0 && c == 0) return 0;
        return MX;
    }
    if(dp[in][a][b][c] != -1) return dp[in][a][b][c];

    int ans = f(in-1, a,b,c);
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
    if(in == n-2 && a == 39 && b == 35 && c == 2) {
        cout << "OUT " << in << ' ' << a << ' ' << b << ' ' << c << ' ' << ans << endl;
        cout << IN << ' ' << A << ' ' << B << ' ' << C << endl;
        getchar();
    }
    return dp[in][a][b][c] = ans;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        fl = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &book[i].ff, &book[i].ss) , fl += book[i].ss;
        sort(book, book+n);

        cout << "SORTED" << endl;
        for(int i=0; i<n; i++) cout << book[i].ff << ' ' << book[i].ss << endl;
//        reverse(book, book+n);
        memset(dp, -1, sizeof dp);
//        f(1, 0,0,0);

//        cout << f(1,0,0,0) << endl;

//        cout << n << ' ' << fl << endl;
//        cout << f(n-2, 30, 30, 2) << endl;
//        cout << f(n-2, 39, 35, 2) << endl;
//        cout << "XXXX " << f(n-2, 39, 35, 2) << endl; getchar();

        int ans = INT_MAX;
        for(int i=0; i<=fl-book[n-1].ss; i++) {
            for(int j=0; j<=fl-book[n-1].ss; j++) {
//                int temp = dp[n][i][j][2];
                IN = n-2; A = i; B = j; C = 2;
                int temp = f(n-2, i,j, 2);
//                if(i == 39 && j == 35) {
////                    cout << "PAISI " << i << ' ' << j << ' ' << temp << endl; getchar();
//                }
                if(temp == -1 || temp == MX) continue;

                int h = book[n-1].ff + temp;
                int w = max( (fl-i-j), max(i,j) );
                ans = min(ans, h*w);
//                if(i == 39 && j == 35) {
//                    cout << "TRY " << i << ' ' << j << ' ' << temp << ' ' << h << ' ' << w << ' ' << h*w << ' ' << ans << endl; getchar();
//                }
            }
        }
        printf("%d\n", ans);
    }
}
