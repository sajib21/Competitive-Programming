#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     10000000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

int idx, mxx = 0;
struct node {
    int val, sub, nxt[2];
    node() {
        val = 0; sub = 0;
        for(int i=0; i<2; i++) nxt[i] = -1;
    }
} trie[3000000];

int add(int s) {
    stack<int>stk;
    for(int i=0; i<29; i++) stk.push(s%2) , s /= 2;
    int cur = 0;

    while(!stk.empty()) {
        int n = stk.top(); stk.pop();
        if(trie[cur].nxt[n] == -1) trie[cur].nxt[n] = ++idx;
        cur = trie[cur].nxt[n];
        trie[cur].sub++;
//        cout << n << ' ' << cur << ' ' << trie[cur].sub << endl;
    }
//    trie[cur].val++;
//    return cur;
}

int del(int s) {
    stack<int>stk;
    for(int i=0; i<29; i++) stk.push(s%2) , s /= 2;
    int cur = 0;

    while(!stk.empty()) {
        int n = stk.top(); stk.pop();
        if(trie[cur].nxt[n] == -1) trie[cur].nxt[n] = ++idx;
        cur = trie[cur].nxt[n];
        trie[cur].sub--;
    }
//    trie[cur].val--;
//    return cur;
}

int chk(int p, int l) {
    stack<int>pstk, lstk;
    for(int i=0; i<29; i++) pstk.push(p%2) , p /= 2;
    for(int i=0; i<29; i++) lstk.push(l%2) , l /= 2;
    int cur = 0;
    int cnt = 0;
    while(!pstk.empty()) {
        int pn = pstk.top(); pstk.pop();
        int ln = lstk.top(); lstk.pop();

        if(!ln) cur = trie[cur].nxt[pn];
        else {
            int t = trie[cur].nxt[pn];
            if(t != -1) cnt += trie[t].sub;
            cur = trie[cur].nxt[!pn];
        }
        if(cur == -1) {
            return cnt;
            cur = 0;
            break;
        }
//        cout << "CHAY " << ln << ' ' << "PAY " << pn << ' ' << !pn << ' ' << cur << ' ' << cnt << endl;
//        cout << cnt << endl;
    }
//    cnt += trie[cur].sub;
    return cnt;
}

int q,c, p,l;


int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("817Eo.txt", "w",stdout);

//    cout << trie[0].nxt[0] << endl;

    scanf("%d", &q);
    while(q--) {
        scanf("%d", &c);
        if(c == 'x') return 0;
        if(c == 1) {
            scanf("%d", &p);
            add(p);
        }
        else if(c == 2) {
            scanf("%d", &p);
            del(p);
        }
        else {
            scanf("%d %d", &p, &l);
            printf("%d\n", chk(p,l));
//            cout << "ZERO " << trie[0].sub << endl;
        }
    }

    return 0;
}

