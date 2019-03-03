#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int n,k,m;
ll dp[1010][101][3];
ll ex[1010], bas[1010];

//ll po(int in) {
//    if(!in) return 1;
//    if(ex[in]) return ex[in];
//    return ex[in] = (10*po(in-1)) % m;
//}

ll f(int in, int mod, int con) {
    if(!mod && con) {
//        if(in == n-1) return 9;
        if(in == n) return 1;
        return (9*ex[n-in-1]) % m;
    }
    if(in == n) {
        return 0;
    }
    if(dp[in][mod][con] != -1) return dp[in][mod][con];
    ll ans = 0;
    ans = (ans + f(in+1, (mod), con)) % m;
    for(int i=1; i<=9; i++) ans = (ans + f(in+1, (mod+i*bas[in])%k, 1)) % m;
    return dp[in][mod][con] = ans;
}

int main() {
    cin >> n >> k >> m;
    memset(dp, -1, sizeof dp);

    ex[0] = bas[0] = 1;
    for(int i=1; i<=1000; i++) {
        ex[i] = (ex[i-1]*10)%m;
        bas[i] = (bas[i-1]*10)%k;
    }

    if(m == 1) {
        cout << 0 << endl; return 0;
    }

    cout << f(0, 0, 0) << endl;

//    main();
}
