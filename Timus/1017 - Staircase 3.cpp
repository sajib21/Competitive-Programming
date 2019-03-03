#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
ll dp[505][505];

ll getMax( ll brick, ll last)
{

    if(!brick) return 1;
    else if(brick < 0) return 0;
    //else if(brick+1 == last) return 1;

    if(dp[brick][last] == 0)
    {
        ll temp = 0;
        for(ll i=last+1; i<=brick; i++)
        {
            temp += getMax(brick-i, i);
        }
        return dp[brick][last] = temp;
    }
    else return dp[brick][last];
}

int main()
{
    //cin >> n;
    scanf("%I64d", &n);

    //memset(dp, -1, sizeof(dp));

    printf("%I64d\n", getMax(n, 0)-1);

    return 0;
}
