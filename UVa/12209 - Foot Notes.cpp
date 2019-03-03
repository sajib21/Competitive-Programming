#include<bits/stdc++.h>
#define bit bitset<100>
#define MAX 1000000009

using namespace std;

int n,s,w, k,x;
bit p[510];
int dp[505];

int f(int in) {
    if(in > n) return 0;
    if(dp[in] != -1) return dp[in];

    int ans = MAX;
    bit cur = 0;
    for(int i=in; i<=n ; i++) {
        cur |= p[i];
        if(cur.count()+(i-in+1) <= s) ans = min(ans, (int)cur.count()+f(i+1) );
        else break;
    }
    return dp[in] = ans;
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(p, 0, sizeof p);
        memset(dp, -1, sizeof dp);

        scanf("%d %d %d", &n,&s,&w);
        for(int i=0; i<w; i++) {
            scanf("%d", &k);
            while(k--) {
                scanf("%d", &x);
                p[x][i] = 1;
            }
        }

//        bool g = true;
//        for(int i=0; g && i<n; i++) if(p[i].count()+1 > s) g = false;
//        if(!g) {
//            printf("Case %d: -1\n", t);
//            continue;
//        }
        if( f(1) == MAX ) dp[1] = -1;
        printf("Case %d: %d\n",t, dp[1] );
    }
}
