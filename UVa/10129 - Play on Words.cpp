#include<bits/stdc++.h>
#define pb push_back
#define LIM 100000

using namespace std;

int n;
char str[1010];
vector<int>graph[LIM+100];
int vis[50], in[50], ot[50];

int dfs(int u) {
    vis[u] = 1;
    int ans = 0;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if(!vis[v]) ans += dfs(v);
        ans++;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(graph, NULL, sizeof graph);
        memset(vis, 0, sizeof vis);
        memset(in, 0, sizeof in);
        memset(ot, 0, sizeof ot);
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%s", str);
            int sz = strlen(str);
            int u,v;
            u = str[0] - 'a';
            v = str[sz-1] - 'a';
            graph[u].pb(v);
            ot[u]++; in[v]++;
        }
        int cnt = 0;
        for(int u=0; u<='z'-'a'; u++) if(ot[u] &&  abs(in[u]-ot[u]) == 1) {
            cnt += dfs(u);
//            cout << u << " A " << cnt << endl;
            break;
        }

        if(cnt == 0) {
            for(int u=0; u<='z'-'a'; u++) if(ot[u] && abs(in[u]-ot[u]) == 0) {
                cnt += dfs(u);
//                cout << u << " B " << cnt << endl;
                break;
            }
        }

        if(cnt != n) {
            printf("The door cannot be opened.\n");
            continue;
        }
        cnt = 0;
        for(int u=0; u<='z'-'a' && cnt <= 2; u++) {
            if(abs(in[u]-ot[u]) > 1 ) cnt = 5;
            else if(abs(in[u]-ot[u]) == 1) cnt++;
        }

        if(cnt > 2) printf("The door cannot be opened.\n");
        else printf("Ordering is possible.\n");
    }
    return 0;
}
