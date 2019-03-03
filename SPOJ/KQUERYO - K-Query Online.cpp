///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             300000
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

int n,q, ara[LIM+10];
vii segTree[LIM+10];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = vii(1, ara[st]);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    vii ans;
    for(int i=0,j=0; i<segTree[lft].size() || j<segTree[rgt].size(); ) {
        if(i == segTree[lft].size()) ans.pb(segTree[rgt][j++]);
        else if(j == segTree[rgt].size()) ans.pb(segTree[lft][i++]);
        else if(segTree[lft][i] <= segTree[rgt][j]) ans.pb(segTree[lft][i++]);
        else ans.pb(segTree[rgt][j++]);
    }
    segTree[node] = ans;
}

int query(int node, int st, int ed, int l, int r, int k) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) {
        int in = upper_bound(segTree[node].begin(), segTree[node].end(), k) - segTree[node].begin();
        return segTree[node].size() - in;
    }
    segVar;
//    int
    return query(lft, st,md, l,r, k) + query(rgt, md+1,ed, l,r, k);
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
    init(1, 1,n);

//    for(int i=1; i<14; i++) {
////        cout << i << " : " ;
////        for(int j=0; j<segTree[i].size(); j++) printf("%3d", segTree[i][j]);
////        cout << endl;
//    }

    scanf("%d", &q);
    int ans = 0;
    while(q--) {
        int a,b,c,i,j,k;
        scanf("%d %d %d", &a,&b,&c);
        i = ans^a; j = ans^b; k = ans^c;
        ans = query(1, 1,n, i,j,k);
        printf("%d\n", ans);
    }

    return 0;
}

