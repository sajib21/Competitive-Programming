/*
Between conflicting voters, there can be only one who will satisfy. So have edge between them and get BPM
*/
int m,f,v;
string in[505], ex[505];
vii graph[505];

int match[505], vis[505];
bool findMatch(int u) {
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            vis[v] = 1;
            if((match[v] == 0 || findMatch(match[v])) ) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for(int i=1; i<=v; i++) {
        memset(vis, 0, sizeof(vis));
        if(!match[i] && findMatch(i)) cnt++;
    }
    return cnt ;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &m,&f,&v);
        for(int i=1; i<=v; i++) graph[i].clear();
        for(int i=1; i<=v; i++) cin >> in[i] >> ex[i];
        for(int i=1; i<=v; i++) {
            for(int j=i+1; j<=v; j++) {
                if(in[i] == ex[j] || in[j] == ex[i]) {
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
            }
        }
        printf("Case %d: %d\n", t, v-bpm());
    }
    return 0;
}
