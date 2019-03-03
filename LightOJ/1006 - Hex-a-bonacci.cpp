#include <stdio.h>
#include <vector>
#define MOD 10000007

using namespace std;

long long int dp[10005];
long long int fn(long long int n)
{
    if( n>=0 && n<6 ) return dp[n] %MOD;

    if(!dp[n])
    {
        dp[n]=( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) %MOD;
        return dp[n];
    }
    else return dp[n];
}

int main()
{
    long long int t,T, n=0, nn=0;
    scanf("%lld", &T);
    for(t=1; t<=T; t++)
    {
        while(n) {dp[n]=0; n--;}
        scanf("%lld %lld %lld %lld %lld %lld %lld", &dp[0],&dp[1],&dp[2],&dp[3],&dp[4],&dp[5],&n );
        printf("Case %lld: %lld\n", t, fn(n));
    }
    return 0;
}
