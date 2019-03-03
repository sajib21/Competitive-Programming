#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

int n, m;
vector<int> graph[100005], transpose[100005];
int cost[100005], color[100005], tim = 0;
stack<int>finWise;
int minCost, minCostCount;
ll ans1 = 0, ans2 = 1;

void dfs1(int u) {

    color[u] = 1;
    //tim++;

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!color[v]) {
            dfs1(v);
        }
    }

    finWise.push(u);
}

void dfs2(int u) {

    color[u] = 2;
    if(cost[u] < minCost) {
        minCost = cost[u];
        minCostCount = 1;
    }
    else if(cost[u] == minCost) minCostCount++;

    int sz = transpose[u].size();
    for(int i=0; i<sz; i++) {
        int v = transpose[u][i];
        if(color[v] == 1) {
            dfs2(v);
        }
    }
}

int main() {

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &cost[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        transpose[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(!color[i]) {
            dfs1(i);
        }
    }

    while(!finWise.empty()) {
        int u = finWise.top();
        finWise.pop();

        if(color[u] == 1) {
            minCost = INT_MAX;
            minCostCount = 0;
            dfs2(u);
            ans1 += minCost;
            ans2 = (ans2 * minCostCount) % MOD;
        }
    }

    cout << ans1 << ' ' << ans2 << endl;

    return 0;
}
