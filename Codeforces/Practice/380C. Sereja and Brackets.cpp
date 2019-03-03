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
    segTree[node].z = segTree[lft].z + segTree[rgt].z + 2*mn;
}

info query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return info();
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    info q1,q2,ans;
    q1 = query(lft, st,md, l,r); q2 = query(rgt, md+1,ed, l,r);
    if(md < l) return q2;
    if(md+1 > r) return q1;
    int mn = min(q1.x , q2.y);
    ans.x = q1.x - mn + q2.x;
    ans.y = q2.y - mn + q1.y;
    ans.z = q1.z + q2.z + 2*mn;
    return ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T=10;
//    scanf("%d", &T);
    for(int t=1; t<=1; t++) {
        memset(segTree, 0, sizeof(segTree));
//        scanf("%d", &n);
        scanf("%s", seq);
        n = strlen(seq);
        init(1, 1,n);
        scanf("%d", &m);
//        printf("Test %d:\n", t);
        while(m--) {
            int x,y;
            scanf("%d %d", &x, &y);
            printf("%d\n", query(1, 1,n, x,y).z);
        }
    }

    return 0;
}

