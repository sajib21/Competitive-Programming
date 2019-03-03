#include<bits.stdc++.h>

using namespace std;

vector<int>grid[1010];
int dp[3][1010][1010];
int color[1010]={0};

int b,c

bool BFS(int root) {

    queue<int>q;
    q.push(root);
    color[root] = 1;
    int newColor;

    while(!q.empty()) {
        int t = q.top();

        if(color[root] == 1) newColor = 2;
        else newColor = 1;

        int sz = grid[t].size();
        for(int i=0; i<sz; i++) {
            if(!color[grid[t][i]] ) {
                color[grid[t][i]] = newColor;

            }
        }

    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> b >> c >> a;
        for(int i =0; i<a; i++) {
            int u,v;
            cin >> u >> v;
            grid[u].push_back(v);
            grid[v].push_back(u);
        }
        if(BFS(1)) printf("yes\n");
        else printf("no\n");
    }
}
