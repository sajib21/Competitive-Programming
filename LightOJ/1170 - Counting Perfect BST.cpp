#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 100000007
#define MAX 10000000000

using namespace std;



int isPow[LIM+100], sz;
vector<ll>pows;
//vector<ll>expo;
ll expo[200000];
int exn = 0;

void genPows() {
    pows.clear();
    memset(isPow, 0, sizeof(isPow));
    isPow[0] = isPow[1] = 1;
    for(int i=4; i<=LIM; i*=2) isPow[i] = 1;
    int sq = sqrt(LIM);
    for(int i=3; i<=sq; i++) {
        if(!isPow[i]) {
            for(int j=i*i; j<=LIM; j*=i) isPow[j] = 1;
        }
    }
    pows.pb(2);
    for(int i=3; i<=LIM; i++) if(!isPow[i]) pows.pb(i);
    int sz = pows.size();

    for(int i=0; i<sz; i++) {
        ll pp = pows[i];
        for(ll j=pp*pp; j<=MAX; j*=pp) {
//            expo.pb(j);
            expo[exn++] = j;
//            cout << j << ' ' ;
//            getchar();
        }
    }
    sort(expo, expo+exn);
}


ll bigMod(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1)*n);
    ll ans = bigMod(n, r/2);
    return (ans*ans);
}


ll a,b;
ll dp[4020];

int main() {

    genPows();
//    sz = expo.size();

//

//    cout << expo[exn-1] << endl;

    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for(int i=2; i<=4020; i++) {
        for(int j=0; j<i; j++) dp[i] = (dp[i] + (dp[j]*dp[i-j-1]) % MOD ) % MOD;
    }
    dp[0] = 0;

//    for(int i=0; i<2000; i++) cout << dp[i] << ' ' ; cout << endl;

    int T;
    scanf("%d", &T);

    int hm = 1;

    for(int t=1; t<=T; t++) {
        scanf("%lld %lld", &a,&b);

        hm =  upper_bound(expo, expo+exn, b) - lower_bound(expo, expo+exn, a) ;
//        hm = lower_bound()
//        cin >> hm ;

//        cout << "N " << hm << endl;
//        cout << hm << endl;
        printf("Case %d: %lld\n", t, dp[hm]);
//        hm++;
    }

    return 0;
}
