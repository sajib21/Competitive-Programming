///MATRIX LIBRARY HERE

int n, ara[7], x, cnt=0;
map<int, int> mp, mp2;
vii graph[40];
matrix co;

void genMap(int mask, int in, int taken) {
    if(mp[mask]) return;
    if(taken == 4) {
        mp[mask] = ++cnt;
        mp2[cnt] = mask;
    }
    if(in == 7) return;

    genMap(setBit(mask, in), in+1, taken+1);
    genMap(mask, in+1, taken);
}

int vis[1050][40];

void genMat(int vmask, int u, int i, int pos[4]) {
    if(vis[vmask][u]) return;
    vis[vmask][u] = 1;
    if(i == 4) {
        int v = mp[vmask];
        co.mat[u][v] = co.mat[v][u] = 1;
        return;
    }
    int p = pos[i];
    if(p-1 >= 0 && !chkBit(vmask, p-1)) genMat(setBit(vmask, p-1), u, i+1, pos);
    if(p+1 < 7 && !chkBit(vmask, p+1)) genMat(setBit(vmask, p+1), u, i+1, pos);
}

int main() {
    co = matrix(0);
    genMap(0, 0, 0);
    for(int i=1; i<=35; i++) {
        int pos[4], p=0, umask = mp2[i];
        for(int i=0; i<7; i++) {
            int x = umask % 2;
            umask /= 2;
            if(x) {
                pos[p++] = i;
            }
        }
        genMat(0, i, 0, pos);
    }

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int mask = 0, u;
        scanf("%d", &n); n--;
        matrix temp = matBigMod(co, n);
        for(int i=0; i<7; i++) {
            scanf("%d", &x);
            if(x) mask = mask*2 + 1;
            else mask = mask*2;
        }
        ll p=mp[mask], ans = 0;
        for(int i=1; i<=matCol; i++) ans = (ans + temp.mat[p][i]) % MOD;
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}

