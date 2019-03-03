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
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define BUG(x) cout << "BUG " << x << endl;

using namespace std;

struct info {
    int val, dif, prop;
    info() {
        val = 0; prop = 0; dif = 0;
    }
    info(int vv, int dd, int pp) {
        val = vv; prop = pp; dif = dd;
    }

};

int n,x, dif[LIM + 10];
info segTree[4*LIM + 10];

void init(int node, int st, int ed) {
//    cout << "IN  " << node << ' ' << st << ' ' << ed << endl;
    if(st == ed) {
        segTree[node] = info(st, dif[st], 0);
//        cout << "OUT " << node << ' ' << st << ' ' << ed << ' ' << segTree[node].val << ' ' << segTree[node].dif << ' ' << segTree[node].prop << ' ' << "BASE" << endl;
        return;
    }

    segVar;
    init(lft, st,  md);
    init(rgt, md+1,ed);

    if(segTree[lft].dif == segTree[rgt].dif) segTree[node] = info(segTree[rgt].val, segTree[rgt].dif, 0);
    else if(segTree[lft].dif < segTree[rgt].dif) segTree[node] = segTree[lft];
    else segTree[node] = segTree[rgt];
//
}

void update(int node, int st, int ed, int l, int r, int val, int prop = 0) {
//    cout << "IN  " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << val << ' ' << prop << " AGE " <<  endl;
//    getchar();
    segTree[node].dif += prop;
    segTree[node].prop+= prop;
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node].dif += val;
        if(st != ed) segTree[node].prop += val;
        return;
    }

    segVar;
    update(lft, st,  md, l,r, val, segTree[node].prop);
    update(rgt, md+1,ed, l,r, val, segTree[node].prop);

//    int prop = segTree[node].prop;
    if(segTree[lft].dif < segTree[rgt].dif) segTree[node] = segTree[lft];
    else segTree[node] = segTree[rgt];
    segTree[node].prop = 0;
//    cout << "OUT " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << val << ' ' << segTree[node].val << ' ' << segTree[node].dif << ' ' << segTree[node].prop << endl;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &x);
            dif[i] = i-x-1;
        }
        init(1, 1, n);
        int ans = 1, cur;
//        for(int i=1; i<=24; i++) {
//            cout << i << ' ' << segTree[i].val << ' ' << segTree[i].dif << ' ' << segTree[i].prop << endl;
//        }
//        BUG(0);

        while( segTree[1].val != 1 ) {
            cur = segTree[1].val;
//            cout << "PRE " << segTree[1].val << ' ' << segTree[1].dif << ' ' << segTree[1].prop << endl;
            update(1, 1,n, cur+1, n, -1 );
//            cout << "1ST " << segTree[1].val << ' ' << segTree[1].dif << ' ' << segTree[1].prop << endl;
            update(1, 1,n, cur, cur, MAX);
//            cout << "2ND " << segTree[1].val << ' ' << segTree[1].dif << ' ' << segTree[1].prop << endl;
            ans++;
        }
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}



