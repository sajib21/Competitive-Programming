#include<bits/stdc++.h>
#define MXX 300005
#define MXZ 16000

using namespace std;

char seq[MXX];
int x,idx = 1, idy[2] , idz[2] , roots[2][22], sz[2][22], pos[MXX], trie[MXX][30];
int cnt[MXX], vis[MXX], val[MXX], fail[MXX];

void genFail(int root);

void add(string str, int op) { ///add + genFail ; op = 0 means add, 1 means del
    if(sz[op][ idy[op] ] > MXZ) {
        genFail(roots[op][ idy[op] ]);
        roots[op][ ++idy[op] ] = ++idx;
    }
    int u = roots[op][ idy[op] ]; fail[u] = u;
    //cout << "STRING " << u << endl;
    for(int i=0; i<str.size(); i++) {
        int p = str[i]-'a';
        if(trie[u][p] == -1) trie[u][p] = ++idx, sz[op][ idy[op] ]++;
        int v = trie[u][p];
        //cout << v << endl;
        fail[v] = roots[op][ idy[op] ];
        u = v;
    }
    cnt[u]++;
    vis[ roots[op][ idy[op] ] ] = 0;
}

//int calc(int u, int root) {
//    cout << u << ' ' << root << endl; getchar();
//    if(u == root) return 0;
////    if(vis[u]) return val[u];
////    vis[u] = 1;
//    return val[u] += cnt[u] + calc(fail[u], root);
//}

void genFail(int root) {
    //cout << "GEN ROOT " << root << endl;
    queue<int>q;
    q.push(root);
    while(!q.empty()) {
        int u = q.front();
        q.pop();

//        cout << u << ' ' << fail[u] << ' ' << val[u] << endl;

        for(int p=0; p<26; p++) {
            int v = trie[u][p];
            if(v == -1) continue;
            q.push(v);
            val[v] = cnt[v];
            int temp = u;
            while(temp != root) {
                temp = fail[temp];
                if(trie[temp][p] != -1) {
                    fail[v] = trie[temp][p];
                    val[v] += val[ fail[v] ];
                    break;
                }
            }
        }
    }
    vis[root] = 1;
//    for(int i=0; i<=idx; i++) calc(i, root);
}

int query(string str, int root) { //cout << "QUERY " << root << endl;
    int u = root, ans = 0;
    for(int i=0; i<str.size(); i++) {
        int p = str[i] - 'a';
        while(u != root && trie[u][p] == -1) u = fail[u];
        if(trie[u][p] == -1) {
            u = root;
            continue;
        }

        int v = trie[u][p];
        ans += val[v];

        //cout << v << endl;
//        int temp = v;
//        while(temp != root) {
//            ans += cnt[temp];
//            temp = fail[temp];
//        }
        u = v;
    }
    return ans;
}

int main() {
    int t;
    memset(trie, -1, sizeof trie);
    roots[0][0] = 0; roots[1][0] = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %s", &x, seq);
        if(x == 1) add(seq, 0);
        else if(x == 2) add(seq, 1);
        else {
            if(!vis[ roots[0][ idy[0] ] ]) genFail(roots[0][ idy[0] ]);
            if(!vis[ roots[1][ idy[1] ] ]) genFail(roots[1][ idy[1] ]);
            int ans = 0;
            for(int i=0; i<=idy[0]; i++) ans += query(seq, roots[0][i]); //cout << ans << endl;
            for(int i=0; i<=idy[1]; i++) ans -= query(seq, roots[1][i]);
            printf("%d\n", ans);
            fflush(stdout);
        }
    }
//    main();
}
