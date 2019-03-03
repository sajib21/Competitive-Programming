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

int dirR[] = {-1, } ;
int dirC[] = { 0, } ;

struct node { ///val is the count/result : number of occurance of this prefix in text ;
              /// nxt is nxt of trie ; fail : failure function / suffix of aho
              /// cnt : count of occurance of this prefix in patterns
    int val, nxt[28], fail, cnt, o, x,y;
    node() { val = fail = cnt = 0; memset(nxt, -1, sizeof nxt); }
    node(int cc, int ff, int vv) { cnt = cc; fail = ff; val = vv; }
};

int idx=0;
node trie[260000];
int posInBase[505];

void add(string s, int in) {
    int cur = 0;
    int sz = s.size();
    for(int i=0; i<sz; i++) {
        int p = s[i]-'A'+1;
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

void checker(string text, int o, int x) {
    int sz = text.size();
    int cur = 0;

    for(int i=0; i<sz; i++) {
        int p = text[i] - 'A' + 1;

        while(cur != 0 && trie[cur].nxt[ p ] == -1) cur = trie[cur].fail;

        if(trie[cur].nxt[ p ] != -1) {
            cur = trie[cur].nxt[p];
            int temp = cur;
            while(temp != 0) {
                trie[temp].val++;
                trie[temp].o = o;
                trie[temp].x = x;
                trie[temp].y = i;
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

char ch[505], chb[1000006];
int row,col,w;
string grid[1010];

int main() {

//    freopen("1427i.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        //memset(trie, -1, sizeof trie);
        idx = 0;
        int n;

        scanf("%d %d %d", &row, &col, &w);
        for(int i=0; i<row; i++) {
            scanf("%s", chb);
            grid[i] = chb;
        }
//        scanf("%s", &chb);
//        text = chb;

        for(int i=0; i<w; i++) {
            scanf("%s", &ch);
            pat = ch;
            reverse(pat.begin(), pat.end());
            cout << pat << endl;
            add(pat, i);
        }

//        cout << "A " << trie[0].nxt[1] << " B " << trie[ trie[0].nxt[1] ].nxt[2] << " C " <<  trie[ trie[ trie[0].nxt[1] ].nxt[2] ].nxt[3] << endl;


        genFail();
//        checker(text);

        for(int c=0; c<col; c++) { ///checking orientation A
            text.clear();
            for(int r=0; r<row; r++) text += grid[r][c]; ///ekhane ulta text banalam cz pattern o ulta kore trie banaisi
            if(text == pat) cout << c << ' ' << text << endl;
            checker(text, 0, c);
        }

//        /// orientation B
//        for(int cc=0; cc<col; cc++) {
//            text.clear();
//            for(int c=cc,r=0; c>=0 && r<row; c--,r++) text += grid[r][c];
//            checker(text, 11, cc);
//        }
//        for(int rr=0; rr<row; rr++) {
//            text.clear();
//            for(int r=rr,c=col-1; r<row && c>=0; r++,c--) text += grid[r][c];
//            checker(text, 12, rr);
//        }
//
//        for(int r=0; r<row; r++) { ///checking orientation C
//            text.clear();
//            for(int c=col-1; c>=0; c--) text += grid[r][c]; ///abr o same reason e ulta nilam
//            checker(text, 2, r);
//        }
//
//        /// orientation D
//        for(int cc=0; cc<col; cc++) {
//            text.clear();
//            for(int c=cc,r=row-1; c>=0 && r>=0; c--,r--) text += grid[r][c];
//            checker(text, 31, cc);
//        }
//        for(int rr=0; rr<row; rr++) {
//            text.clear();
//            for(int r=rr,c=col-1; r>=0 && c>=0; r--,c--) text += grid[r][c];
//            checker(text, 32, rr);
//        }
////        cout << "BUG" << endl;
//        for(int c=0; c<col; c++) { ///checking orientation E
//            text.clear();
//            for(int r=row-1; r>=0; r--) text += grid[r][c]; ///ekhane ulta text banalam cz pattern o ulta kore trie banaisi
//            checker(text, 4, c);
//        }
//
//        ///orientation F
//        for(int cc=0; cc<col; cc++) {
//            text.clear();
//            for(int c=cc,r=row-1; c<col && r>=0; c++,r--) text += grid[r][c];
//            checker(text, 51, cc);
//        }
//        for(int rr=0; rr<row; rr++) {
//            text.clear();
//            for(int r=rr,c=0; r>=0 && c<col; r--,c++) text += grid[r][c];
//            checker(text, 52, rr);
//        }
//
//        for(int r=0; r<row; r++) { ///checking orientation G
//            text.clear();
//            for(int c=0; c<col; c++) text += grid[r][c]; ///abr o same reason e ulta nilam
//            checker(text, 6, r);
//        }
//
//        ///orientation H
//        for(int cc=0; cc<col; cc++) {
//            text.clear();
//            for(int c=cc,r=0; c<col && r<row; c++,r++) text += grid[r][c];
//            checker(text, 71, cc);
//        }
//        for(int rr=0; rr<row; rr++) {
//            text.clear();
//            for(int r=rr,c=0; r<row && c<col; r++,c++) text += grid[r][c];
//            checker(text, 72, rr);
//        }

        for(int i=0; i<w; i++) {
            int id = posInBase[i];
            int r,c; char o;
            if(trie[id].o == 0) { c = trie[id].x; r = trie[id].y; o = 'A'; }

//            else if(trie[id].o == 11) { c = trie[id].x - trie[id].y; r = trie[id].y; o = 'B'; }
//            else if(trie[id].o == 12) { r = trie[id].x + trie[id].y; c = col-trie[id].y-1; o = 'B'; }
//
//            else if(trie[id].o == 2) { r = trie[id].x; c = col-trie[id].y-1; o = 'C'; }
//
//            else if(trie[id].o == 31) { c = trie[id].x - trie[id].y; r = row-trie[id].y-1; o = 'D'; }
//            else if(trie[id].o == 32) { r = trie[id].x - trie[id].y; c = col-trie[id].y-1; o = 'D'; }
//
//            else if(trie[id].o == 4) { c = trie[id].x; r = row-trie[id].y-1; o = 'E'; }
//
//            else if(trie[id].o == 51) { c = trie[id].x + trie[id].y; r = row-trie[id].y-1; o = 'F'; }
//            else if(trie[id].o == 52) { r = trie[id].x - trie[id].y; c = trie[id].y; o = 'F'; }
//
//            else if(trie[id].o == 6) { r = trie[id].x; c = trie[id].y; o = 'G'; }
//
//            else if(trie[id].o == 71) { c = trie[id].x + trie[id].y; r = trie[id].y; o = 'H'; }
//            else if(trie[id].o == 72) { r = trie[id].x + trie[id].y; c = trie[id].y; o = 'H'; }

            printf("%d %d %c\n", r,c, o);
        }
        deleteTrie(0);
    }

    return 0;
}
