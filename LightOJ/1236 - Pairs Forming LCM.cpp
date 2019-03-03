#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

///DIRECTION ARRAY
/*
int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};
*/

///ROW COLUMN INFO
/*
struct rc {
    int r, c, tim;
    rc() {}
    rc(int rr, int cc, int t) {
        r = rr;
        c = cc;
        tim = t;
    }
};
*/




bool isPrime[LIM+100];
vector<int>primes;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
}



ll bigMod(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1)*n) ;
    ll ans = bigMod(n, r/2);
    return (ans*ans) ;
}


ll n;

int main() {

    genSieve();
    int sz = primes.size();
//    cout << sz << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld", &n);
        ll nn = n;

        ll fc = 1 , pfc = 0;

        for(int i=0; i<sz && primes[i]*primes[i] <= nn; i++) {
            if(nn % primes[i] == 0) {
                pfc++;
                ll tmp = 0;
                while(nn % primes[i] == 0) {
                    nn /= primes[i];
                    tmp++;
                }
                fc *= (2*tmp + 1);
            }
        }
        if(nn!=1) fc *= 3;
        printf("Case %d: %lld\n", t, (fc+1)/2 );
    }

    return 0;
}
