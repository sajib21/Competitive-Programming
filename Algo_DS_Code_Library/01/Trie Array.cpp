#include<bits/stdc++.h>

using namespace std;

int idx, mxx = 0;
struct node {
    int val, nxt[10];
    node() {
        val = 0;
        for(int i=0; i<10; i++) nxt[i] = -1;
    }
} trie[400000];

int add(string s, int val=-1) {
    int cur = 0;
    for(int i=0; i<8; i++) {
        int d = s[i] - '0';
        if(trie[cur].nxt[d] == -1) trie[cur].nxt[d] = ++idx;
        cur = trie[cur].nxt[d];
    }
//    mxx = max(idx, mxx);
//    trie[cur].val = val;
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
