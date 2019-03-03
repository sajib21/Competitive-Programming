#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pb(x) push_back(x)
#define MAX 1000000
#define LIM 100005

using namespace std;

bool isPrime[2*MAX+100];
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

//    for(int i=0; i<10; i++) cout << primes[i] << ' '; cout << endl;
}

int n,x;
vi edge[2*MAX+100], g[2*LIM];
int vis[2*LIM];

void f(int u, int x) {
//    cout << "INCLUDE " << u << ' ' << x << endl;
    for(int i=0; primes[i]*primes[i] <= x; i++) {
        int p = primes[i];
        if(x%p==0) {
            while(x%p==0) {
                x /= p;
            }
            edge[p].pb(u);
//            cout << p << ' ';
        }
    }
    if(x > 1) {
        edge[x].pb(u);
//        cout << x ;
    }
//    cout << endl;
}

void mergey(int p) {
//    if(edge[p].size()) cout << p << " : " << edge[p][0] << ' ';
    for(int i=1; i<edge[p].size(); i++) {
        g[ edge[p][i] ].pb( edge[p][i-1] );
        g[ edge[p][i-1] ].pb( edge[p][i] );
//        cout << edge[p][i] << ' ';
    }
//    cout << endl;
}

void dfs(int u) {
    vis[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    gen();
//    cout << primes.size()
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(edge, NULL, sizeof edge);
        memset(g, NULL, sizeof g);
        memset(vis, 0, sizeof vis);

        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            f(i, x);
        }

//        mergey(11);
        for(int i=0; i<primes.size(); i++) mergey(primes[i]);




        int ans = 0;
        for(int i=0; i<n; i++) if(!vis[i]) {
            ans++;
            dfs(i);
        }
        printf("Case %d: %d\n", t, ans);
    }
}
