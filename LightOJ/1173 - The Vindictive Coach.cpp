#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

ll dp[55][55][2];
int n, k;

ll get(int choto, int boro, int konta) {
    if(!choto && !boro) return 1;
    if(dp[choto][boro][konta] != -1) return dp[choto][boro][konta];

    ll ans = 0;
    if(!konta) {
        for(int i=0; i<choto; i++) {
            ans += get(i, boro+choto-i-1, !konta);
        }
    }
    else {
        for(int i=0; i<boro; i++) {
            ans += get(choto+boro-i-1, i, !konta);
        }
    }
    return dp[choto][boro][konta] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&k);

        if(k == 1) {
            if(n<=2) printf("Case %d: 1\n", t);
            else printf("Case %d: %llu\n", t, get(1, n-3, 0));
        }
        else {
            ll ans = get(k-1, n-k, 0);
            printf("Case %d: %llu\n",t, ans );
        }
    }
    return 0;
}
