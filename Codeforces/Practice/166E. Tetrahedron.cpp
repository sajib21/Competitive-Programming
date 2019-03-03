#include<bits/stdc++.h>
#define MOD 1000000007
#define LIM 10000007
#define ll long long int

using namespace std;

int n;
ll dp[LIM][3];

ll getCount(int n, int lastA) {

    if(!n) {
        if(lastA) return 1;
        else return 0;
    }
//    else if(n < 0) return 0;

    if(dp[n][lastA] != 0) return dp[n][lastA];

    if(lastA) return dp[n][lastA] = (3*getCount(n-1, !lastA) )%MOD;
    else return dp[n][lastA] = (getCount(n-1, !lastA) + 2*getCount(n-1, lastA) ) % MOD;
}

int main() {

    scanf("%d", &n);

    if(!n) printf("0\n");
    else printf("%lld\n", getCount(n, 1));

    return 0;

}
