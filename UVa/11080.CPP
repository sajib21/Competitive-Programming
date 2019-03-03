#include <bits/stdc++.h>
#define bug cout << "bug found" << endl;
using namespace std;

vector<int>graph[202];
int level[202], color[202];
int tempGuardsOdd, tempGuardsEven;


bool bfs(int root) {

    color[root] = 1;
    level[root] = 0;

    tempGuardsOdd = 0, tempGuardsEven = 0;

    tempGuardsEven++;
    queue<int>q;
    q.push(root);

    while(!q.empty()) {

        int u = q.front();
        q.pop();
        int sz = graph[u].size();
        //if(!sz) level[u] = 1;
        int cnt = 0, v;
        for(int i=0; i<sz; i++) {
            v = graph[u][i];
            if(!color[v])  {
                color[v] = 1;
                level[v] = level[u] + 1;
                cnt++;
                q.push(v);
            }
            else if(color[v] && level[u] == level[v]) {
                return false;
            }
        }
        if(level[v]%2) tempGuardsOdd += cnt;
        else tempGuardsEven += cnt;
    }
    return true;
}

int main() {



    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n,m;
        bool isPossible;
        cin >> n >> m;

        for(int i=0; i<=n; i++) graph[i].clear();

        for(int i=0; i<m; i++) {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(!m) {
            cout << n << endl;
            continue;
        }

        memset(level, 0, sizeof(level));
        memset(color, 0, sizeof(color));

        int guards = 0;

        for(int i=0; i<n; i++) {
            if(!color[i]) {

                if(graph[i].size()) isPossible = bfs(i);
                if(!isPossible) {
                    break;
                }

                if(!graph[i].size()) guards++;
                else guards += min(tempGuardsEven, tempGuardsOdd);
            }
        }

        if(!isPossible) {
            cout << "-1" << endl;
            continue;
        }


        cout << guards << endl;

        //bug

    }

    return 0;
}
