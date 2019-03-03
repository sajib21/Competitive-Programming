#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info{
    int x,y;
    info() {}
    info(int xx, int yy) {
        x = xx; y = yy;
    }
};

int n, st[505], ed[505], sx[505], sy[505], dx[505], dy[505];
vector<int>graph[1100];

int match[1100], vis[1100];
bool findMatch(int u) {

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
//        if(costsVec[u][i] > cost) continue;
        if(!vis[v]) {
            vis[v] = 1;
            if((match[v] == 0 || findMatch(match[v])) ) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for(int i=0; i<n; i++) {
        memset(vis, 0, sizeof(vis));
        if(findMatch(i)) cnt++;
    }
    return cnt;
}


int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) graph[i].clear();
        for(int i=0; i<n; i++) {
            int h,m;
            scanf("%d:%d %d %d %d %d", &h,&m, &sx[i], &sy[i], &dx[i], &dy[i]);
            st[i] = h*60 + m;
            ed[i] = st[i] + abs(sx[i]-dx[i]) + abs(sy[i]-dy[i]);
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(st[j]-(ed[i] + abs(dx[i]-sx[j]) + abs(dy[i]-sy[j])) >= 1) {
//                    edges.pb(info(n+i, j));
                    graph[i].pb(n+j);
                }
            }
        }

        cout << "GRAPH" << endl;
        for(int i=0; i<2*n; i++) {
            cout << i << " : ";
            for(int j=0; j<graph[i].size(); j++) cout << graph[i][j] << ' ' ;
            cout << endl;
        }

        printf("Case %d: %d\n", t, n-bpm());
    }

    return 0;
}

