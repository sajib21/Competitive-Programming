#include<bits/stdc++.h>
#define ll long long int
#define MOD 100000007
#define LIM 1000

using namespace std;

ll n,k,s;
ll sum[15*LIM+10], preSum[15*LIM+10] , preBig[15*LIM+10];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T; t++) {
        scanf("%ld %lld %lld", &n,&k,&s);

//        memset(preSum, 1, sizeof(preSum));

        for(ll i=0; i<=s; i++) preSum[i] = 1 , preBig[i] = i+1;

        for(ll i=1; i<=n; i++) {

            for(ll j=0; j<i; j++) sum[j] = 0;
            for(ll j=i; j<=s; j++) sum[j] = ( preBig[j-1] - (k * ( (j-k-1 >= 0)? preSum[j-k-1] : 0 ))%MOD -  ( ( (j-k-1 >= 0)? preBig[j-k-1] : 0 ) ) + 10*MOD ) % MOD;



            for(int j=0; j<i; j++) preSum[j] = preBig[j] = 0;
            for(int j=i; j<=s; j++) {
                preSum[j] = ( sum[j] + preSum[j-1]  ) % MOD;
                preBig[j] = ( preSum[j] + preBig[j-1] ) % MOD;
            }
        }

//        for(int i=1; i<=10; i++) cout << preSum[i] << ' '; cout << endl;

        printf("Case %d: %lld\n", t, sum[s]);
    }
    return 0;
}
