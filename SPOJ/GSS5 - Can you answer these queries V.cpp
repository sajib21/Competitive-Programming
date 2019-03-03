///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     100000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

int n,q, a[LIM+10], prefixSum[LIM+10], suffixSum[LIM+10];
int preSegTree[4*LIM+10], sufSegTree[4*LIM+10];

void initPre(int node, int st, int ed) {
    if(st == ed) {
        preSegTree[node] = prefixSum[st];
        return;
    }
    segVar;
    initPre(lft, st,md); initPre(rgt, md+1,ed);
    preSegTree[node] = max(preSegTree[lft], preSegTree[rgt]);
}
void initSuf(int node, int st, int ed) {
    if(st == ed) {
        sufSegTree[node] = suffixSum[st];
        return;
    }
    segVar;
    initSuf(lft, st,md); initSuf(rgt, md+1,ed);
    sufSegTree[node] = max(sufSegTree[lft], sufSegTree[rgt]);
}

int queryPre(int node, int st, int ed, int l, int r) {
    if(l > r) return prefixSum[r];
    if(st > r || ed < l) return INT_MIN;
    if(st >= l && ed <= r) return preSegTree[node];
    segVar;
    return max( queryPre(lft, st,md, l,r) , queryPre(rgt, md+1,ed, l,r) );
}
int querySuf(int node, int st, int ed, int l, int r) {
    if(l > r) return suffixSum[l];
//    cout << "QSUF " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << sufSegTree[node] << endl; getchar();
    if(st > r || ed < l) return INT_MIN;
    if(st >= l && ed <= r) return sufSegTree[node];
    segVar;
    return max( querySuf(lft, st,md, l,r) , querySuf(rgt, md+1,ed, l,r) );
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(prefixSum, 0, sizeof(prefixSum));
        memset(suffixSum, 0, sizeof(suffixSum));
        memset(preSegTree, 0, sizeof(preSegTree));
        memset(sufSegTree, 0, sizeof(sufSegTree));
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        prefixSum[1] = a[1]; suffixSum[n] = a[n];
        for(int i=2; i<=n; i++)  prefixSum[i] = prefixSum[i-1] + a[i];
        for(int i=n-1; i>0; i--) suffixSum[i] = suffixSum[i+1] + a[i];

//        for(int i=1; i<=n; i++) cout << prefixSum[i] << ' ' ; cout << endl;
//        for(int i=1; i<=n; i++) cout << suffixSum[i] << ' ' ; cout << endl;
//        cout << prefixSum[3] << endl; getchar(); getchar();

        initPre(1, 1,n);
        initSuf(1, 1,n);

//        int x1,y1,x2,y2;
//        x1 = 1, y1 = 1, x2 = 2, y2 = 3;



        scanf("%d", &q);
        while(q--) {
            int x1,Y1, x2,Y2;
            scanf("%d %d %d %d", &x1,&Y1, &x2,&Y2);
            if(Y1 <= x2) {
                int ans = 0;
                ans += prefixSum[x2-1] - prefixSum[Y1];
                ans += querySuf(1, 1,n, x1,Y1) - suffixSum[Y1+1] + queryPre(1, 1,n, x2,Y2) - prefixSum[x2-1];
//                cout << prefixSum[x2-1] << ' ' << prefixSum[Y1] << ' ' << querySuf(1, 1,n, x1,Y1) << ' ' << suffixSum[Y1+1] << ' ' <<  queryPre(1, 1,n, x2,Y2) << ' ' << prefixSum[x2-1] << endl;
                printf("%d\n", ans);
            }
            else {
//                x2 = Y1+1;
                int ans1 = 0, ans2=0;
//                ans1 += querySuf(1, 1,n, x1,Y1) - suffixSum[Y1+1] + queryPre(1, 1,n, Y1+1,Y2) - prefixSum[Y1];
//                cout << "L " << querySuf(1, 1,n, x1,Y1) << ' ' << suffixSum[Y1+1]  << ' ' <<  queryPre(1, 1,n, Y1+1,Y2)  << ' ' <<  prefixSum[Y1] << ' ' << endl;
//                ans2 += querySuf(1, 1,n, x1,x2-1) - suffixSum[x2] + queryPre(1, 1,n, x2,Y2) - prefixSum[x2-1];
//                cout << "R " << querySuf(1, 1,n, x1,x2-1)  << ' ' <<  suffixSum[x2]  << ' ' <<  queryPre(1, 1,n, x2,Y2)  << ' ' <<  prefixSum[x2-1]  << ' ' << endl;
//                printf("%d\n", max(ans1,ans2));
                printf("%d\n", querySuf(1, 1,n, x2,Y2)+queryPre(1, 1,n, x1,Y1)-suffixSum[1]);
            }
        }
    }

    return 0;
}
