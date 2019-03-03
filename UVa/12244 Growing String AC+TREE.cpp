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
int posInBase[LIM+100], par[LIM+100];
string pat[10004]; char str[1003];

void add(string s, int in) {
    int cur = 0;
    for(int i=0; i<s.size(); i++) {
        int p = s[i]-'a';
        if(trie[cur].nxt[ p ] == 0) {
            trie[cur].nxt[ p ] = ++idx;
            trie[idx] = node();
        }
        int pr = cur;
        cur = trie[cur].nxt[ p ];
        par[cur] = pr;
    }
    trie[cur].cnt++;

//    trie[cur].val++;
//    trie[cur].rem++;
//    trie[cur].niche = trie[cur].upre = in;
    posInBase[in] = cur;
}

void genFail() {
    int cur = 0;

    cur = 0;
    queue<int>q;
    q.push(cur);
    int ans = 0;

    while(!q.empty()) {
        cur = q.front();
        q.pop();

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
}

int n;
int dp[LIM+10];

int f(int u) {
    if(!u) return 0;
    if(dp[u] != -1) return dp[u];

    return dp[u] = trie[u].cnt + max(f(par[u]) , f(trie[u].fail));
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        scanf("%d", &n);
        if(!n) return 0;
        for(int i=0; i<=idx; i++) trie[i] = node();
        memset(par, 0, sizeof par);

        idx = 0;
        for(int i=0; i<n; i++) {
            scanf("%s", str);
            pat[i] = str;
        }
        for(int i=0; i<n; i++) {
            add(pat[i], i);
        }
        genFail();
//        printf("%d\n", genFail());

        memset(dp, -1, sizeof dp);


        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, f(posInBase[i]));
        }
        printf("%d\n", ans);

    }

    return 0;
}
