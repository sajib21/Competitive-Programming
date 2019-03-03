#include<bits/stdc++.h>

using namespace std;

int n;
vector<int>fight[20002], name;
int vis[20002];
int tempCount[3], cnt[3];

void bfs(int rt) {

    tempCount[0] = tempCount[1] = 0;

    queue<int>q;
    q.push(rt);
    vis[rt] = 0;
    tempCount[ vis[rt] ]++;

    while(!q.empty()) {

        int u = q.front();
        q.pop();



        //vis[u] = 1;
        //

        int sz = fight[u].size();
        for(int i=0; i<sz; i++) {
            int v = fight[u][i];
            if(vis[v] == -1) {
                vis[v] = !vis[u];
                //cout << vis[v] << endl;
                tempCount[ vis[v] ]++;
                q.push(v);
            }
        }
    }

    //cout << tempCount[0] << tempCount[1] << endl;

}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(vis, -1, sizeof(vis));
        cnt[0] = cnt[1] = 0;

        scanf("%d", &n);
        int sz = name.size();
        for(int i=0; i<sz; i++) fight[ name[i] ].clear();
        name.clear();

        for(int i=0; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            fight[u].push_back(v);
            fight[v].push_back(u);
            name.push_back(u); name.push_back(v);
        }

        sz = name.size();
        for(int i=0; i<sz; i++) if(vis[ name[i] ] == -1) {
            bfs(name[i]);

            if(cnt[0] > cnt[1]) {
                cnt[0] += max(tempCount[0], tempCount[1]);
                cnt[1] += min(tempCount[0], tempCount[1]);
            }
            else {
                cnt[1] += max(tempCount[0], tempCount[1]);
                cnt[0] += min(tempCount[0], tempCount[1]);
            }
        }

        printf("Case %d: %d\n", t, max(cnt[0], cnt[1]));
    }

    return 0;
}
