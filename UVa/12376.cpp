#include <bits/stdc++.h>

using namespace std;

int units[110];
//vector<int> nodes;
int edges[110];

int main() {

    int t, T;
    cin >> T;

    for(t=1; t<=T; t++) {

        memset(edges, -1, sizeof(edges));
        memset(units, 0, sizeof(units));

        int n,m;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> units[i];
        }
        for(int i=0; i<m; i++) {
            int u,v;
            cin >> u >> v;
            if(edges[u] == -1 || units[v] > units[ edges[u] ]) {
                edges[u] = v;
            }
        }
        int temp = 0, maxUnit = 0;
        while(1) {
            maxUnit += units[ temp ];
            if(edges[temp] == -1) break;
            temp = edges[temp];
        }

        //cout << maxUnit << temp << endl;
        printf("Case %d: %d %d\n", t, maxUnit, temp);
    }

    return 0;

}
