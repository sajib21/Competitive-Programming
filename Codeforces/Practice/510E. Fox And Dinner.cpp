/*
Between conflicting voters, there can be only one who will satisfy. So have edge between them and get BPM
*/
#include<bits/stdc++.h>
#define MAX 20000
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

bool isPrime[MAX+10];
vi primes;
int sz = primes.size();

void gen() {
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=MAX; i+=2) isPrime[i] = 1;
    for(int i=3; i<=MAX; i+=2) {
        if(isPrime[i]) continue;
        for(int j=i+i; j<=MAX; j+=i) isPrime[j] = 1;
    }
    primes.pb(2);
    for(int i=3; i<=MAX; i+=2) if(!isPrime[i]) primes.pb(i);
    sz = primes.size();
}

int n,f,v, a[400];
string in[505], ex[505];
vi graph[505];

int match[505], nxt[505], vis[505];
bool findMatch(int u) {
    cout << "IN " << u << endl;
    int sz = graph[u].size();
    int keep = -1;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            cout << "TRU " << u << ' ' << v << endl; getchar();

            if(match[v] || nxt[v-n] == u+n) continue;

            vis[v] = 1;

            match[v] = u;
//                match[u] = v;
            nxt[u] = v;
                cout << "MATCH " << u << ' ' << v << endl; getchar();
            return true;
//            }
        }
    }

    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            cout << "TR2 " << u << ' ' << v << endl; getchar();

            vis[v] = 1;

            if( match[v] == 0 || findMatch(match[v]) ) {
                match[v] = u;
//                match[u] = v;
                nxt[u] = v;
                cout << "MATCH " << u << ' ' << v << endl; getchar();
                return true;
            }
        }
    }

//    nxt[]

    return false;
}

int bpm() {
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        memset(vis, 0, sizeof(vis));
//        cout << "TRY " << i << endl;
        if(!match[i] && findMatch(i)) cnt++;
        cout << "FOUND " << i << ' ' << nxt[i] << endl; getchar();
    }
    return cnt ;
}

int ans;
vi sol[400];

void ff(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    sol[ans].pb(u);

    if(nxt[u]) ff(nxt[u]-n);
}

int main() {
    gen();
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) continue;
            if(!isPrime[a[i]+a[j]]) {
                graph[i].pb(n+j);
//                cout << i << ' ' << n+j << endl;
            }
        }
    }

    int x = bpm();

    cout << x << endl;
    cout << "MATCH" << endl;
    for(int i=1; i<=n; i++) cout << nxt[i] << ' '; cout << endl;
    for(int i=1; i<=n; i++) cout << match[i+n] << ' '; cout << endl;

    if(x != n) cout << "Impossible" << endl;
    else {
        memset(vis, 0, sizeof vis);
        ans = 0;
        for(int u=1; u<=n; u++) {
            if(vis[u]) continue;
            ff(u);
            ans++;
        }
        cout << ans << endl;
        for(int i=0; i<ans; i++) {
            printf("%d", sol[i].size());
            for(int j=0; j<sol[i].size(); j++) printf(" %d", sol[i][j]);
            printf("\n");
        }
    }

    return 0;
}

