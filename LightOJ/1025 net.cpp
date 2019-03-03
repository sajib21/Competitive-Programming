
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>



#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod abs
#define pf printf
#define sf scanf

using namespace std;

#define MAXX 64

char str[MAXX];
int len;
ll dp[MAXX][MAXX];

ll rec(int i, int j)
{
    if(j < i) return 0;
    if(i == j) return 1;

    ll &ret = dp[i][j];
    if(ret != -1) return ret;

    if(str[i] == str[j])
    {
        return ret =  1 + rec(i+1, j) + rec(i, j-1);
    }
    else
    {
        return ret = rec(i+1, j) + rec(i, j-1) - rec(i+1, j-1);
    }
}


int main()
{



    int kases, kaseno = 0;

    getint(kases);
    while(kases--)
    {
        cin>>str;
        len = strlen(str);
        mem(dp, -1);
        pf("Case %d: %lld\n", ++kaseno, rec(0, len - 1));
    }


    return 0;
}
