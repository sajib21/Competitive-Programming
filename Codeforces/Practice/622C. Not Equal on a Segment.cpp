#include<bits/stdc++.h>
#define LIM 200005
#define segVar int lft=2*node, rgt=2*node+1, md=(st+ed)/2
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,m, a[LIM];
vi segTree[4*LIM];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

void init(int node, int st, int ed) {
    for(int i=st; i<=ed; i++) segTree[node].pb(i);
    sort(segTree[node].begin(), segTree[node].end(), cmp);

    if(st == ed) return;
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
}

int bs(int node, int st, int ed, int x) {
    int lo=st, hi=ed+1;
    while(lo < hi) {
        int md = (lo+hi)/2;
        if(a[md] >= x) hi = md;
        else lo = md+1;
    }
    return hi;
}
int us(int node, int st, int ed, int x) {
    int lo=st, hi=ed+1;
    while(lo < hi) {
        int md = (lo+hi)/2;
        if(a[md] > x) hi = md;
        else lo = md+1;
    }
    return hi;
}
int query(int node, int st, int ed, int l, int r, int x) {
//    cout << "IN " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << x << endl; getchar();

    if(ed < l || st > r) return -1;
    if(st >= l && ed <= r) {
        if(a[ segTree[node][0] ] != x) return segTree[node][0];
        if(a[ segTree[node].back() ] != x) return segTree[node].back();
        return -1;
    }
    segVar;
    int ans = query(lft, st,md, l,r, x);
//    cout << "XX " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << x << ' ' << ans << endl; getchar();
    if(ans != -1) return ans;
    ans = query(rgt, md+1,ed, l,r,x);
//    cout << "XO " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << x << ' ' << ans << endl; getchar();

    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    init(1, 1,n);

    while(m--) {
        int l,r,x;
        scanf("%d %d %d", &l, &r, &x);
        printf("%d\n", query(1, 1,n, l,r, x));
    }
}
