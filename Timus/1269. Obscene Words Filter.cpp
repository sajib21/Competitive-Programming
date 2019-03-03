#include<bits/stdc++.h>
#define MAX 200000
#define OPT 256
#define pb push_back

using namespace std;

//int OPT = 128;

struct node { ///val: count/result : num of occur of this prefix in text ;
        /// nxt: nxt of trie ; fail: failure func / suffix of aho
        /// cnt : cnt of occur of this prefix in patterns
    int val, nxt[OPT], fail, cnt;
    node() { val = fail = cnt = 0; memset(nxt, 0, sizeof nxt); }
    node(int cc, int ff, int vv) { cnt = cc; fail = ff; val = vv; }
};



int n, idx=0;
//node trie[MAX+100];
vector<node>trie;
int posInBase[MAX+100];
//int sizInBase[MAX+100];

void add(string s, int in) {
    int cur = 0;
    for(int i=0; i<s.size(); i++) {
        int p = s[i];
        if(trie[cur].nxt[ p ] == 0) {
            trie[cur].nxt[ p ] = ++idx;
            trie.pb(node());
//            trie[idx] = node();
        }
        cur = trie[cur].nxt[ p ];
    }
    trie[cur].cnt++;
    if(!posInBase[cur]) posInBase[cur] = s.size();
//    sizInBase[in] =
}

void genFail() {
    int cur = 0;
    queue<int>q;
    q.push(cur);

    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for(int p=0; p<OPT; p++) {
            if(trie[cur].nxt[p] != 0) {
                q.push(trie[cur].nxt[p]);
                int temp = cur;

                while(temp != 0) {
                    int f = trie[temp].fail;
                    if( trie[f].nxt[p] != 0 ) {
                        trie[ trie[cur].nxt[p] ].fail = trie[f].nxt[p];
                        break;
                    }
                    else temp = f;
                }
                if(temp == 0) trie[ trie[cur].nxt[p] ].fail = 0;
            }
        }
    }
}

bool checker(string text, int in) {
    int sz = text.size();
    int cur = 0;

    vector<int>ans;

    for(int i=0; i<sz; i++) {
        int p = text[i];
        while(cur != 0 && trie[cur].nxt[ p ] == 0) cur = trie[cur].fail;
        if(trie[cur].nxt[ p ] != 0) {
            cur = trie[cur].nxt[p];
            int temp = cur;
            while(temp != 0) {
                if(trie[temp].cnt) {
                    ans.pb(i-posInBase[temp]+1 + 1);
                }
                trie[temp].val++;
                temp = trie[temp].fail;
            }
        }
    }

    if(ans.size()) {
        sort(ans.begin(), ans.end());
//        for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ' ; cout << endl;
        printf("%d %d\n", in+1, ans[0]);
        return true;
    }
    return false;
}
char str[1001000];

int main() {
//    cout << string("str ing").size() << endl;
    trie.push_back(node());

    scanf("%d", &n); getchar();

    string s;
    for(int i=0; i<n; i++) {
        gets(str);
        puts(str);
        cout << "SIZE " << strlen(str) << endl;
        add(str, i);
    }

    idx = 0;

    genFail();
    int m;
    scanf("%d", &m);
    getchar();
//    scanf("%")
    bool f = false;
    for(int i=0; i<m; i++) {
        gets(str);
        if(!f) f |= checker(str, i);
    }

    if(!f) printf("Passed\n");
    return 0;

    return 0;
}

