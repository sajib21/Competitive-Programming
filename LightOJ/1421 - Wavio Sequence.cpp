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
int segLIS[4*LIM+10];
int segLDS[4*LIM+10];

int query1(int node, int st, int ed, int l, int r) {
    if(r < l) return 0;
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segLIS[node];

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    return max(query1(lft, st, md, l, r) , query1(rgt, md+1, ed, l, r) ) ;
}

void update1(int node, int st, int ed, int pos, int val) {
    if(ed < pos || st > pos ) return;
    if(st == pos && ed == pos) {
        segLIS[node] = max(segLIS[node] , val);
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update1(lft, st,  md, pos, val);
    update1(rgt, md+1,ed, pos, val);
    segLIS[node] = max(segLIS[lft] , segLIS[rgt] ) ;
}

int query2(int node, int st, int ed, int l, int r) {
    if(r < l) return 0;
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segLDS[node];

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    return max(query2(lft, st, md, l, r) , query2(rgt, md+1, ed, l, r) ) ;
}

void update2(int node, int st, int ed, int pos, int val) {
    if(ed < pos || st > pos ) return;
    if(st == pos && ed == pos) {
        segLDS[node] = max(segLDS[node] , val) ;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update2(lft, st,  md, pos, val);
    update2(rgt, md+1,ed, pos, val);
    segLDS[node] = max(segLDS[lft] , segLDS[rgt] ) ;
}

int main() {

//    freopen("1421 out.txt", "w", stdout);

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

        memset(segLIS, 0, sizeof(segLIS));
        memset(segLDS, 0, sizeof(segLDS));

        int keep1[LIM+100] , keep2[LIM+100];

        for(int i=1; i<=n; i++) {
            update1(1, 1,N, ara[i].mp, 1+query1(1, 1,N, 1, ara[i].mp-1)  );
            keep1[i] = query1(1, 1,N, ara[i].mp, ara[i].mp);
        }
        for(int i=n; i>0; i--) {
            update2(1, 1,N, ara[i].mp, 1+query2(1, 1,N, 1, ara[i].mp-1)  );
            keep2[i] = query2(1, 1,N, ara[i].mp, ara[i].mp);
        }

//        for(int i=1; i<=n; i++) cout << keep1[i] << " : " << keep2[i] << endl;


        int ans = 0;
        for(int i=1; i<=n; i++) ans = max(ans, 2*min(keep1[i] , keep2[i]) - 1 );
        printf("Case %d: %d\n", t, ans);


    }
    return 0;

}

