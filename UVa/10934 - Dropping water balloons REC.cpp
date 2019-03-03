#include<bits/stdc++.h>
#define pii pair<int,int>
#define mpr make_pair
#define ll long long int

using namespace std;

ll dp[103][65];

ll f(int rem, int tr) {
    if(!rem || !tr) return dp[rem][tr] = 0;;
    if(dp[rem][tr] != -1) return dp[rem][tr];
    return dp[rem][tr] = 1 + f(rem, tr-1) + f(rem-1,tr-1);
}

int k;
ll n;

int main() {
//    freopen("10934i.txt", "r", stdin);
//    freopen("10934o.txt", "w", stdout);

    memset(dp, -1, sizeof dp);
    while(scanf("%d %lld", &k,&n)) {
        if(!k) return 0;
        bool flag = true;
        for(int i=0; i<=63; i++) {
            if( f(k,i) >= n) {
                printf("%d\n", i);
                flag = false;
                break;
            }
        }
        if(flag) printf("More than 63 trials needed.\n");
    }
}

