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

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

struct info{
    ull x,y,z;
    info() {x = y = z = 0;}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};
bool cmpx(info x, info y) {
    return x.x < y.x;
}
bool cmpy(info x, info y) {
    return x.y < y.y;
}

int n,m,q;
ull p1 = 7, p2 = 17;
char str[LIM+10]; string pat;
info tree1[4*LIM+100], tree2[4*LIM+100];
ull expo1[LIM+10], expo2[LIM+10];

void init(int node, int st, int ed) {
    if(st == ed) {
        tree1[node].x = tree1[node].y = pat[st];
        tree2[node].x = tree2[node].y = pat[st];
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1, ed);

    tree1[node].x = tree1[lft].x + tree1[rgt].x*expo1[md-st+1]; //  (md-st+1)*p1;
    tree1[node].y = tree1[lft].y + tree1[rgt].y*expo2[md-st+1]; //  (md-st+1)*p2;

    tree2[node].x = tree2[rgt].x + tree2[lft].x*expo1[ed-md];   //  (ed-md)*p1;
    tree2[node].y = tree2[rgt].y + tree2[lft].y*expo2[ed-md];   //  (ed-md)*p2;
}

void update(int node, int st, int ed, int p, int val) {
    if(ed < p || st > p) return;
    if(st >= p && ed <= p) {
        tree1[node].x = tree1[node].y = val;
        tree2[node].x = tree2[node].y = val;
        return;
    }
    segVar;
    update(lft, st,md, p,val); update(rgt, md+1,ed, p,val);

    tree1[node].x = tree1[lft].x + tree1[rgt].x*expo1[md-st+1]; //  (md-st+1)*p1;
    tree1[node].y = tree1[lft].y + tree1[rgt].y*expo2[md-st+1]; //  (md-st+1)*p2;

    tree2[node].x = tree2[rgt].x + tree2[lft].x*expo1[ed-md];   //  (ed-md)*p1;
    tree2[node].y = tree2[rgt].y + tree2[lft].y*expo2[ed-md];   //  (ed-md)*p2;
}


info query1(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return info(0,0);
    if(st >= l && ed <= r) return tree1[node];
    segVar;
    info a,b, ans;
    a = query1(lft, st,md, l,r);
    b = query1(rgt,md+1,ed,l,r);

    int len = max( 0, md- max(st,l) +1 );
    ans.x = a.x + b.x*expo1[len]; //   (md-st+1)*p1;
    ans.y = a.y + b.y*expo2[len]; //   (md-st+1)*p2;

    return ans;
}

info query2(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return info(0,0);
    if(st >= l && ed <= r) return tree2[node];
    segVar;
    info a,b, ans;
    a = query2(lft, st,md, l,r);
    b = query2(rgt,md+1,ed,l,r);

    int len = max( 0, min(ed,r) -md );
    ans.x = b.x + a.x*expo1[len];  //   (ed-md)*p1;
    ans.y = b.y + a.y*expo2[len];  //   (ed-md)*p2;
    return ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%s", str);
    pat = str;
    pat = "0" + pat;
    n = pat.size() - 1;
    for(int i=1; i<=n; i++) pat[i] -= 'a';

    expo1[0] = expo2[0] = 1;
    for(int i=1; i<=n; i++) expo1[i] = expo1[i-1]*p1;
    for(int i=1; i<=n; i++) expo2[i] = expo2[i-1]*p2;

    init(1, 1,n);
    init(1, 1,n);

    scanf("%d", &q);
    while(q--) {
        int i,j; char ch;
        scanf("%s", str);
        if(str[0] == 'c') {
            scanf("%d %c", &i,&ch);
            update(1, 1,n, i, ch-'a');
        }
        else {
            scanf("%d %d", &i,&j);
            info a,b;
            a = query1(1, 1,n, i,j);
            b = query2(1, 1,n, i,j);

            if(a.x == b.x && a.y == b.y) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
