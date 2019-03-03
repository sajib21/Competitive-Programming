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

using namespace std;

struct info{
    int x,y;
    info() {}
    info(int xx, int yy) {
        x = xx; y = yy;
    }
};
bool cmp (info x, info y) {
    return x.x < y.x;
}

info blu[LIM+10], red[LIM+10];
int nxtPtr[LIM+10], prePtr[LIM+10];

int ub(int lo, int hi, int val) {
    int md;
    bool f = false;
    while(lo < hi) {
        md = (lo + hi ) >> 1;
        if(red[md].y <= val) lo = md;
        else hi = md;

        if(lo+1 == hi) {
            if(f) break;
            f = true;
        }
    }
    return hi;
}
int pb(int lo, int hi, int val) {
    int md;
    bool f = false;
    while(lo < hi) {
        md = (lo + hi + 1) >> 1;
        if(red[md].y < val) lo = md;
        else hi = md;

        if(lo+1 == hi) {
            if(f) break;
            f = true;
        }
    }
    return lo;
}

int n,m;

int main() {

//    freopen("1103i.txt", "r", stdin);
//    freopen("1103o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        blu[0].x = blu[0].y = red[0].x = red[0].y = 0;
        for(int i=1; i<=n; i++) scanf("%d %d", &blu[i].x, &blu[i].y);
        for(int i=1; i<=m; i++) scanf("%d %d", &red[i].x, &red[i].y);
        sort(blu, blu+n+1, cmp);
        sort(red, red+m+1, cmp);
        memset(nxtPtr, -1, sizeof(nxtPtr));
        memset(prePtr, 0, sizeof(prePtr));
        for(int j=1, i=1; i<=n && j<=m; ) {
            if(blu[i].x < red[j].x) nxtPtr[i++] = j;
            else j++;
        }
        for(int j=m, i=n; i>0 && j>0; ) {
            if(blu[i].x > red[j].x) prePtr[i--] = j;
            else j--;
        }
//        cout << "NXT " << endl;
//        for(int i=0; i<=n+1; i++) cout << i << ' ' << nxtPtr[i] << endl;
//        cout << "PRE " << endl;
//        for(int i=0; i<=n+1; i++) cout << i << ' ' << prePtr[i] << endl;


        ll ans = 0;
//        cout << "N " << n << endl;
        for(int b=1; b<=n; b++) {
//            if(blu[b].x <= blu[b].y) { ///THROWING IN RIGHT DIRECTION
                int r = nxtPtr[b];
            if(r != -1) {
//                    continue;
                ans += 1LL + ub(r, m+1, blu[b].y) - r - 1LL;
//                cout << b << " RIGHT " << ub(r, m+1, blu[b].y) - r << endl;
            }
//            if(blu[b].x >= blu[b].y) { ///THROWING IN LEFT DIRECTION
                r = prePtr[b];
            if(r) {
//                    continue;
                ans += 1LL + r - pb(0, r, blu[b].y) - 1LL;
//                cout << b << " LEFT  " << r - pb(0, r, blu[b].y) << endl;
            }
        }
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
