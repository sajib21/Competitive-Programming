/// WE WILL MAKE LONGEST DECREASING SUBSEQUENCE
/// AND AT LDS[I] WE WILL KEEP THE LDS VALUE WHICH WE CAN MAKE EVENTUALLY IF WE TAKE THIS VALUE NOW. (WERE PREVIOUSLY, WE KEPT THE LDS VALUE MADE SO FAR TAKING THIS VALUE)
/// THEN, WE WILL CHECK FROM FIRST. IF WE CAN MAKE REQUIRED SIZE TAKING THE CURRENT VALUE, WE WILL ALWAYS TAKE IT AND DECREMENT THE REQUIRED SIZE AND ETC

#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
//#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info {

    int in, n, mp;
    info() {}
    info(int ii, int nn, int mm = 0) {
        in = ii; n = nn; mp = mm;
    }
};
bool cmp1(info a, info b) {
    return a.n < b.n;
}
bool cmp2(info a, info b) {
    return a.in < b.in;
}


int n,q;
info ara[LIM+10], qry[12];
info segTree[4*LIM+10];
int qf[LIM+10];

info query(int node, int st, int ed, int l, int r) {
    if(r < l) return info(0,0);
    if(ed < l || st > r) return info(0,0);
    if(st >= l && ed <= r) return segTree[node];

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    info q1,q2;
    q1 = query(lft, st, md, l, r);
    q2 = query(rgt, md+1, ed, l, r);

    if(q1.n > q2.n) return q1;
    if(q1.n < q2.n) return q2;
    if(q1.in < q2.in) return q1;
    return q2;
}

void update(int node, int st, int ed, int pos, info term) {
//    cout << "INSIDE UP " << node << ' ' << st << ' ' << ed << ' ' << pos << ' ' << val <<endl;

    if(ed < pos || st > pos ) return;
    if(st == pos && ed == pos) {
        segTree[node].in = term.in;
        segTree[node].n  = term.n;
//        segTree[node] = (segTree[node] + val) % MOD;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update(lft, st,  md, pos, term);
    update(rgt, md+1,ed, pos, term);

    info q1,q2;
    q1 = segTree[lft];
    q2 = segTree[rgt];

    if(q1.n > q2.n) segTree[node] = q1;
    else if(q1.n < q2.n) segTree[node] = q2;
    else if(q1.in < q2.in) segTree[node] = q1;
    else segTree[node] = q2;

//    segTree[node] = (segTree[lft] + segTree[rgt] ) % MOD;

}

int pre[100005], lds[100005];
vii sol[12];

vii tt;
void getSol(info v) {
    if(!v.mp) return;
    getSol(ara[pre[v.mp]]);
    tt.pb(v.in);
}

int main() {

//    freopen("1277i.txt", "r", stdin);
//    freopen("1277o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &q);
//        for(int i=0; i<=q; i++) sol[i].clear();
//        memset(qf, 0, sizeof(qf));
        memset(lds, 0, sizeof(lds));
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

        int qq = 0;
        for(int i=n; i>0; i--) {
            info temp = query(1, 1,N, ara[i].mp+1, n);
            temp.n++;
            pre[ ara[i].mp ] = temp.in;
            lds[i] = temp.n;
            temp.in = i;
            update(1, 1,N, ara[i].mp, temp );
        }

//        for(int i=1; i<=n; i++) cout << lds[i] << ' '; cout << endl;

//        scanf("%d", &q);
        printf("Case %d:\n", t);
        for(int qq=0; qq<q; qq++) {
            int m;
            scanf("%d", &m);
            int prev = INT_MIN;
            bool f=0;
            for(int i=1; i<=n; i++) {
                if(lds[i] >= m && ara[i].n > prev) {
                    if(f) printf(" ");
                    printf("%d", ara[i].n);
                    prev = ara[i].n;
                    f = 1;
                    m--;
                }
                if(!m) break;
            }
            if(m) printf("Impossible");
            printf("\n");
        }
    }
    return 0;

}

