#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

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

///PREREQ - GENSIEVE()
int divCount(ll num) {
    int ans = 1;
    int sz = primes.size();
    for(int i=0; i<sz && primes[i]*primes[i] <= num; i++) {
        int cnt = 1;
        while(num % primes[i] == 0) {
            cnt++;
            num /= primes[i];
        }
        ans *= cnt;
    }
    if(num > 1) ans *= 2;
    return ans;
}

ll a,b;

int main() {
    genSieve();
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld %lld", &a, &b);

        if(b*b > a) {
            printf("Case %d: 0\n", t);
            continue;
        }

        ll ans = divCount(a);
        ans /= 2;

//        cout << ans << endl;

        for(int d=1; d<b; d++) if(a%d==0) ans--;

        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}


