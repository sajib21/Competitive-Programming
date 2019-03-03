#include<bits/stdc++.h>
#define ll unsigned long long int
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

int n,m;
pll dp[66][66][2][66];

pll operator + (pll a, pll b) {
    return pll(a.ff+b.ff, a.ss+b.ss);
}

pll f(int in, int on, int last, int step) {
//    cout << "IN " << in << ' ' << on << ' ' << last << ' ' << step << endl;
//    getchar();
    if(in == n) {
        if(on < m) return pll(0,0);
        if(step < on) return pll(1,0);
        else if(step > on ) return pll(0,1);
        return pll(0,0);
    }
    if(dp[in][on][last][step].ff != -1) return dp[in][on][last][step];

    pll ans = f(in+1,on, last, step);
    if(!last) ans = ans + f(in+1, on+(n-in), !last, step+1 );
    else      ans = ans + f(in+1, on-(n-in), !last, step+1 );

//    cout << "OUT " << in << ' ' << on << ' ' << last << ' ' << step << ' ' << ans.ff << ' ' << ans.ss << endl;
//    getchar();

    return dp[in][on][last][step] = ans;
}

int main() {
    int t = 1;
    while(scanf("%d %d", &n, &m)) {
        if(!n && !m) return 0;
        memset(dp, -1, sizeof dp);
//        pll ans = pll(0m0);
//        for(int rem=m; rem<=n; rem++) {
        pll ans = f(0, 0, 0, 0);
//        }
        printf("Case %d: %llu %llu\n", t++, ans.ff, ans.ss);
    }
}
