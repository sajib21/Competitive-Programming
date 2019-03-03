#include<bits/stdc++.h>
#define MOD 1000000007
#define LIM 10000007
#define ll long long int

using namespace std;

int n;
ll dp[LIM];

ll getCount(int n) {

    if(!n) return 1;
    else if(n < 0) return 0;

    if(dp[n] != 0) return dp[n];

    return dp[n] = (getCount(n-2) + 2*getCount(n-1))%MOD;
}

int main() {

    scanf("%d", &n);

    if(!n) printf("0\n");
    else printf("%lld\n", 3*getCount(n-2));

    return 0;

}
