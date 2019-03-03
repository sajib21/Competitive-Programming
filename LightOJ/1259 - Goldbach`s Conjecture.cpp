#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

bool isPrime[LIM+10];
//vector<int>primes;
int primes[1000000 + 10];

void genSieve() {
//    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }

    primes[0] = 2;
    int c = 1;
    for(int i=3; i<=LIM; i+=2) {
        if(!isPrime[i]) primes[c++] = i;
//        cout << "BUG " << c << ' ' << primes[c-1] << endl;
//        getchar();
    }
}

int main() {

    genSieve();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int n;
        scanf("%d", &n);
        if(n == 4) {
            printf("Case %d: 1\n", t);
            continue;
        }

        int cnt = 0;
        for(int i=0; primes[i] <= n/2; i++) {
            if( !isPrime[ n-primes[i] ] ) {
//                cout << n-primes[i] << ' ' << isPrime[ n-primes[i] ] << endl;
                cnt++;
            }
        }
        printf("Case %d: %d\n", t, cnt);
    }
    return 0;

}
