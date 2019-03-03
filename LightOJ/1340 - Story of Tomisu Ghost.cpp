using namespace std;

#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 10000019
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))



bool isPrime[LIM+100];
vector<int>primes;
vector< pair<int,int> > prmCnt[LIM+10];


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

void countPrmCnt() {

    int sz = primes.size();
    for(int i=0; i<sz; i++) {
        int cnt = 0;
        int p = primes[i];
        for(int num=p; num<=LIM; num+=p) {
            int nm = num;
            while(nm % p == 0) {
                cnt++;
                nm /= p;
            }
            prmCnt[num].pb(mp(p, cnt));
        }
    }
}

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}


int n,t;

int main() {

//    freopen("1340i.txt", "r", stdin);
//    freopen("1340o.txt", "w",stdout);

    genSieve();
    countPrmCnt();

//    for(int i=0; primes[i] <= 10; i++) {
//        int p = primes[i];
////        int ret = &prmCnt[ (10/p)*p ];
//        for(int x=0; x<prmCnt[ (10/p)*p ].size(); x++) if(prmCnt[ (10/p)*p ][x].first == p) {
//            cout << prmCnt[ (10/p)*p ][x].first << ' ' << prmCnt[ (10/p)*p ][x].second << endl;
//        }
//
//    }

    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        scanf("%d %d", &n, &t);

        if(t >= n) {
            printf("Case %d: -1\n", tt);
            continue;
        }

        ll ans = 1;
        int sz = primes.size();
        for(int i=0; i<sz && primes[i] <= n; i++) {
            int p = primes[i];
            int cnt = 0;
//            for(int num=p; num<=n; num+=p) {
//                cout << num ;
//                int p = primes[i];
            //        int ret = &prmCnt[ (10/p)*p ];
                for(int x=0; x<prmCnt[ (n/p)*p ].size(); x++) if(prmCnt[ (n/p)*p ][x].first == p) {
//                    cout << prmCnt[ (n/p)*p ][x].first << ' ' << prmCnt[ (n/p)*p ][x].second << endl;
                    cnt = prmCnt[ (n/p)*p ][x].second;
                    ans = (ans * bigMod(p, cnt/t, MOD)) % MOD;
                }
//            }
        }

        if(ans == 1) printf("Case %d: %d\n", tt, -1);
        else printf("Case %d: %d\n", tt, ans);
    }

    return 0;
}
