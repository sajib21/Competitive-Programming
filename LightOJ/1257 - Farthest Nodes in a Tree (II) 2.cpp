#include<bits/stdc++.h>
#define MX 30004
using namespace std;

int n;
vector<int>graph[MX], cost[MX];
//int pre[MX];
int dp[MX], preDp[MX];
int dp2[MX], preDp2[MX];

int getMax(int u, int pre) {

    if(dp[u] != -1 && preDp[u] != pre && pre != -1) {
        return dp[u];
    }
    else if(dp2[u] != -1 && preDp2[u] != pre && pre != -1) return dp2[u];

    int sz = graph[u].size();
    int ansDp = -1, ansPreDp=-1;
    int ansDp2= -1, ansPre2 = -1;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];


        if(pre != v) {
            int temp = cost[u][i] + max(0,getMax(v, u) );
            if(temp > ansDp) {

                ansDp2 = ansDp;
                ansPre2 = ansPreDp;

                ansDp = temp;
                ansPreDp = v;
            }
            else if(temp > ansDp2) {
                ansDp2 = temp;
                ansPre2 = v;
            }
        }
    }

    dp[u] = ansDp; preDp[u] = ansPreDp;
    dp2[u] = ansDp2; preDp2[u] = ansPre2;

    return dp[u];

//    else return ansDp;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        scanf("%d", &n);

//        memset(pre, -1, sizeof(pre));
        memset(dp, -1, sizeof(dp));
        memset(preDp, -1, sizeof(preDp));
        memset(dp2, -1, sizeof(dp2));
        memset(preDp2, 01, sizeof(preDp2));


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

        }

    }

    return 0;
}
