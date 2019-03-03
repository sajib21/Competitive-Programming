#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
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

bool isPrime[MAX+100], taken[10];
vector<int>primes, anaprimes, opt;

bool ifAna(int in, int val) {
    if(in == opt.size()) {
//        cout << "CHK RET " << val << ' ' << isPrime[val] << endl; getchar();
        return isPrime[val];

    }

    for(int i=0; i<opt.size(); i++) if(!taken[i]) {
        taken[i] = 1;
        if(ifAna(in+1 , 10*val + opt[i])) return true;
        taken[i] = 0;
    }
    return false;
}

void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
//    primes.pb(0);
    for(int i=4; i<=MAX; i+=2) isPrime[i] = 1;
    int sq = sqrt(MAX);
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=MAX; j+=i) isPrime[j] = 1;
        }
    }

    primes.pb(2); primes.pb(3); primes.pb(5); primes.pb(7);
    anaprimes.pb(2); anaprimes.pb(3); anaprimes.pb(5); anaprimes.pb(7);

    for(int i=11; i<=MAX; i+=2) if(!isPrime[i]) {
        int t = i;
        bool f = false;
        while(t && !f) {
            int p = t % 10;
            if(p == 2 || p == 4 || p == 5 || p == 6 || p == 8 || p == 0) f = true;
            t /= 10;
        }
        isPrime[i] = f;
        if(!isPrime[i]) primes.pb(i);
    }

    int s = primes.size();
    for(int i=4; i<s; i++) {
        int prm = primes[i];
        memset(taken, 0, sizeof(taken));
        opt.clear();
        int tmp = prm;

        while(tmp) {
            opt.pb(tmp%10);
            tmp /= 10;
        }
//        cout << "GO " << prm << endl;
        bool f = ifAna(0, 0);

//        cout << "CHECKING " << prm << ' ' << f << endl; getchar();
        if(!f) anaprimes.pb(prm);
    }
    anaprimes.pb(MAX);

//    primes.pb(MAX);
}

//bool taken[10];
//vii opt;

int m;
int main() {

//    freopen("00897i.txt", "r", stdin);
//    freopen("00897o.txt", "w", stdout);

    genSieve();
//    int sz = primes.size(), sz2 = anaprimes.size();
//    cout << sz << ' ' << sz2 << endl;

//    for(int i=0; i<sz; i++) cout << primes[i] << ' ' ; cout << endl;
//    for(int i=0; i<sz2; i++) cout << anaprimes[i] << ' ' ; cout << endl;

    for(int t=1; ; t++) {
        scanf("%d", &m);
        if(!m) return 0;

        int tp = m, lim = 1;
        while(tp) tp /= 10 , lim *= 10;
//        cout << lim << endl;
        int temp = upper_bound(anaprimes.begin(), anaprimes.end(), m) - anaprimes.begin();
        if(anaprimes[temp] > lim || anaprimes[temp] == MAX) printf("0\n");
        else printf("%d\n", anaprimes[temp]);
    }
    return 0;
}
