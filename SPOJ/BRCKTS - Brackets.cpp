///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             30000000
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

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

struct info{
    int x,y,z;
    info() {}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};

int n,m;
char seq[LIM+10];

info segTree[4*LIM+10];

void init(int node, int st, int ed) {
    if(st == ed) {
        if(seq[st-1] == '(') segTree[node].x++;
        else segTree[node].y++;
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    int mn = min(segTree[lft].x , segTree[rgt].y);
    segTree[node].x = segTree[lft].x - mn + segTree[rgt].x;
    segTree[node].y = segTree[rgt].y - mn + segTree[lft].y;
}

void update(int node, int st, int ed, int p) {
    if(ed < p || st > p) return;
    if(st >= p && ed <= p) {
        if(seq[st-1] == '(') {
            seq[st-1] = ')';
            segTree[node].x--;
            segTree[node].y++;
        }
        else {
            seq[st-1] = '(';
            segTree[node].x++;
            segTree[node].y--;
        }
        return;
    }
    segVar;
    update(lft, st, md, p); update(rgt, md+1, ed, p);
    int mn = min(segTree[lft].x , segTree[rgt].y);
    segTree[node].x = segTree[lft].x - mn + segTree[rgt].x;
    segTree[node].y = segTree[rgt].y - mn + segTree[lft].y;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T=10;
//    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(segTree, 0, sizeof(segTree));
        scanf("%d", &n);
        scanf("%s", seq);
        init(1, 1,n);
        scanf("%d", &m);
        printf("Test %d:\n", t);
        while(m--) {
            int x;
            scanf("%d", &x);
//            if(x == -1) {
//                cout << "BREAK" << endl;
//                break;
//            }
            if(!x) {
                if(!segTree[1].x && !segTree[1].y) printf("YES\n");
                else printf("NO\n");
            }
            else update(1, 1,n, x);
//            cout << segTree[1].x << ' ' << segTree[1].y << endl;
        }
    }

    return 0;
}

