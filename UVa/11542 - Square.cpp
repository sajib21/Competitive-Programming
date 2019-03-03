#include<bits/stdc++.h>
#define LIM 500
#define pb(x) push_back(x)
#define vi vector<int>
#define ll long long int
#define MOD 1000000007

using namespace std;

bool isPrime[LIM+100];
vector<int>primes;
int sz;
int n;
ll a;
int co[200][1010];

void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=3; i<=LIM; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
    sz = primes.size();
}

void getDiv(ll x, int in) {
    vi ans;
//    cout << "FACTOR " << x << ' ' << in << endl;
//    getchar();
    for(int i=0; i<sz && primes[i] <= x; i++) {
        int p = primes[i];
        int cnt = 0;
        while(x%p==0) {
            cnt++;
            x /= p;
        }
//        cout << i << ' ' << primes[i] << ' ' << in << ' ' << cnt << ' ' << x << endl;
//        getchar();
        co[i][in] = cnt%2;
    }
//    ans.pb(0);
//    if(x != 1) ans.pb(1);
//    return ans;
}




ll gauss() {
    int pivot[1010];
    memset(pivot, -1, sizeof pivot);

    int row = 62, col = n+1;

//    for(int r=0; r<row; r++) {
//        for(int c=0; c<col; c++) cout << co[r][c] << ' ';
//        cout << endl;
//    }

    for(int r=0, c=0; c<col-1 && r<row; c++) {
        int cur = r;
        for(int i=r; i<row; i++) if(co[i][c] > co[cur][c]) {
            cur = i;
        }
        if(!co[cur][c]) continue;
        pivot[c] = r;
//        cout << "PIV " << cur << ' ' << c << endl;
        if(cur != r) swap(co[cur], co[r]);

        for(int i=0; i<row; i++) if(i != r && co[i][c]) {
            for(int j=c; j<col-1; j++) co[i][j] ^= co[r][j];
        }
        r++;
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(pivot[i] == -1) ans++;
    }
    return ans;
}


ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n);
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans);
}


int main() {
    freopen("11542i.txt", "r", stdin);
    freopen("11542o.txt", "w", stdout);
    genSieve();
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(co, 0, sizeof co);
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%lld", &a);
            getDiv(a, i);
        }
        printf("%lld\n", bigMod(2, gauss() , MOD)-1 );
    }
}
