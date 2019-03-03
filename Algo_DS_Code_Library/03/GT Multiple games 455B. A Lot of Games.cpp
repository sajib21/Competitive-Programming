///move: add character in last so that string is a prefix of
///any given string
///play k times and last winner is ultimate winner


#include<bits/stdc++.h>
#define LIM 100005
#define OP 28
using namespace std;

int idx, mxx = 0;
struct node {
    int val, nxt[OP];
    node() {
        val = 0;
        for(int i=0; i<OP; i++) nxt[i] = -1;
    }
} trie[LIM];
bool win[LIM], lose[LIM];

int add(string s) {
    int cur = 0;
    for(int i=0; i<s.size(); i++) {
        int d = s[i] - 'a';
        if(trie[cur].nxt[d] == -1) trie[cur].nxt[d] = ++idx;
        cur = trie[cur].nxt[d];
        win[cur] = lose[cur] = false;
    }
    win[cur] = false;
    lose[cur] = true;
    return cur;
}

int chk(string s) {
    int cur = 0;
    for(int i=0; i<8; i++) {
        int d = s[i] - '0';
        cur = trie[cur].nxt[d];
    }
    return cur;
}

void del(int cur) {

    for(int i=0; i<10; i++) {
        if(trie[cur].nxt[i] != -1) {
            del(trie[cur].nxt[i]);
        }
    }
    trie[cur] = node();
}

int n,k;

bool dfs(int u) {
//    cout << "DFS IN " << u << ' ' << win[u] << ' ' << lose[u] << endl; getchar();
    for(int i=0; i<OP; i++) {
        int v = trie[u].nxt[i];
        if(v == -1) continue;
        dfs(v);
        if(!win[v]) win[u] = true;
        if(!lose[v]) lose[u] = true;

//         if(k&1) win[u] = true;
//        else lose[u] = true;
    }
//    cout << "DFS OUT " << u << ' ' << win[u] << ' ' << lose[u] << endl; getchar();
    return win[u];
}

int main() {
    idx = 0;
    memset(trie, -1, sizeof trie);
    scanf("%d %d", &n,&k);
    while(n--) {
        string s;
        cin >> s;
        add(s);
    }

    dfs(0);


    if(win[0] && lose[0]) printf("First\n");
    else if(win[0] && k%2==1) printf("First\n");
    else printf("Second\n");

//    for(int i=0; i<=idx; i++) cout  << i << ' ' << win[i] << ' ' << lose[i] << endl;

}
