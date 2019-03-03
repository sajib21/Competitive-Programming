#include<bits/stdc++.h>
#define MX 30004
using namespace std;

int n;
vector<int>graph[MX], cost[MX];
//int pre[MX];
int dp[MX], preDp[MX];

int getMax(int u, int pre) {

    if(dp[u] != -1 && preDp[u] != pre && pre != -1) {
//        cout << u << ' ' << preDp[u] << ' ' << pre << endl;
        return dp[u];
    }

    int sz = graph[u].size();
    int ansDp = 0, ansPreDp=-1;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];


        if(pre != v) {
            int temp = cost[u][i] + getMax(v, u);
            if(temp > ansDp) {
                ansDp = temp;
                ansPreDp = v;
            }
        }
    }
    if(ansDp > dp[u]) {
        dp[u] = ansDp; preDp[u] = ansPreDp;
        return dp[u];
    }
    else return ansDp;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        scanf("%d", &n);

//        memset(pre, -1, sizeof(pre));
        memset(dp, -1, sizeof(dp));
        memset(preDp, -1, sizeof(preDp));
        for(int i=0; i<n; i++) graph[i].clear(), cost[i].clear();

        for(int i=1; i<n; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        printf("Case %d:\n", t);
        for(int i=0; i<n; i++) {
            printf("%d\n", getMax(i, -1));
//            cout << dp[i] << ' ' << preDp[i] << endl;
//            cout << dp[i+1] << ' ' << preDp[i+1] << endl;
//            cout << "OUT " <<  preDp[2] << ' ' << preDp[2] << endl;
//            cout << "OK" << endl;
        }

    }

    return 0;
}
