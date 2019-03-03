#include <bits/stdc++.h>

using namespace std;

vector<int>graph[100005];
int flag[100005];
int color[100005];

int result;

int DFS(int node) {

    if(flag[node]) {
        result--;
        return 1;
    } //age hoise naki
    if(!color[node]) {

        if( !graph[node].size() ) {
            color[node] = 1;
            return 1;
        }

        int temp = 0;
        for(int i=0; i<graph[node].size(); i++ ) {
            temp = temp | DFS(graph[node][i]);
        }
        color[node] = 1;
        return temp;
    }
    else return 1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {

        int n,m, u,v;
        memset(color, 0, sizeof(color));
        memset(flag, 0, sizeof(flag));

        cin >> n >> m;
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
        }

        result = 0;
        for(int i=1; i<=n; i++) {
            if(!color[i]) {
                //flag[i] = 1;
                result += DFS(i);

                for(int q=1; q<=n; q++) cout << '\t' << color[q];
                cout << '.' << endl;
                cout << "result " << i << '\t' << result << endl << endl;
                flag[i] = 1;
            }
        }
//        for(int i=1; i<=n; i++) cout << '\t' << color[i];
//        putchar('\n');

        cout << result << endl;
    }
}
