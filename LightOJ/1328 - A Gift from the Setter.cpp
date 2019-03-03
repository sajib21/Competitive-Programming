#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int k,c,n;
ll a[LIM+10];

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %lld", &k,&c,&n,&a[0]); n--;
        for(int i=1; i<=n; i++) a[i] = (a[i-1]*k + c) % MOD;
        sort(a, a+n+1);
        ll ans = 0;
        for(int i=0, j=-n; i<=n; i++, j+=2) {
            ans += j*a[i];
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}

