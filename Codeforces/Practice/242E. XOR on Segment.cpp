///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
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

struct info{
    ll x[22],y,z;
    info() {memset(x, 0, sizeof(x)); y = 0; z=0;}
    info(ll xx[], ll yy = 0, int zz = 0) {
        for(int i=0; i<20; i++) x[i] = xx[i];
        y = yy; z = zz;
    }
};

int n,q, ara[LIM+10];
info segTree[4*LIM+10];

void init(int node, int st, int ed) {
    if(st == ed) {
        int num = ara[st];
        for(int i=0; i<20; i++) {
            segTree[node].x[i] += num%2;
            num /= 2;
        }
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    for(int i=0; i<20; i++) segTree[node].x[i] = segTree[lft].x[i] + segTree[rgt].x[i];
}

void update(int node, int st, int ed, int l, int r, int val, int prop = 0) {
    segTree[node].y ^= prop;
    int num = prop;
    for(int i=0; i<20; i++, num/=2) if(num%2) segTree[node].x[i] = (ed-st+1 - segTree[node].x[i]);

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {

//        cout << "BEFORE " << st << ' ' << ed << endl;
//        for(int i=0; i<20; i++) cout << segTree[node].x[i] << ' ' ; cout << endl;

        segTree[node].y ^= val;
        for(int i=0; i<20; i++) {
            if(val%2) segTree[node].x[i] = (ed-st+1 - segTree[node].x[i]);
            val /= 2;
        }

//        cout << "AFTER  " << st << ' ' << ed << endl;
//        for(int i=0; i<20; i++) cout << segTree[node].x[i] << ' ' ; cout << endl;
        return;
    }
    segVar;
    update(lft, st,md, l,r, val, segTree[node].y); update(rgt, md+1,ed, l,r, val, segTree[node].y);
    for(int i=0; i<20; i++) segTree[node].x[i] = segTree[lft].x[i] + segTree[rgt].x[i];
    segTree[node].y = 0;
}

ll query(int node, int st, int ed, int l, int r, int prop = 0) {



    segTree[node].y ^= prop;
    int num = prop;
    for(int i=0; i<20; i++, num/=2) if(num%2) segTree[node].x[i] = (ed-st+1 - segTree[node].x[i]);

//    cout << "QRY " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << prop << ' ' << segTree[node].y << endl;
//    for(int i=0; i<20; i++) cout << segTree[node].x[i] ; cout << endl;
//    getchar();



    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) {
//        cout << "PROP " << prop << endl;
//        cout << "SEG  " << node << ' ' << st << ' ' << ed << endl;
//        for(int i=0; i<20; i++) cout << segTree[node].x[i] << ' ' ; cout << endl << endl;


        ll ans=0;
//        segTree[node].y ^= val;
        for(ll i=0, b=1; i<20; i++, b*=2) {
            ans += segTree[node].x[i] * b;
//            cout << cnt << ' ' ;
            prop /= 2;
        }
//        cout << endl;
//        cout << "EKHANE " << ans << endl;
        return ans;
    }
    segVar;
    ll an = query(lft, st,md, l,r, segTree[node].y) + query(rgt, md+1,ed, l,r, segTree[node].y);
    segTree[node].y = 0;
    return an;
}


int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
    init(1, 1,n);

//    for(int i=0; i<20; i++) printf("%3d", segTree[9].x[i]); cout << endl;

    scanf("%d", &q);
    while(q--) {
        int c,x,y,z;
        scanf("%d", &c);
        if(c == 1) {
            scanf("%d %d", &x,&y);
//            for(int i=0; i<5; i++) cout << segTree[1].x[
            printf("%I64d\n", query(1, 1,n, x,y));
        }
        else {
            scanf("%d %d %d", &x,&y,&z);
            update(1, 1,n, x,y, z);
        }
        //            if(x == 2 && y == 5)
//        for(int x=1; x<=9; x++) {for(int i=0; i<20; i++) printf("%3d", segTree[x].x[i]); cout << endl; }
    }


    return 0;
}
