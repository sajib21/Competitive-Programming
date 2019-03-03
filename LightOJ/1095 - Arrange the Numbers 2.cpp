#include<bits/stdc++.h>
#define ll long long int
#define LIM 1000
#define MOD 1000000007

using namespace std;

ll n,m,k;
ll comb[LIM+10][LIM+10], fact[LIM+10];

void getComb() {

    comb[0][0] = comb[1][0] = comb[1][1] = 1;

    for(int i=2; i<=1000; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j=1; j<i; j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j] ) % MOD;
    }
}

void getFact() {

    fact[0] = 1;
    for(int i=1; i<=1000; i++) fact[i] = (i * fact[i-1]) % MOD;
}

ll get(ll r, ll a, ll b) {

    if(r > a) return 0;
    return ( ((comb[a][r] * fact[b-r]) % MOD) - get(r+1, a,b) + MOD ) % MOD;
}

int main() {

    getComb();
    getFact();

//    for(int i=0; i<50; i++) cout << fact[i] << endl;
//    for(int i=1; i<50; i++) {
//        for(int j=1; j<i; j++) {
//            cout << i << ' ' << j << " : " << comb[i][j] << endl;
//        }
//    }

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%lld %lld %lld", &n,&m,&k);
//        cout << comb[m][k] << ' ' << get(0, m-k,n-k) << endl;
        printf("Case %d: %lld\n", t, ( comb[m][k] * get(0, m-k, n-k) ) % MOD );
    }

    return 0;

}
