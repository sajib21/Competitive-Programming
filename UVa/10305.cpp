#include <bits/stdc++.h>

using namespace std;



int main() {
    int n,m;

    while(cin >> n >> m) {
        if(!n && !m) return 0;

        int degree[110]={0};
vector<int> graph[110]; //map e <int,int> hoy
queue<int> emptyGraph;

        int u,v;
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            degree[v]++;
            graph[u].push_back(v);
        }
        for(int i=1; i<=n; i++) if(!degree[i])
            emptyGraph.push(i);

        int flag = 0;

        while(!emptyGraph.empty()) {
            int top = emptyGraph.front();
            emptyGraph.pop();
            if(!flag) {
                cout << top;
                flag = 1;
            }
            else cout << ' ' << top;
            for(int i=0; i<graph[top].size(); i++) {
                degree[ graph[top][i] ]--;
                if(!degree[ graph[top][i] ]) emptyGraph.push(graph[top][i]);
            }
        }
//
//
//        printf("!\t %d", graph[0].first);
//
//        for(int i=1; i<n; i++) {
//            //cout >> graph[i].first >> ' ';
//            printf(" %d", graph[i].first) ;
//        }
        putchar('\n');

    }

    return 0;
}
