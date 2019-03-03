///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}


using namespace std;

struct node { ///val is the count/result : number of occurance of this prefix in text ;
              /// nxt is nxt of trie ; fail : failure function / suffix of aho
              /// cnt : count of occurance of this prefix in patterns
    int val, nxt[28], fail, cnt;
    node() { val = fail = cnt = 0; memset(nxt, -1, sizeof nxt); }
    node(int cc, int ff, int vv) { cnt = cc; fail = ff; val = vv; }
};

int idx=0;
node trie[10000009];
int posInBase[1005];

void add(string s, int in) {
    int cur = 0;
    int sz = s.size();
    for(int i=0; i<sz; i++) {
        int p = s[i]-'a'+1;
        if(trie[cur].nxt[ p ] == -1) {
            trie[cur].nxt[ p ] = ++idx;
            trie[idx] = node();
        }
        cur = trie[cur].nxt[ p ];
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
        for(int p=1; p<=26; p++) {
            if(trie[cur].nxt[p] != -1) {
                q.push(trie[cur].nxt[p]);
                int temp = cur;

                while(temp != 0) {
                    int f = trie[temp].fail;
                    if( trie[f].nxt[p] != -1 ) {
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

void checker(string text) {
    int sz = text.size();
    int cur = 0;

    for(int i=0; i<sz; i++) {
        int p = text[i] - 'a' + 1;

        while(cur != 0 && trie[cur].nxt[ p ] == -1) cur = trie[cur].fail;

        if(trie[cur].nxt[ p ] != -1) {
            cur = trie[cur].nxt[p];
            int temp = cur;
            while(temp != 0) {
                trie[temp].val++;
                temp = trie[temp].fail;
            }
        }
    }
}

void deleteTrie(int cur) {
    for(int i=1; i<=26; i++) if(trie[cur].nxt[i] != -1) deleteTrie(trie[cur].nxt[i]);
    trie[cur] = node();
}

string pat, text;

//#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

char ch[1005], chb[100006];

int main() {

//    freopen("1427i.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        //memset(trie, -1, sizeof trie);
        idx = 0;
        int n;
        scanf("%s", &chb);
        scanf("%d", &n);

        text = chb;

        for(int i=0; i<n; i++) {
            scanf("%s", &ch);
            pat = ch;
            add(pat, i);
        }
        genFail();
        checker(text);

//        printf("Case %d:\n", t);

        for(int i=0; i<n; i++) {
            int id = posInBase[i];
            if(trie[id].val) printf("y\n");
            else printf("n\n");
        }
        deleteTrie(0);
    }

    return 0;
}
