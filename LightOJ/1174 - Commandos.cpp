#include<bits/stdc++.h>

using namespace std;

vector<int>graph[100];
int n,m;
int key1[111], key2[111];
int s,d;

void maxLevel(int us, int key[]) {

    memset(key, 0, sizeof(key));

    queue<int>q;

    key[us] = 0;
    q.push(us);

    //int ml = 0;

    while(!q.empty()) {

        int u = q.front();
        q.pop();
        int sz = graph[u].size();

        for(int i=0; i<sz; i++) {

            int v = graph[u][i];
            if(!key[v] && v != us) {
                key[v] = key[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {

    int t,T;
    cin >> T;
    for(t=1; t<=T; t++) {


        cin >> n >> m;

        for(int i=0; i<n; i++) graph[i].clear();
        memset(key1, 0, sizeof(key1));
        memset(key2, 0, sizeof(key2));


        for(int i=0; i<m; i++)
        {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cin >> s >> d;

        maxLevel(s, key1);
        maxLevel(d, key2);

        int ml = 0;
        for(int i=0; i<n; i++) {
            ml = max(ml, key1[i]+key2[i]);
            //cout << "dekhi " << i << key1[i] << " " << key2[i] << endl;
        }

        printf("Case %d: %d\n", t, ml);

    }

    return 0;

}
