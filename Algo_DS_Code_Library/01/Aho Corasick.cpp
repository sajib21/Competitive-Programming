#include<bits/stdc++.h>
#define MAX 2000006
#define LIM 2000006

using namespace std;

struct node { ///val: count/result : num of occur of this prefix in text ;
        /// nxt: nxt of trie ; fail: failure func / suffix of aho
        /// cnt : cnt of occur of this prefix in patterns
    int val, nxt[28], fail, cnt, par;
    node() { val = fail = cnt = par = 0 ; memset(nxt, 0, sizeof nxt); }
    node(int cc, int ff, int vv) { cnt = cc; fail = ff; val = vv; }
};

int idx=0;
node trie[MAX+100];
int posInBase[LIM+100];
char seq[1010];

void add(string s, int in) {
    int cur = 0;
    for(int i=0; i<s.size(); i++) {
        int p = s[i]-'a'+1;
        if(trie[cur].nxt[ p ] == 0) {
            trie[cur].nxt[ p ] = ++idx;
            trie[idx] = node();
        }
        int pp = cur;
        cur = trie[cur].nxt[ p ];
        trie[cur].par = pp;
    }
    trie[cur].cnt++;
    posInBase[in] = cur;
}

void genFail() {
    int cur = 0;
    queue<int>q;
    q.push(cur);

    while(!q.empty()) {
        cur = q.front();
        q.pop();

//        trie[cur].all += trie[cur].cnt;

        for(int p=1; p<=26; p++) {
            if(trie[cur].nxt[p] != 0) {
                q.push(trie[cur].nxt[p]);

                int nxt = trie[cur].nxt[p];
//                trie[nxt].all += trie[cur].all;

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

int dp[LIM];

int f(int u) {
    if(!u) return 0;
    if(dp[u] != -1) return dp[u];

    return dp[u] = trie[u].cnt + max(f(trie[u].par) , f(trie[u].fail));
}

int main() {
    string patterns[] = {"his", "hers", "is", "s", "him", "she", "her"};
    string text = "hishersherimhim";

    int n;
    while(scanf("%d", &n) && n) {
        idx = 0;
        memset(trie, 0, sizeof trie);
        memset(dp, -1, sizeof dp);

        for(int i=0; i<n; i++) {

            scanf("%s", seq);
            add(seq, i);
        }

        genFail();


//        for(int i=0; i<=idx; i++) cout << "D " << i << ' ' << trie[i].cnt << ' ' << trie[i].all << ' ' << trie[i].fail << endl;

        int ans = 0;
        for(int i=1; i<=idx; i++) ans = max(ans, f(i) );

        printf("%d\n", ans);

    }

    return 0;
}
