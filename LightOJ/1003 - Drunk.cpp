#include<bits/stdc++.h>

using namespace std;

map<string, int> mp;
vector<int>graph[10010];
int color[10010], tim, dis[10010], fin[10010];
bool cycle;

void cycleDetect(int u) {

    color[u] = 1;
    dis[u] = ++tim;

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(color[v] == 0) {
            cycleDetect(v);
        }
        else if(color[v] == 1) {
            cycle = true;
            //cout << u << ' ' << v << endl;
        }
        if(cycle == true) break;
    }

    color[u] = 2;
    fin[u] = ++tim;
}

int main() {

    int T, t;
    scanf("%d", &T);

    for(t=1; t<=T; t++ ) {

        mp.clear();
        //for(int i=0; i<)
        memset(color, 0, sizeof(color));
        memset(dis, 0, sizeof(dis));
        memset(fin, 0, sizeof(fin));
        tim = 0;

        int m, n=0;
        cycle = false;
        scanf("%d", &m);

        for(int i=0; i<m; i++) {
            string s1, s2;
            //scanf("%s %s", &s1, &s2);
            cin >> s1 >> s2;

            if(!mp[s1]) {
                mp[s1] = n++;
            }
            if(!mp[s2]) {
                mp[s2] = n++;
            }

            int u = mp[s1], v = mp[s2];

            graph[u].push_back(v);
        }

        for(int i=0; i<n; i++) {
            if(!color[i]) {
                cycleDetect(i);
                if(cycle) break;
            }
        }

        if(cycle) printf("Case %d: No\n", t);
        else printf("Case %d: Yes\n", t);

        for(int i=0; i<=n; i++) graph[i].clear();

    }

    return 0;

}
