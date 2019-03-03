#include<bits/stdc++.h>
#define LIM 100005
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n, a[LIM];
vi mTree[4*LIM];
int gTree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        mTree[node].pb(a[st]);
        gTree[node] = a[st];
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    gTree[node] = __gcd(gTree[lft], gTree[rgt]);
    int i=0, j=0;
    while(i < mTree[lft].size() && j < mTree[rgt].size()) {
        if(mTree[lft][i] < mTree[rgt][j]) mTree[node].pb(mTree[lft][i++]);
        else                              mTree[node].pb(mTree[rgt][j++]);
    }
    while(i < mTree[lft].size()) mTree[node].pb(mTree[lft][i++]);
    while(j < mTree[rgt].size()) mTree[node].pb(mTree[rgt][j++]);
}

int gquery(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return gTree[node];
    segVar;
    return __gcd( gquery(lft, st,md, l,r) , gquery(rgt, md+1,ed, l,r) );
}
int mquery(int node, int st, int ed, int l, int r, int v) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return upper_bound(mTree[node].begin(), mTree[node].end(), v)
        - lower_bound(mTree[node].begin(), mTree[node].end(), v);

    segVar;
    return mquery(lft, st,md, l,r, v) + mquery(rgt, md+1,ed, l,r, v);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    init(1, 1,n);

    int t;
    scanf("%d", &t);
    while(t--) {
        int i,j;
        scanf("%d %d", &i,&j);
        printf("%d\n", (j-i+1) - mquery(1, 1,n, i,j, gquery(1, 1,n, i,j) ) );
    }
}
