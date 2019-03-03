#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

struct info {

    int in, n, mp;
    info() {}
    info(int ii, int nn, int mm) {
        in = ii; n = nn; mp = mm;
    }
};
bool cmp1(info a, info b) {
    return a.n < b.n;
}
bool cmp2(info a, info b) {
    return a.in < b.in;
}


int n;
info ara[LIM+10];
int segTree[4*LIM+10];

int query(int node, int st, int ed, int l, int r) {
    if(r < l) return 0;
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node];

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    return (query(lft, st, md, l, r) + query(rgt, md+1, ed, l, r) ) % MOD;
}

void update(int node, int st, int ed, int pos, int val) {
//    cout << "INSIDE UP " << node << ' ' << st << ' ' << ed << ' ' << pos << ' ' << val <<endl;

    if(ed < pos || st > pos ) return;
    if(st == pos && ed == pos) {
        segTree[node] = (segTree[node] + val) % MOD;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update(lft, st,  md, pos, val);
    update(rgt, md+1,ed, pos, val);
    segTree[node] = (segTree[lft] + segTree[rgt] ) % MOD;

}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &ara[i].n) , ara[i].in = i;
        sort(ara+1, ara+n+1, cmp1);
        ara[1].mp = 1;
        int N = 1;
        for(int i=2; i<=n; i++) {
            if(ara[i].n == ara[i-1].n) ara[i].mp = ara[i-1].mp;
            else ara[i].mp = ++N;
        }
        sort(ara+1, ara+n+1, cmp2);

        memset(segTree, 0, sizeof(segTree));

        for(int i=1; i<=n; i++) {
            update(1, 1,N, ara[i].mp, 1+query(1, 1,N, 1, ara[i].mp-1)  );

        }
        printf("Case %d: %d\n", t, segTree[1] );



    }
    return 0;

}

