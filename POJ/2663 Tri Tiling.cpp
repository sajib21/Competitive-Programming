#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <cstring>

#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int n;
ll dp[34][7];

ll f(int in, int op) {
    if(in == 0) {
        if(!op) {
//            cout << in << ' ' << op << endl;
            return 1;
        }
        else return 0;
    }
    if(dp[in][op] != -1) return dp[in][op];

    ll ans = 0;
    if(op == 0) return dp[in][op] = f(in-1, 1) + f(in-1, 2) + f(in-1, 5);
    if(op == 1) return dp[in][op] = f(in-1, 3) + f(in-1, 0);
    if(op == 2) return dp[in][op] = f(in-1, 0) + f(in-1, 4);
    if(op == 3) return dp[in][op] = f(in-1, 1);
    if(op == 4) return dp[in][op] = f(in-1, 2);
    if(op == 5) return dp[in][op] = f(in-1, 0);
}

int main() {

    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &n) && n != -1) {
        printf("%lld\n", f(n, 0) );
    }
    return 0;
}
