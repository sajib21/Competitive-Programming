#include<bits/stdc++.h>
#define LIM 10000000
#define MAX 10000000
#define pb push_back

using namespace std;

bool isPrime[MAX+100];
vector<int>primes;
int sz;
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
    sz = primes.size();
}

int l,r;
int main() {
    genSieve();
    cout << sz << ' ' << primes[sz-1] << endl;
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &l, &r);
    }
}
