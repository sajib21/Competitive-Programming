#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n, a[110];
int vis[220], match[220], blocked[220];

int findMatch(int u) {
    for(int v=u+1; v<=n; v++) {
        if( u == v || (a[u]%a[v] && a[v]%a[u]) ) continue;
        int V = v+n;
        if(vis[V] || blocked[V]) continue;
        vis[V] = 1;

        if(!match[V] || findMatch(match[V])) {
            match[V] = u;
            match[u] = V;

            return true;
        }
    }
    return false;
}

int bpm() {
    memset(match, 0, sizeof match);
    int ans = 0;
    for(int i=1; i<=n; i++) {
        memset(vis, 0, sizeof vis);
        if(!blocked[i] && !match[i] && findMatch(i)) {
            ans++;

        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(blocked, 0, sizeof blocked);
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        sort(a, a+n+1);

        int best = bpm();
        vi sol;

        for(int u=n; u>0; u--) {
            blocked[u+n] = blocked[u] = 1;
            int temp = bpm();

            if(temp == best) {
                blocked[u] = blocked[u+n] = 0;
            }
            else {
                best--;
            }
        }

        printf("Case %d:", t);
        for(int i=1; i<=n; i++) if(!blocked[i]) printf(" %d", a[i]);
        printf("\n");
    }
    return 0;
}
