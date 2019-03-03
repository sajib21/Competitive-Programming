/*
Between conflicting voters, there can be only one who will satisfy. So have edge between them and get BPM
*/
///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

int m,f,v;
string in[505], ex[505];
vii graph[505];

int match[505], vis[505];
bool findMatch(int u) {
//    vis[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
//        if(costsVec[u][i] > cost) continue;
        if(!vis[v]) {
            vis[v] = 1;
            if((match[v] == 0 || findMatch(match[v])) ) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for(int i=1; i<=v; i++) {
        memset(vis, 0, sizeof(vis));
        if(!match[i] && findMatch(i)) {
            cnt++;
//            cout << "MATCH "  << endl;
//            for(int j=1; j<=v; j++) cout << j << ' ' << match[j] << endl;
        }
//        cout << "GOT " << i << ' ' << cnt << endl;
    }
//    cout << "FOUND " << estim << ' ' << cnt << endl;
//    cout << "BPM " << cnt << endl;
    return cnt ;

}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &m,&f,&v);
        for(int i=1; i<=v; i++) graph[i].clear();
        for(int i=1; i<=v; i++) cin >> in[i] >> ex[i];
        for(int i=1; i<=v; i++) {
//            if(in[i][0] == 'F') continue;
            for(int j=i+1; j<=v; j++) {
//                if(in[j][0] == 'M') continue;
                if(in[i] == ex[j] || in[j] == ex[i]) {
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
            }
        }

//        cout << "GRAPH" << endl;
//        for(int i=1; i<=v; i++) {
//            for(int j=0; j<graph[i].size(); j++) cout << graph[i][j] << ' ';
//            cout << endl;
//        }

        printf("Case %d: %d\n", t, v-bpm());

    }

    return 0;
}
