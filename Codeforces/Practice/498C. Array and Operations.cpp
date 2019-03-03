/// given an array and some pairs of indices, how many times you can select any pair i,j
/// and do a[i] = a[i]/v and a[j]/v where v is any common divisor
/// number theory + matching

#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define LIM 110
#define MXX 32000
using namespace std;

bool isPrime[MXX+10];
vi primes;

void gen() {
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=MXX; i+=2) isPrime[i] = 1;
    int sq = sqrt(MXX);
    for(int i=3; i<sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=MXX; j+=i) {
                isPrime[j] = 1;
            }
        }
    }
    for(int i=2; i<=MXX; i++) if(!isPrime[i]) primes.pb(i);
}

vi getDiv(int x) {
    vi ans;
    for(int i=0; primes[i]*primes[i] <= x; i++) {
        int p = primes[i];
        while(x%p==0) {
            ans.pb(p);
            x /= p;
        }
    }
    if(x != 1) ans.pb(x);
    return ans;
}

int n,m, a[LIM];
vi divs[LIM];
int sz[LIM];
vi g[LIM*250];

int match[LIM*250], vis[LIM*250];

bool findMatch(int u) {
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        if(!match[v] || findMatch(match[v])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int f() {
    int ans = 0;
    for(int u=1; u<=sz[n]; u++) {
        memset(vis, 0, sizeof vis);
        if(!match[u] && findMatch(u)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    gen();

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        divs[i] = getDiv(a[i]);
    }
    for(int i=1; i<=n; i++) sz[i] = sz[i-1] + divs[i].size();

    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        for(int i=0; i<divs[a].size(); i++) {
            int j = lower_bound(divs[b].begin(), divs[b].end(), divs[a][i]) - divs[b].begin();
            for(; j<divs[b].size(); j++) {
                if(divs[a][i] == divs[b][j]) {
                    int u,v;
                    u = sz[a-1] + i + 1;
                    v = sz[b-1] + j + 1;
                    g[u].pb(v); g[v].pb(u);
                }
                else break;
            }
        }
    }

    printf("%d\n", f());
}
