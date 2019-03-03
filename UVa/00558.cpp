#include<bits/stdc++.h>

using namespace std;


int main() {
    long long c;
    cin >> c;
    while(c--) {

        long long n,m,key[1010];
        bool flag = false;
        //graph.clear(); cost.clear();
        vector<int> graph[1010], cost[1010];

        cin >> n >> m;

        for(int i=0; i<m; i++) {
            long long u,v,c;
            scanf("%lld %lld %lld", &u,&v,&c);
            graph[u].push_back(v);
            cost[u].push_back(c);
        }

        for(int i=0; i<n; i++) key[i] = INT_MAX;

        for(int t=1; t<n; t++) { //n-1 times visiting

            for(int u=0; u<n; u++) {
                int sz = graph[u].size();
                for(int i=0; i<sz; i++) {
                    int v = graph[u][i];
                    if(key[u]+cost[u][i] < key[v]) {
                        key[v] = key[u]+cost[u][i];
                    }
                }
            }
        }

        //cout << key[0] << ' ' << key[1] << " debug" << endl;

        for(int u=0; u<n; u++) {
            int sz = graph[u].size();
            for(int i=0; i<sz; i++) {
                int v = graph[u][i];
                if(key[u]+cost[u][i] < key[v]) {
                    //key[v] = key[u]+cost[u][i];
                    printf("possible\n");
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) printf("not possible\n");
    }

    return 0;
}
