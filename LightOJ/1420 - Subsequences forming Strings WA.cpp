/*
Had Wrong idea of the problem.
However, the problem i interpreted and solved was also very interesting!
The problem i assumed is as follows:

Say you have strings a,b,c. You have to determine the number of ways
you can choose one subsequence from each of a and b so that after CONCATING the two subsequence respectively (first from a, then from b),
you can make the string c.

i assumed that the subsequence must have non zero size.
*/


///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

int n;
ll dpSuf[1030][1030], dpPref[1030][1030];
char a[1030],b[1030],c[1030];

int main() {

//    freopen("BOB DATASET.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
//    cout << T << endl;
    for(int t=1; t<=T; t++) {
        scanf("%s %s %s", a,b,c);
//        printf("%s %s %s\n", &a,&b,&c);
//        for(int i = 0; i<100000000; i++);
        int as,bs,cs;
        as = strlen(a); bs = strlen(b); cs = strlen(c);

        memset(dpSuf, 0, sizeof dpSuf);
        memset(dpPref, 0, sizeof dpPref);
        for(int i=0; i<as; i++) dpPref[0][i] = 1;
        for(int i=0; i<bs; i++) dpSuf[0][i] = 1;

        for(int i=0; i<cs; i++) {
            for(int j=0; j<as; j++) {
                if(c[i] == a[j]) dpPref[i+1][j+1] += dpPref[i][j]; ///remember to shift i j to i+1 j+1
                dpPref[i+1][j+1] += dpPref[i+1][j];
                dpPref[i+1][j+1] %= MOD;
            }
        }

//        for(int i=0; i<cs; i++) {
//            for(int j=0; j<as; j++) cout << dpPref[i+1][j+1] << ' ' ;
//            cout << endl;
//        }

        reverse(b, b+bs);
        reverse(c, c+cs);

        for(int i=0; i<cs; i++) {
            for(int j=0; j<bs; j++) {
                if(c[i] == b[j]) dpSuf[i+1][j+1] += dpSuf[i][j]; ///remember to shift i j to i+1 j+1
                dpSuf[i+1][j+1] += dpSuf[i+1][j];
                dpSuf[i+1][j+1] %= MOD;
            }
        }
//        for(int i=0; i<cs; i++) {
//            for(int j=0; j<bs; j++) cout << dpSuf[i+1][j+1] << ' ' ;
//            cout << endl;
//        }

        ll ans = 0;
        for(int i=0; i<cs; i++) {
            ans = (ans + dpPref[i+1][as]*dpSuf[cs-i-1][bs]) % MOD;
//            cout << dpPref[i+1][as] << ' ' << dpSuf[bs-i-1][bs] << endl;
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
