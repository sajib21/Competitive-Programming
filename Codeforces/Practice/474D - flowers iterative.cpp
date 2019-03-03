#include<bits/stdc++.h>
#define RED 0
#define WHITE 1
#define MOD 1000000007
#define ll long long int

using namespace std;

int t,k, a[100010],b[100010], mxi = 0;
ll fib[100010], dp[100010];

void genFib() {

    for(int i=0; i<k; i++) fib[i] = 1;
    for(int i=k; i<=mxi; i++) fib[i] = (fib[i-1] + fib[i-k]) % MOD;
    //return fib[indx] = ( getFib(indx-1) + getFib(indx-k) ) % MOD;
}

void genCount() {

    //if(indx == 0) return 1;
    //if(indx < 0) return 0;

    //if(dp[indx] != -1) return dp[indx];
    for(int i=1; i<=mxi; i++)
        dp[i] = (fib[i] + dp[i-1] ) % MOD;
    //fib[indx] = fib[indx-1] + fib[indx-2];
}


int main() {

    memset(dp, -1, sizeof(dp));
    memset(fib, 0, sizeof(fib));
    //fib[0] = 1; fib[1] = 1;
    dp[0] = 0;

    scanf("%d %d", &t, &k);

    for(int i=0; i<t; i++) {

        scanf("%d %d", &a[i],&b[i]);
        mxi = max(mxi, max(a[i],b[i]));

        //printf("%d\n", getCount(b,RED) )


        //printf("%I64d\n", ans);
        //cout << getCount(b) - getCount(a-1) << endl;
    }
    genFib();
    genCount();

    for(int i=0; i<t; i++) cout << (dp[ b[i] ] - dp[a[i] - 1] + MOD) % MOD << endl;

    return 0;
}
