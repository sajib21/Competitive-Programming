
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
    int val, nxt[28], fail, cnt, o, x,y;
    node() { val = fail = cnt = 0; memset(nxt, -1, sizeof nxt); }
    node(int cc, int ff, int vv) { cnt = cc; fail = ff; val = vv; }
};

int idx=0;
node trie[1000006];
int posInBase[1003];
int posInMain[1004];

string pat, text;

//#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

char ch[1000005], chb[1005];
int row,col,w;
string grid[1010];

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
    posInMain[cur] = in;
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

int ansr[2005],ansc[2005];
char anso[2005];

void getAns(int in) {
    int id = posInBase[in];
    int r,c; char o;
    if(trie[id].o == 0) { c = trie[id].x; r = trie[id].y; o = 'A'; }

    else if(trie[id].o == 11) { c = trie[id].x - trie[id].y; r = trie[id].y; o = 'B'; }
    else if(trie[id].o == 12) { r = trie[id].x + trie[id].y; c = col-trie[id].y-1; o = 'B'; }

    else if(trie[id].o == 2) { r = trie[id].x; c = col-trie[id].y-1; o = 'C'; }

    else if(trie[id].o == 31) { c = trie[id].x - trie[id].y; r = row-trie[id].y-1; o = 'D'; }
    else if(trie[id].o == 32) { r = trie[id].x - trie[id].y; c = col-trie[id].y-1; o = 'D'; }

    else if(trie[id].o == 4) { c = trie[id].x; r = row-trie[id].y-1; o = 'E'; }

    else if(trie[id].o == 51) { c = trie[id].x + trie[id].y; r = row-trie[id].y-1; o = 'F'; }
    else if(trie[id].o == 52) { r = trie[id].x - trie[id].y; c = trie[id].y; o = 'F'; }

    else if(trie[id].o == 6) { r = trie[id].x; c = trie[id].y; o = 'G'; }

    else if(trie[id].o == 71) { c = trie[id].x + trie[id].y; r = trie[id].y; o = 'H'; }
    else if(trie[id].o == 72) { r = trie[id].x + trie[id].y; c = trie[id].y; o = 'H'; }

    ansr[in] = r; ansc[in] = c; anso[in] = o;

    printf("%d %d %d %c\n",  r,c, o);
}


int cur = 0;
void checker(int r, int c, int dr, int dc, int o, int x) {
    int sz = text.size();
//    int cur = 0;

    for(int i=0; r>=0 && r<row && c>=0 && c<col; i++, r+=dr, c+=dc) {
        int p = grid[r][c] - 'A' + 1;

//        while(cur != 0 && trie[cur].nxt[ p ] == -1) cur = trie[cur].fail;
//        if(cur == -1) cur = 0;
        cur = trie[cur].nxt[p];

        if(cur == -1) cur = 0;

        int temp = cur;
        if(posInMain[cur]) {
            trie[temp].val++;
                trie[temp].o = o;
                trie[temp].x = x;
                trie[temp].y = i;
        }

//        if(trie[cur].nxt[ p ] != -1) {
//            cur = trie[cur].nxt[p];
//            int temp = cur;
////            while(temp != 0) {
//            if(posInMain[temp] != -1) {
//                trie[temp].val++;
//                trie[temp].o = o;
//                trie[temp].x = x;
//                trie[temp].y = i;
////                temp = trie[temp].fail;
//
////                if(posInMain[temp] != -1) {
////                    getAns(posInMain[temp]);
////                }
////            }
//            }
//        }
    }
}

void deleteTrie(int cur) {
    for(int i=1; i<=26; i++) if(trie[cur].nxt[i] != -1) deleteTrie(trie[cur].nxt[i]);
    trie[cur] = node();
}



int main() {

//    freopen("1427i.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        //memset(trie, -1, sizeof trie);
        memset(posInMain, 0, sizeof posInMain);
        idx = 0;
        int n;

        scanf("%d %d %d", &row, &col, &w);
        for(int i=0; i<row; i++) {
            scanf("%s", chb);
            grid[i] = chb;
        }

        for(int i=0; i<w; i++) {
            scanf("%s", ch);
            pat = ch;
            reverse(pat.begin(), pat.end());
            add(pat, i);
        }
        genFail();

        cur = 0;

        for(int c=0; c<col; c++) { ///checking orientation A
            checker(0,c, +1,0,  0, c);
        }

        /// orientation B
        for(int cc=0; cc<col; cc++) {
            checker(0,cc, +1,-1, 11,cc);
        }
        for(int rr=0; rr<row; rr++) {
            checker(rr,col-1, +1,-1, 12,rr);
        }

        for(int r=0; r<row; r++) { ///checking orientation C
            checker(r,col-1, 0,-1, 2, r);
        }

        /// orientation D
        for(int cc=0; cc<col; cc++) {
            checker(row-1,cc, -1,-1, 31,cc);
        }
        for(int rr=0; rr<row; rr++) {
            checker(rr,col-1, -1,-1, 32, rr);
        }

        for(int c=0; c<col; c++) { ///checking orientation E
            checker(row-1,c, -1,0, 4, c);
        }

        ///orientation F
        for(int cc=0; cc<col; cc++) {
            checker(row-1,cc, -1,+1, 51,cc);
        }
        for(int rr=0; rr<row; rr++) {
            checker(rr,0, -1,+1, 52, rr);
        }

        for(int r=0; r<row; r++) { ///checking orientation G
            checker(r,0, 0,+1, 6, r);
        }

        ///orientation H
        for(int cc=0; cc<col; cc++) {
            checker(0,cc, +1,+1, 71,cc);
        }
        for(int rr=0; rr<row; rr++) {
            checker(rr,0, +1,+1, 72, rr);
        }

        for(int i=0; i<w; i++) {
            int id = posInBase[i];
            int r,c; char o;
            if(trie[id].o == 0) { c = trie[id].x; r = trie[id].y; o = 'A'; }

            else if(trie[id].o == 11) { c = trie[id].x - trie[id].y; r = trie[id].y; o = 'B'; }
            else if(trie[id].o == 12) { r = trie[id].x + trie[id].y; c = col-trie[id].y-1; o = 'B'; }

            else if(trie[id].o == 2) { r = trie[id].x; c = col-trie[id].y-1; o = 'C'; }

            else if(trie[id].o == 31) { c = trie[id].x - trie[id].y; r = row-trie[id].y-1; o = 'D'; }
            else if(trie[id].o == 32) { r = trie[id].x - trie[id].y; c = col-trie[id].y-1; o = 'D'; }

            else if(trie[id].o == 4) { c = trie[id].x; r = row-trie[id].y-1; o = 'E'; }

            else if(trie[id].o == 51) { c = trie[id].x + trie[id].y; r = row-trie[id].y-1; o = 'F'; }
            else if(trie[id].o == 52) { r = trie[id].x - trie[id].y; c = trie[id].y; o = 'F'; }

            else if(trie[id].o == 6) { r = trie[id].x; c = trie[id].y; o = 'G'; }

            else if(trie[id].o == 71) { c = trie[id].x + trie[id].y; r = trie[id].y; o = 'H'; }
            else if(trie[id].o == 72) { r = trie[id].x + trie[id].y; c = trie[id].y; o = 'H'; }

            printf("%d %d %c\n", r,c, o);
//            printf("%d %d %c\n", ansr[i],ansc[i], anso[i]);
        }
        deleteTrie(0);
    }

    return 0;
}
