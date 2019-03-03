#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
#define LIM 200005
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

int n,p, a[LIM], id[LIM],bas[LIM], sub[LIM], tim, vis[LIM];
pii segTree[4*LIM];
vii g[LIM];

void dfs(int u) {
    vis[u] = 1;
    id[u] = ++tim;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        dfs(v);
    }
    sub[u] = tim;
}

void init(int node, int st, int ed) {
//    cout << node << ' ' << st << ' ' << ed << endl;
    if(st == ed) {
        segTree[node].ff = a[ bas[st] ];
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = pii(segTree[lft].ff+segTree[rgt].ff, 0);
}

void update(int node, int st, int ed, int l, int r, int carry=0) {
    if(carry) segTree[node].ff = (ed-st+1) - segTree[node].ff;
    segTree[node].ss ^= carry;
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node].ff = (ed-st+1) - segTree[node].ff;
        segTree[node].ss = 1 - segTree[node].ss;
        return;
    }
    segVar;
    update(lft, st,md, l,r, segTree[node].ss);
    update(rgt, md+1,ed, l,r, segTree[node].ss);
    segTree[node].ff = segTree[lft].ff + segTree[rgt].ff;
    segTree[node].ss = 0;
}

int query(int node, int st, int ed, int l, int r, int carry=0) {
    if(carry) segTree[node].ff = (ed-st+1) - segTree[node].ff;
    segTree[node].ss ^= carry;
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) {
        return segTree[node].ff;
    }
    segVar; int c = segTree[node].ss; segTree[node].ss = 0;
    return query(lft, st,md, l,r, c) +
        query(rgt, md+1,ed, l,r, c);
}

int main() {
//    char str[1000];
//    scanf("%s", str);
//    printf("%s\n", str);


    scanf("%d", &n);
    for(int u=2; u<=n; u++) {
        scanf("%d", &p);
        g[p].pb(u);
    }
    dfs(1);
    for(int i=1; i<=n; i++) bas[ id[i] ] = i;

//    cout << 1 << ' ' << id[1] << sub[1] << endl;

//    cout << "ID" << endl;
//    for(int i=1; i<=n; i++) cout << i << ' ' << id[i] << endl;
//    cout << "BAS" << endl;
//    for(int i=1; i<=n; i++) cout << i << ' ' << bas[i] << endl;

    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    init(1, 1,n);

//    for(int i=1; i<=12; i++) cout << i << ' ' << segTree[i].ff << endl;



    int q;
    scanf("%d", &q);

//    cout << "BUG" << endl;

    while(q--) {
        char str[10]; int x;
        scanf("%s", str);
//        printf("%s\n", str);
        scanf("%d", &x);

        if(str[0] == 'p') {
//            cout << "POW " << id[x] << ' ' << sub[x] << endl;
            update(1, 1,n, id[x], sub[x]);
        }
        else {
            printf("%d\n", query(1, 1,n, id[x], sub[x]));
        }
    }
}
/*
10
1 2 3 3 5 5 7 7 8
0 0 0 0 1 1 1 1 0 0
100
pow 3
get 1
pow 9
get 1
get 1
get 8
pow 8
pow 4
get 10
pow 2
*/
