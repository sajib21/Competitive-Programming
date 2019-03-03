/// PROBLEM : GIVEN A PATTERN, PROBABILITY OF EACH CHARACTER BEING CHOSED AND THE SIZE OF TEXT,
/// YOU HAVE TO DETERMINE THE PROBABILITY OF CHOOSING SUCH A TEXT SO THAT THE PATTERN DOESN'T OCCUR IN THE TEXT.

///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             40
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
    int val, nxt[64], fail, cnt;
    node() { val = fail = cnt = 0; memset(nxt, 0, sizeof nxt); }
    node(int cc, int ff, int vv) { cnt = cc; fail = ff; val = vv; }
};

string text, pattern;
int n,k, sizeText, sizePattern;
double prob[65];

int idx=0;
node trie[LIM*20+4];

void add(string s, int in) {
    int cur = 0;
    for(int i=0; i<s.size(); i++) {
        int p = s[i];
        if(trie[cur].nxt[ p ] == 0) {
            trie[cur].nxt[ p ] = ++idx;
            trie[idx] = node();
        }
        cur = trie[cur].nxt[ p ];
    }
    trie[cur].cnt++;
}

void genFail() {
    int cur = 0;
    queue<int>q;
    q.push(cur);


    while(!q.empty()) {
        cur = q.front();
        q.pop();

        int f = trie[cur].fail;
//        if(trie[f].cnt) trie[cur].cnt++;

//        cout << "GEN FAIL " << cur << endl; getchar();
        for(int p=0; p<62; p++) {
            if(trie[cur].nxt[p] != 0) {
                q.push(trie[cur].nxt[p]);
                int temp = cur;
//                cout << "GEN FAIL " << cur << ' ' << trie[cur].nxt[p] << endl; getchar();

                while(temp != 0) {
                    int f = trie[temp].fail;
                    if( trie[f].nxt[p] != 0 ) {
                        trie[ trie[cur].nxt[p] ].fail = trie[f].nxt[p];
                        if(trie[ trie[f].nxt[p] ].cnt) trie[ trie[cur].nxt[p] ].cnt++;
                        break;
                    }
                    else temp = f;
                }
                if(temp == 0) trie[ trie[cur].nxt[p] ].fail = 0;
            }
            else {
                int f = trie[cur].fail;
                trie[cur].nxt[p] = trie[f].nxt[p];
            }
        }
    }
}

bool vis[110][LIM*20+4];
double dp[110][LIM*20+4];

double f(int in, int k) { /// in is the current index of text, k is the current index of pattern ;
                          /// this function is looking for the probability of the pattern being PRESENT in text
    if(trie[k].cnt) return 0;
    if(in == sizeText) return 1;
    if(vis[in][k] != 0) return dp[in][k];

    double ans = 0;
    for(int p=0; p<62; p++) if(prob[p] != 0) ans += prob[p]*f(in+1, trie[cur].nxt[p]);

    vis[in][k] = 1;
    return dp[in][k] = ans;
}

int main() {

//    freopen("11468i.txt", "r", stdin);
//    freopen("11468o.txt", "w",stdout);

//    cout << trie[0].nxt[0] << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) { //cout << "BUG" << endl;

        for(int i=0; i<62; i++) prob[i] = 0;
        for(int i=0; i<=LIM*20; i++) trie[i] = node();
        memset(vis, 0, sizeof vis);
        memset(dp, 0, sizeof dp);

        idx = 0;
        scanf("%d", &k);
        for(int i=0; i<k; i++) {
            char str[30]; scanf("%s", str);
            pattern = str;
            for(int j=0; j<pattern.size(); j++) {
                if(pattern[j] >= 'a' && pattern[j] <= 'z') pattern[j] = pattern[j] - 'a';
                else if(pattern[j] >= 'A' && pattern[j] <= 'Z') pattern[j] = pattern[j] - 'A' + 26;
                else if(pattern[j] >= '0' && pattern[j] <= '9') pattern[j] = pattern[j] - '0' + 26 + 26;

            }
//            for(int j=0; j<pattern.size(); j++) cout << (int)(pattern[j]) << ' ' ; cout << endl;
            add(pattern, i);
        }
        genFail();

        scanf("%d", &n); ///n is the number of valid characters
        for(int i=0; i<n; i++) {
            char c; double p;
            getchar();
            scanf("%c %lf", &c, &p); ///each valid character and probability of choosing it
            if(c >= 'a' && c <='z') prob[c-'a'] = p;
            else if(c >= 'A' && c <='Z') prob[c-'A' + 26] = p;
            else if(c >= '0' && c <='9') prob[c-'0' + 26 + 26] = p;

        }
        scanf("%d", &sizeText);

        double ans = f(0,0);
        printf("Case #%d: %lf\n",t, ans);

//        del(0);
    }

    return 0;
}
