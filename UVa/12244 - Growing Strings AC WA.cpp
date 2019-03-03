///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             1000000
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
    int val, nxt[28], fail, cnt, rem;
    node() { val = fail = cnt = rem = 0; memset(nxt, 0, sizeof nxt); }
//    node(int cc, int ff, int vv) { cnt = cc; fail = ff; val = vv; }
};

int idx=0;
node trie[LIM+100];
int posInBase[LIM+100];
int par[LIM+10];
string pat[10004]; char str[1003];

void add(string s, int in) {
    int cur = 0;
    for(int i=0; i<s.size(); i++) {
        int p = s[i]-'a';
        if(trie[cur].nxt[ p ] == 0) {
            trie[cur].nxt[ p ] = ++idx;
            trie[idx] = node();
        }
        int t = cur;
        cur = trie[cur].nxt[ p ];
        par[cur] = t;
    }
    trie[cur].cnt++;
    trie[cur].val++;
    trie[cur].rem++;
    posInBase[in] = cur;
}

int dfs(int u) {
    int ans = 0;
    for(int i=0; i<26; i++) {
        int v = trie[u].nxt[i]; if(!v) continue;
        ans = max(ans, dfs(v));
    }
    trie[u].cnt += ans;
    return trie[u].cnt;
}

int genFail() {
    int cur = 0;

    dfs(0);
    trie[0].cnt = trie[0].val = 0;

    queue<int>bq;
    bq.push(cur);

//    while(!bq.empty()) {
//        cur = bq.front();
//        bq.pop();
//        for(int p=0; p<26; p++) {
//            int t = trie[cur].nxt[p];
//            if(!t) continue;
//            trie[t].val += trie[cur].val;
//            bq.push(t);
//        }
//    }

//    for(int i=0; i<=18; i++) cout << i << ' ' << trie[i].cnt << endl;

    cur = 0;
    queue<int>q;
    q.push(cur);
    int ans = 0;

    while(!q.empty()) {
        cur = q.front();
        q.pop();

        int f = trie[cur].fail, p = par[cur];

        cout << cur << ' ' << trie[cur].cnt << ' ' << f << ' ' << trie[f].val << ' ' << p << ' ' << trie[p].val << endl; getchar();

        trie[cur].val = max( trie[f].val+trie[cur].cnt , trie[p].val );
//        trie[cur].cnt += trie[f].cnt;
        ans = max(ans, trie[cur].val);

        for(int p=0; p<26; p++) {
            if(trie[cur].nxt[p] != 0) {
                int t = trie[cur].nxt[p];

                q.push(t);
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
    return ans;
}

int n;

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        scanf("%d", &n);
        if(!n) return 0;
        for(int i=0; i<=idx; i++) trie[i] = node();

        idx = 0;
        for(int i=0; i<n; i++) {
            scanf("%s", str);
            pat[i] = str;
        }
        for(int i=0; i<n; i++) {
            add(pat[i], i);
        }
        printf("%d\n", genFail());
    }

    return 0;
}
