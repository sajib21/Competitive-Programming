#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 500000
#define MOD 1000000007
#define MAX 40000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

bool isPrime[LIM+100];
vector<int>primes;
int sz;
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

int n,x, num[MAX+10];
int numFlag[LIM+10];
//vii graph[LIM+10];
vii Graph[MAX+10];

int match[MAX+10], visl[MAX+10], visr[MAX+10];

bool bfs() {
    int dis = INT_MAX;
    memset(visl, -1, sizeof(visl));
    memset(visr, -1, sizeof(visr));
    queue<int>q;

    for(int i=1; i<=n; i++) {
        if(!match[i]) {
            visl[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        int sz = Graph[u].size();
        if(visl[u] > dis) break;

//        cout << u << ' ' << visl[u] << endl;

        for(int i=0; i<sz; i++) {
            int v = Graph[u][i];
            if(visr[v] == -1) {
                visr[v] = visl[u] + 1;
                if(!match[v]) dis = visr[v];
                else {
                    int w = match[v];
                    visl[w] = visr[v] + 1;
                    q.push(w);
                }
            }
        }
    }
//    cout << "RETURN BFS " << (dis != INT_MAX) << endl;;
    return dis != INT_MAX;
}

bool findMatch(int u) {
    int sz = Graph[u].size();
//    if(!sz) retur
    for(int i=0; i<sz; i++) {
        int v = Graph[u][i];
        if(visr[v] == visl[u]+1) {
            visr[v] = 0;
            if(!match[v] || findMatch(match[v])) {
                match[v] = u;
                match[u] = v;
//                cout << "MATCH OF " << u << " IS " << v << endl;
//                cout << "MATCH OF " << num[u] << " IS " << num[v] << endl;
//                vis[v] = 0
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    memset(match, 0, sizeof(match));
//    memset(vis, -1, sizeof(vis));
    int ans = 0;
    while(bfs()) {
        for(int i=1; i<=n; i++) {

            if(!match[i] && findMatch(i)) {
    //            cout << "TRY " << i << endl;
                ans++;
            }
        }
    }

//    cout << " BPM " << ans << endl;
    return ans;
}

int main() {

//    freopen("1356i.txt", "r", stdin);
//    freopen("1356o.txt", "w",stdout);

    genSieve();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(numFlag, 0, sizeof numFlag);
//        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            scanf("%d", &num[i]);
            numFlag[ num[i] ] = i;
//            graph[ num[i] ].clear();
            Graph[ i ].clear();
        }
        for(int q=1; q<=n; q++) {
            x = num[q];
            int temp = x;
            for(int i=0; i<sz && primes[i]*primes[i]<=temp; i++) {
                int p = primes[i];
                if(temp % p == 0) {
                    while(temp%p==0) temp /= p;
                    int b = x / p;
                    if(numFlag[b]) {
//                        graph[ b ].pb(x);
                        Graph[ numFlag[b] ].pb(numFlag[x]);
                        Graph[ numFlag[x] ].pb(numFlag[b]);
//                        cout << "g " << b << ' ' << x << endl;
//                        cout << "G " << numFlag[b] << ' ' << numFlag[x] << endl;
//                        graph[x].pb(b);
                    }
                }
            }
            if(temp > 1) {
                int p = temp;
                int b = x / p;
                if(numFlag[b]) {
//                    graph[ b ].pb(x);
                    Graph[ numFlag[b] ].pb(numFlag[x]);
                    Graph[ numFlag[x] ].pb(numFlag[b]);
//                    cout << "g " << b << ' ' << x << endl;
//                    cout << "G " << numFlag[b] << ' ' << numFlag[x] << endl;
//                    graph[x].pb(b);
                }
            }
        }
//        cout << "g" << endl;
//        for(int i=1; i<=n; i++) {
//            int u = num[i];
//            cout << u << " : " ;
//            for(int j=0; j<graph[u].size(); j++) cout << graph[u][j] << ' ';
//            cout << endl;
//        }
//        cout << "G" << endl;
//        for(int i=1; i<=n; i++) {
//            cout << i << " : " ;
//            for(int j=0; j<Graph[i].size(); j++) cout << Graph[i][j] << ' ';
//            cout << endl;
//        }

        printf("Case %d: %d\n", t, n-bpm());
    }

    return 0;
}
