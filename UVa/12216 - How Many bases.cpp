#include<bits/stdc++.h>
#define MAX 100000000
#define MOD 100000007
#define ll long long int
#define vi vector<int>
#define pb(x) push_back(x)


using namespace std;

int chkBit(int mask, int p) { return mask & (1<<p); }

bool isPrime[MAX+5];
vi primes;
void gen() {
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=MAX; i+=2) isPrime[i] = 1;
    for(int i=3; i<=MAX; i+=2) {
        if(isPrime[i]) continue;
        for(int j=i+i; j<=MAX; j+=i) isPrime[j] = 1;
    }
    primes.pb(2);
    for(int i=3; i<=MAX; i+=2) if(!isPrime[i]) primes.pb(i);
}
vi getDivCnt(ll n, ll m) {
    vi ans;
    if(!isPrime[n]) {
        ans.pb(1*m);
        return ans;
    }
    for(int i=0; primes[i]*primes[i]<=n; i++) {
        int p = primes[i];
        int cnt = 0;
        while(n%p==0) {
            cnt++;
            n /= p;
        }
        if(cnt) ans.pb(cnt*m);
    }
    if(n > 1) ans.pb(1*m);
    return ans;
}

ll n,m,t;
vi divCnt;

ll f(int mask) {
//    cout << "CALC " << mask << endl;
    ll ans = 1;
    for(int p=0; p<divCnt.size(); p++) {
        if(chkBit(mask, p)) ans *= (divCnt[p]/t - divCnt[p]/(t+1));
        else ans *= (divCnt[p]/t + 1);
//        cout << ans << endl;
        ans %= MOD;
    }
    return ans;
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    gen();
    int T=1;
    while(scanf("%lld %lld %lld", &n,&m,&t)) {
        if(!n && !m && !t) return 0;

        divCnt = getDivCnt(n,m);

//        cout << divCnt.size() << endl;

//        cout << "SZ " << divCnt.size() << endl;
//        for(int i=0; i<divCnt.size(); i++) cout << divCnt[i] << ' ' ; cout << endl;

        ll ans = 0;
        ll target = 1<<(divCnt.size()) ;
        int xx = divCnt.size();
        for(int i=1; i<target; i++) {
//            bitset<10>bit = i;
            ll cur = f(i);
            if(__builtin_popcount(i)&1) {
                ans += cur;
//                cout << bit << " ADD " << cur << endl;
            }
            else {
                ans -= cur;
//                cout << bit << " SUB " << cur << endl;
            }
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }

        printf("Case %d: %lld\n", T++, ans );
    }
}
