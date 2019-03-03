#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {

        int n,m, u,v;
        vector<int>graph[100005];

        cin >> n >> m;
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            graph[v].push_back(u);
        }

        int temp=0;

        for(int i=1; i<=n; i++)
            if(!graph[i].size())
                temp++;

        if(temp) cout << temp << endl;
        else cout << 1 << endl;
    }

    return 0;
}
