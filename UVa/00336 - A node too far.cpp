#include <bits/stdc++.h>
#include <set>

using namespace std;

int main()
{
    int n, test=1;
    while(scanf("%d", &n) && n) {
        vector<int>graph[100000];
        set<int>nodes;

        for(int i=0; i<n; i++)
        {
            int u,v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }

        int qn, ttl;
        while(scanf("%d %d", &qn, &ttl) && (qn || ttl) ) {

            if(!graph[qn].size()) {
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", test++, nodes.size(), qn, ttl);
                continue;
            }
            else if(!ttl) {
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", test++, nodes.size()-1, qn, ttl);
                continue;
            }

            int can=0;
            queue<int>q;

            int vis[100000] = {0};
            int lev[100000] = {0};
            memset(vis, -1, sizeof(vis));
            vis[qn] = 0;

            q.push(qn);

            while(!q.empty()) {
                int top = q.front(); q.pop();
                int s = graph[top].size();

                if(vis[top] == ttl) break;
                for(int i=0; i<s; i++)
                    if(vis[graph[top][i]] == -1) {
                        q.push(graph[top][i]);
                        vis[graph[top][i]] = vis[top]+1;
                        can++;
                    }
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", test++, nodes.size() - can - 1, qn, ttl);

        }
    }

    return 0;
}
