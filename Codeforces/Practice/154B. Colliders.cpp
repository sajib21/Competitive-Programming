#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     100000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;


bool isPrime[LIM+100];
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

int n,m,x, prmCnt[LIM+10], numFlag[LIM+10], prmNum[LIM+10];
char c;

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    genSieve();
    sz = primes.size();
//    cout << sz << endl;

    scanf("%d %d", &n,&m);
    while(m--) {
        getchar();
        scanf("%c %d", &c, &x);

        if(c == '+') {
            ll ans = 1;
            int num = x;

            if(numFlag[x]) {
                printf("Already on\n");
                continue;
            }
            if(x == 1) {
                numFlag[x] = 1;
                printf("Success\n");
                continue;
            }

            bool f = true;
            int cl;
            for(int i=0; i<sz && primes[i]*primes[i] <= num && f; i++) {
                if(num % primes[i] == 0) {
                    while(num % primes[i] == 0) {
                        num /= primes[i];
                    }
                    if(prmCnt[ primes[i] ]) {
                        f = false;
                        cl = primes[i];
                    }
                }
            }
            if(f && num > 1) {
                if(prmCnt[num]) {
                    f = false;
                    cl = num;
                }
            }

            if(!f) {
                printf("Conflict with %d\n", prmNum[cl]);
            }
            else {
                printf("Success\n");
                num = x;
                for(int i=0; i<sz && primes[i]*primes[i] <= num && f; i++) {
                    if(num % primes[i] == 0) {
                        while(num % primes[i] == 0) {
                            num /= primes[i];
                        }
                        prmCnt[ primes[i] ]++;
                        prmNum[ primes[i] ] = x;
                        numFlag[ x ] = 1;
                    }
                }

                if(num > 1) {
                    prmCnt[ num ]++;
                    prmNum[ num ] = x;
                    numFlag[ x ] = 1;
                }
            }


        }
        else {
            if(!numFlag[x]) {
                printf("Already off\n");
                continue;
            }
            printf("Success\n");
            if(x == 1) {
                numFlag[x] = 0;
                continue;
            }
            int num = x;
            for(int i=0; i<sz && primes[i]*primes[i] <= num; i++) {
                if(num % primes[i] == 0) {
                    while(num % primes[i] == 0) {
                        num /= primes[i];
                    }
                    prmCnt[ primes[i] ]--;
                    prmNum[ primes[i] ] = 0;
                    numFlag[ x ] = 0;
                }
            }

            if(num > 1) {
                prmCnt[ num ]--;
                prmNum[ num ] = 0;
                numFlag[ x ] = 0;
            }

        }
    }

    return 0;
}



