#include<bits/stdc++.h>

using namespace std;

int setBit(int mask, int p) { return mask | (1<<p); }
int chkBit(int mask, int p) { return mask & (1<<p); }

int n,m, k,x, jalao[60];
int keys[50000];
char qry[20];

void bfs() {
    memset(keys, -1, sizeof keys);
    queue<int>q;
    q.push(0);
    keys[0] = 0;

    while(!q.empty()) {
        int umask = q.front(); q.pop();

        for(int i=0; i<m; i++) {
            int vmask = umask ^ jalao[i];
            if(keys[vmask] != -1) continue;
            keys[vmask] = keys[umask] + 1;
            q.push(vmask);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++) {
            jalao[i] = 0;
            scanf("%d", &k);
            for(int j=0; j<k; j++) {
                scanf("%d", &x);
                jalao[i] = setBit(jalao[i], x);
            }
        }
        bfs();

        int q;
        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {
            scanf("%s", qry);
            int qmask = 0;
            for(int i=0; i<n; i++) if(qry[i] == '1') qmask = setBit(qmask, n-i-1);
            printf("%d\n", keys[qmask]);
        }
        printf("\n");
    }
}
/*
2
3 3
3 0 1 2
2 1 2
1 2
3
101
010
111
*/
