void genSieve() ;

int n,x, num[MAX+10];
int numFlag[LIM+10];
vii Graph[MAX+10];

int match[MAX+10], visl[MAX+10], visr[MAX+10];

bool bfs() {
    int dis = INT_MAX;
    memset(visl, -1, sizeof(visl));
    memset(visr, -1, sizeof(visr));
    queue<int>q;

    for(int i=1; i<=n; i++) {
        if(!match[i]) {
            visl[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        int sz = Graph[u].size();
        if(visl[u] > dis) break;
        for(int i=0; i<sz; i++) {
            int v = Graph[u][i];
            if(visr[v] == -1) {
                visr[v] = visl[u] + 1;
                if(!match[v]) dis = visr[v];
                else {
                    int w = match[v];
                    visl[w] = visr[v] + 1;
                    q.push(w);
                }
            }
        }
    }
    return dis != INT_MAX;
}

bool findMatch(int u) {
    int sz = Graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = Graph[u][i];
        if(visr[v] == visl[u]+1) {
            visr[v] = 0;
            if(!match[v] || findMatch(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bpm() { ///HOPCROFT
    memset(match, 0, sizeof(match));
    int ans = 0;
    while(bfs()) {
        for(int i=1; i<=n; i++) {
            if(!match[i] && findMatch(i)) ans++;
        }
    }
    return ans;
}
