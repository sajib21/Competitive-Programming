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

using namespace std;

int n, cnt=0;
map<string, string>mp;
map<string, int>flag;
string plc[335];
vector<int>order;
int vis[335];

void dfs(int u) {
//    cout << u << ' ' << plc[u] << endl;

    vis[u] = 1;
    int v = flag[ mp[ plc[u] ] ] ;
//    cout << "V " << v << ' ' << vis[v] << endl;
    if(v && !vis[v]) dfs(v);
    order.pb(u);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        cnt = 0;
        mp.clear();
        flag.clear();
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for(int i=1; i<n; i++) {
            string u,v;
            cin >> u >> v;
            mp[u] = v;
            if(!flag[u]) plc[++cnt] = u, flag[u] = cnt;
            if(!flag[v]) plc[++cnt] = v, flag[v] = cnt;
        }
//        for(int i=1; i<=n; i++) cout << i << ' ' << plc[i] << endl;
        for(int i=1; i<=n; i++) if(!vis[i]) {
//            cout << "CALLING " << i << ' ' << endl;
            dfs(i);
        }
        printf("Case %d:\n", t);
        while(!order.empty()) {
            int nd = order.back();
            order.pop_back();
            cout << plc[nd] << endl;
        }
        cout << endl;
    }
    return 0;
}
