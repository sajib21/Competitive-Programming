#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;


/*

int isPrime[LIM+100];
vector<int>primes;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=2; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
}
*/

/*
ll bigMod(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1)*n) % MOD;
    ll ans = bigMod(n, r/2);
    return (ans*ans) % MOD;
}
*/

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n,m,k;
        double p;
        scanf("%d %d %d %lf", &n,&m,&k, &p);
        printf("Case %d: %.10lf\n", t, n * (k*p) );
    }

    return 0;
}
