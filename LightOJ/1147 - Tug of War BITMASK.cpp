#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 100000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int n, w[105], all, lim;
ll dp[MAX/2 + 10];

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("1147o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        all = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &w[i]);
            all += w[i];
        }
        lim = (all+1) / 2;
        ll c1 = (n+1) / 2;
        ll c2 = (n) / 2;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1LL;
        for(int in=1; in<=n; in++) {
            for(int make=lim; make>=w[in]; make--) {
                dp[make] |= (dp[ make - w[in] ] << 1LL);
            }
        }

        for(int make=lim; make>=0; make--) {
            if( (dp[make] & (1LL << c1)) ) {
                printf("Case %d: %d %d\n", t, min(make, all-make), max(make, all-make));
                break;
            }
        }
    }
    return 0;
}

