#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>

#define LIM 1024
#define MX 1e15
#define ld long double
#define pii pair<int,int>
#define mpr make_pair
#define ff first
#define ss second
#define ll long long int


using namespace std;

ll n,vel,x, samne[LIM+110], pisey[LIM+110];
pii hoga[LIM+110];
double dp[LIM+110][LIM+110][3];
int putki[LIM+110][LIM+110][3];

double fun(int lft, int rgt, int con) {

//    assert(lft >= 1 && rgt <= n && con < 2 && vel);

//    if(lft < 1 || rgt > n) return 2*MX; ///ei line na thkle rte dey
    if(lft == 1 && rgt == n) return 0;
    if(putki[lft][rgt][con] == 1) return dp[lft][rgt][con];

    double choda = 0;
    if(lft > 1) choda += samne[lft-1];
    if(rgt < n) choda += pisey[rgt+1];

    double ans = MX;

    if(lft > 1) {
        double ltl = 1.0*(1.0*hoga[lft].ff - hoga[lft-1].ff)/(1.0*vel);
        double rtl = 1.0*(1.0*hoga[rgt].ff - hoga[lft-1].ff)/(1.0*vel);
        if(!con) ans = min(ans, ltl*choda + fun(lft-1, rgt, 0) );
        else     ans = min(ans, rtl*choda + fun(lft-1, rgt, 0) );
    }
    if(rgt <= n-1) {
        double ltr = 1.0*(1.0*hoga[rgt+1].ff - hoga[lft].ff)/(vel*1.0);
        double rtr = 1.0*(1.0*hoga[rgt+1].ff - hoga[rgt].ff)/(1.0*vel);
        if(!con) ans = min(ans, ltr*choda + fun(lft, rgt+1, 1) );
        else     ans = min(ans, rtr*choda + fun(lft, rgt+1, 1) );
    }

    putki[lft][rgt][con] = 1;
    return dp[lft][rgt][con] = ans;
}

int main() {
//    freopen("1336i.txt", "r", stdin);
//    freopen("1336o.txt", "w", stdout);

    while(true) {
        scanf("%lld %lld %lld", &n,&vel,&x);
        if(n == 0 || vel == 0 || x == 0) return 0;
//        vel = abs(vel);
        ll sum = 0;
        for(int i=1; i<=n; i++) {
            int q;
            scanf("%lld %lld %lld", &hoga[i].ff, &q, &hoga[i].ss);
            sum += q;
        }
        hoga[n+1].ff = x; hoga[n+1].ss = 0;
        n++;
        std::sort(hoga+1, hoga+n+1);
//        memset(samne, 0, sizeof samne); memset(pisey, 0, sizeof pisey);
        samne[1] = hoga[1].ss; for(int i=2; i<=n; i++) samne[i] = samne[i-1] + hoga[i].ss;
        pisey[n] = hoga[n].ss; for(int i=n-1; i>=1; i--) pisey[i] = pisey[i+1] + hoga[i].ss;

        samne[0] = samne[n+1] = pisey[0] = pisey[n+1] = 0;

        int in = n; for(int i=1; i<=n; i++) if(hoga[i].ff == x) {
            in = i;
            break;
        }
//        assert(in <= 1001);

        memset(putki, 0, sizeof putki);
//        if(vel == 0) vel = 1;
        printf("%lld\n", (ll) floor(fun(in, in, 0)) + sum );
    }
    return 0;
}
