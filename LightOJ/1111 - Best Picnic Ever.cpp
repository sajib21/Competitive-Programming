#include<bits/stdc++.h>

using namespace std;

int k,n,m, p,people[105], ans, vis[1005];
vector<int>graph[1005];

void getCount(int root) {

    int tempVis[1005]; memset(tempVis, 0, sizeof(tempVis));

    tempVis[root] = 1;
    queue<int>q;
    vis[root] += 1;
    q.push(root);

    while(!q.empty()) {

        int u = q.front(), sz = graph[u].size();
        q.pop();

        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(!tempVis[v]) {
                vis[v]++;
                tempVis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(vis, 0, sizeof(vis));
        //memset(people, 0, sizeof(people));
        scanf("%d %d %d", &k, &n, &m);
        for(int i=1; i<=n; i++) graph[i].clear();

        for(int i=0; i<k; i++) {
            scanf("%d", &people[i]);
        }
        int u,v;
        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
        }

        ans = 0;
        for(int i=0; i<k; i++) {
            getCount(people[i]);
        }
        for(int i=1; i<=n; i++) if(vis[ i ] == k) ans++;

        //for(int i=1; i<=n; i++) cout << vis[i] << endl;
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
