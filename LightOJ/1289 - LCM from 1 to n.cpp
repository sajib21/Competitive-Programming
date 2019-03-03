///JUST STUCK IN MOD INVERSE AND COULDN'T SOLVE IT FOR THE WHOLE DAY. HAVE NEW IDEA BUT DON'T KNOW WHY DOESN'T IT WORK

#include<bits/stdc++.h>
#define ll long long int
#define ui unsigned int
#define vii vector<int>
#define vll vector<ll>
#define vui vector<ui>
#define pb push_back
#define LIM 100000000LL
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

ll mod = 4294967296LL;

int setBit(int n, int pos) { return n | (1 << pos);}
int chkBit(int n, int pos) { return n & (1 << pos);}

int isPrime[LIM/32 + 100];
vll primes, mulPrimes;

ll bigMod(ll n, ll r, ll mod) {
//    cout << n << ' ' << r << ' ' << mod << ' ' << ' ' << endl;
    if(!n) return 0;
    if(r==1) return n;
    if(r==0) return 1;
    ll ans;
    if(r%2) {
        ans = (bigMod(n, r-1, mod)*n) % mod;
//        cout << "BMO " << n << ' ' << r << ' ' << ans << endl;
        return ans;
    }
    ans = bigMod(n, r/2, mod) % mod;
//    cout << "BME " << n << ' ' << r << ' ' << ans*ans << endl;
    return (ans*ans) % mod;
}
//ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

void genSieve() {
//    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] |= (1 << 0); isPrime[0] |= (1 << 1);
//    for(int i=4; i<=LIM; i+=2) isPrime[i/32] |= (1 << i%32);
    ll sq = sqrt(LIM);
    for(ll i=3; i<=sq; i+=2) {
        if( !(isPrime[i/32] & (1 << (i%32) )) ) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j/32] |= (1 << (j%32));
        }
    }
    ll m = 1;
    primes.pb(2); mulPrimes.pb(1);
    for(ll i=3; i<=LIM; i+=2) if(!(isPrime[i/32] & (1 << (i%32))) ) {
        primes.pb(i);
        m = (m*i) % mod;
        mulPrimes.pb(m);
//        if(primes.size() == 5761455) {
//            cout << "PUSHING " << i << endl;
//        }
    }
}

int n, sq;

int main() {

//    cout << mod << endl;




    genSieve();
    cout << bigMod(1, mod-2, mod ) % mod << endl;
//    cout << primes.size();
//    cout << primes[5761455] << ' ' << primes[5761454] << endl;

//    cout << primes.size();
//    return 0;
//cout << primes[0] << ' ' << primes[1] << endl;
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        ll ans = 1;
        while(ans*2 <= n) ans = (ans*2) % mod;

        sq = sqrt(n);
        int sz = primes.size();
        for(int i=1; primes[i]*primes[i] <= n && i < primes.size(); i++) {
//            if( !(isPrime[i/32] & (1 << (i%32))) ) {
                cout << primes[i] << " is prime " << endl;
                ll tmp = 1;
                while(tmp*primes[i] <= n) tmp = (tmp*primes[i]) % mod;
                cout << tmp << endl;
                ans = (ans * tmp) % mod;
//            }
        }
        cout << "ANS " << ans << endl;
        int x = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
//        if(primes[x] > n || x >= primes.size()) x--;
        int in = lower_bound(primes.begin(), primes.end(), sq) - primes.begin();
        if(primes[in] > sq && in) in--;
//        if(primes[in] >= sq) in--;
        cout << "X " << x << " IN " << in << endl;
        cout << ans << ' ' << primes[x] << ' ' << mulPrimes[x] << ' ' << primes[in] << ' ' << mulPrimes[in] << endl;
        ll a = mulPrimes[x] , b = mulPrimes[in];
        ll g = __gcd(a,b);
        a /= g; b /= g;
        cout << "AB " << a << ' ' << b << ' ' << g << endl; ///OK TILL THIS LINE
        if(b^1) cout << "B ODD" << endl;
        else cout << "B EVEN" << endl;
        ll temp = bigMod(b ,  mod-2, mod ) % mod;
        cout << temp << endl;
        ans = (ans * ( (temp%mod) *  (a%mod) ) % mod ) % mod;
//        ans = (ans * a / b) % mod;
//        for(int i=sq+1; i<=n; i+=2) if( !(isPrime[i/32] & (1 << (i%32))) ) ans *= i;
//        cout << ans << endl;
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
