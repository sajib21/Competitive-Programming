#include<bits/stdc++.h>
#define RED 0
#define WHITE 1
#define MOD 1000000007
#define ll long long int

using namespace std;

int t,k, a,b;
ll fib[100010], dp[100010];

ll getFib(int indx) {

    if(indx < 0) return 0;
    if(fib[indx]) return fib[indx];

    return fib[indx] = ( getFib(indx-1) + getFib(indx-k) ) % MOD;

}

ll getCount(int indx) {

    //if(indx == 0) return 1;
    if(indx < 0) return 0;

    if(dp[indx] != -1) return dp[indx];

    return dp[indx] = (getFib(indx) + getCount(indx-1) ) % MOD;
    //fib[indx] = fib[indx-1] + fib[indx-2];
}


int main() {

    memset(dp, -1, sizeof(dp));
    memset(fib, 0, sizeof(fib));
    //fib[0] = 1; fib[1] = 1;
    dp[0] = 0;

    scanf("%d %d", &t, &k);
    for(int i=0; i<k; i++) fib[i] = 1;

    while(t--) {

        scanf("%d %d", &a,&b);

        //printf("%d\n", getCount(b,RED) )


        //printf("%I64d\n", ans);
        cout << getCount(b) - getCount(a-1) << endl;
    }

    return 0;
}
