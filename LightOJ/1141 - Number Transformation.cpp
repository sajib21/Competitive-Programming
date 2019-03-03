#include<bits/stdc++.h>
#define pii pair<int,int>
#define LIM 1000
#define pb push_back

using namespace std;


int isPrime[LIM+100], sz;
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
    sz = primes.size();
}


int main() {

    genSieve();

    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        int s,t, g, d;
        scanf("%d %d", &s, &t);

        queue<int>q;
        q.push(s);

        int vis[2000] = {0};

        int ans = INT_MAX;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(u == t) {
                ans = min(ans, vis[u]);
//                break;
            }


            int uu = u;
            for(int i=0; primes[i] <= uu && primes[i] < u ; i++) {
                if(uu%primes[i]==0) {
                    while(uu%primes[i]==0) uu/= primes[i];

                    int v = u + primes[i];
                    if( !vis[v] && v <= t ) {
                        vis[v] = vis[u] + 1;
                        q.push(v);
                    }
                }

            }
        }
        if(ans == INT_MAX) printf("Case %d: -1\n", tt);
        else printf("Case %d: %d\n", tt, ans);

    }
    return 0;

}
