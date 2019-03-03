#include<bits/stdc++.h>
#define ll long long int
#define LIM 200005
#define segVar int lft=2*node, rgt=2*node+1, md=(st+ed)/2
#define pb(x) push_back(x)

using namespace std;

int n, a[LIM];
ll t, sum[LIM];
vector<ll>tree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        tree[node].push_back(sum[st]);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    int i=0, j=0;
    while(i<tree[lft].size() && j<tree[rgt].size()) {
        if(tree[lft][i] <= tree[rgt][j]) tree[node].pb(tree[lft][i++]);
        else tree[node].pb(tree[rgt][j++]);
    }
    while(i<tree[lft].size()) tree[node].pb(tree[lft][i++]);
    while(j<tree[rgt].size()) tree[node].pb(tree[rgt][j++]);
}

int query(int node, int st, int ed, int l, int r, ll v) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r)
        return lower_bound(tree[node].begin(), tree[node].end(), v) - tree[node].begin();
    segVar;
    return query(lft, st,md, l,r, v) + query(rgt, md+1,ed, l,r, v);
}

int main() {
    scanf("%d %lld", &n, &t);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
    init(1, 1,n);

    ll ans = 0;
    for(int i=1; i<=n; i++) {
        ll temp = query(1, 1,n, i,n, t+sum[i-1]);
        ans += temp;
//        cout << i << ' ' << temp << endl;
    }

    cout << ans << endl;
}
