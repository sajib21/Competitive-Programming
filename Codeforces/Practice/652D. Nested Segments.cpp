#include<bits/stdc++.h>
#define LIM 200005
#define MAX 1000000009
#define vi vector<int>
#define pb(x) push_back(x)
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2

using namespace std;

struct info {
    int x,y,z;
    info() {}
    info(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        return x < b.x;
    }
};

int n;
info pts[LIM];
int ans[LIM];
vi segTree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node].pb(pts[st].y);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    int i=0,j=0;
    while(i < segTree[lft].size() && j < segTree[rgt].size()) {
        if(segTree[lft][i] < segTree[rgt][j]) segTree[node].pb(segTree[lft][i++]);
        else segTree[node].pb(segTree[rgt][j++]);
    }
    while(i < segTree[lft].size()) segTree[node].pb(segTree[lft][i++]);
    while(j < segTree[rgt].size()) segTree[node].pb(segTree[rgt][j++]);
}
int query(int node, int st, int ed, int p, int v) {
    if(ed < p) return 0;
    if(st >= p) {
        return lower_bound(segTree[node].begin(), segTree[node].end(), v) -
        segTree[node].begin();
    }
    segVar;
    return query(lft, st,md, p, v) + query(rgt, md+1,ed, p,v);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d %d", &pts[i].x, &pts[i].y);
        pts[i].z = i;
    }
    sort(pts+1, pts+n+1);

//    cout << "DATA" << endl;
//    for(int i=0; i<n; i++) cout << pts[i].x << ' ' << pts[i].y << ' ' << pts[i].z << endl;

    init(1, 1,n);
    for(int i=1; i<=n; i++) {
        int x = pts[i].x, y = pts[i].y, id = pts[i].z;
        ans[id] = query(1, 1,n, i, y);
    }

    for(int i=1; i<=n; i++) printf("%d\n", ans[i]);
}
