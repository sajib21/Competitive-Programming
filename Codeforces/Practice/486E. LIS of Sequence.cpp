#include<bits/stdc++.h>
#define LIM 100005
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

struct info {
    int x,y,z;
    info() {}
    info(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        if(x == b.x) {
            if(y == b.y) z < b.z;
            else return y < b.y;
        }
        return x < b.x;
    }
};

int n, a[LIM], mx, ans, tree[LIM*4], f1[LIM], f2[LIM], mark[LIM], res[LIM];
info segTree[LIM*4];

int query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return tree[node];
    segVar;
    return max( query(lft, st,md, l,r) , query(rgt, md+1,ed, l,r) ) ;
}

void update(int node, int st, int ed, int p, int v) {
//    cout << "UP " << node << ' ' << st << ' ' << ed << ' ' << p << ' ' << v << ' ' << tree[node] << endl; getchar();
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        tree[node] = max(tree[node], v);
//        cout << "NEW " << node << ' ' << st << ' ' << ed << ' ' << tree[node] << endl; getchar();
        return;
    }
    segVar;
    update(lft, st,md, p,v); update(rgt, md+1,ed, p,v);
    tree[node] = max(tree[lft], tree[rgt]);
}

void init(int node, int st, int ed) {
//    cout << "in " << node << ' ' << st << ' ' << ed << endl; getchar();
    if(st == ed) {
        segTree[node] = info(f2[st], a[st], st);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = max(segTree[lft], segTree[rgt]);
}

int query2(int node, int st, int ed, int l, int r, int x, int y) {
//    cout << "QRY " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << x << ' ' << y << " : " << segTree[node].x << ' ' << segTree[node].y << ' ' << segTree[node].z << endl; getchar();
    if(ed < l || st > r) return -1;
    if(st >= l && ed <= r) {
        segVar;
        if(segTree[node].x < x) return -1;
        if(st == ed) {
            if(segTree[node].x == x && segTree[node].y > y) return segTree[node].z;
            return -1;
        }
//        cout << "LFT : " << segTree[lft].x << ' ' << segTree[lft].y << ' ' << segTree[lft].z << endl;
//        cout << "RGT : " << segTree[rgt].x << ' ' << segTree[rgt].y << ' ' << segTree[rgt].z << endl; getchar();

        if(segTree[rgt].x == x && segTree[rgt].y > y) {
            return query2(rgt, md+1,ed, l,r, x,y);
        }
        else if(segTree[lft].x == x && segTree[lft].y > y) {
            if(segTree[rgt].x >= x && segTree[rgt].y > y) return query2(rgt, md+1,ed, l,r, x,y);
            else return query2(lft, st,md, l,r, x,y);
        }
        return -1;
    }
    segVar;
    return max( query2(lft, st,md, l,r, x,y) , query2(rgt, md+1,ed, l,r, x,y) );
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }

    for(int i=0; i<n; i++) {
        int x = query(1, 0,mx, 0,a[i]-1) + 1;
        f1[i] = x;
//        cout << "UPDATE 1 " << i << endl;
        update(1, 0,mx, a[i], x);
//        cout << x << endl;
    }

    memset(tree, 0, sizeof tree);
    for(int i=n-1; i>=0; i--) {
        int x = query(1, 0,mx, a[i]+1,mx) + 1;
        f2[i] = x;
        ans = max(ans, x);
        update(1, 0,mx, a[i], x);
//        cout << "COUNT " << i << ' ' << a[i] << ' ' << x << endl; getchar();
    }

    init(1, 0,n-1);

//    cout << "BUG " << ans << endl;
//for(int i=0; i<n; i++) cout << mark[i] << ' ' ; cout << endl;

    int j = query2(1, 0,n-1, 0,n-1, ans, 0);
    if(j > 0) {
        mark[0]++; mark[j]--;
    }

    for(int i=0; i<n-1; i++) {
        int q = ans - f1[i];
//        cout << "CALL " << i << endl;
        int j = query2(1, 0,n-1, i+1,n-1, q, a[i]);
        cout << i << ' ' << j << endl;
        if(j == -1) continue;
//        if(i+1 < j) {
//            if(a[i] >= a[i+1]) {
//                mark[i]++; mark[j]--;
////                cout << i << " MARKED " << i << ' ' << j << " : " << mark[i] << ' ' << mark[j] << endl;
//            }
//            else {
                mark[i+1]++; mark[j]--;
                cout << i << " MARKED " << i+1 << ' ' << j << " : " << mark[i+1] << ' ' << mark[j] << endl;
//            }

//        }
//        cout << "GOT " << i+1 << ' ' << j-1 << endl;
    }
//    for(int i=0; i<n; i++) cout << mark[i] << ' ' ; cout << endl;
    for(int i=1; i<n; i++) mark[i] += mark[i-1];
//    for(int i=0; i<n; i++) cout << mark[i] << ' ' ; cout << endl;

    for(int i=0; i<n; i++) {
        if(f1[i]+f2[i]-1 < ans) res[i] = 1;
        else if(mark[i]) res[i] = 2;
        else res[i] = 3;
    }

    for(int i=0; i<n; i++) {
//        if(i) printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");

    /*
    debug this case:
    11
    10 10 5 10 5 10 6 9 12 7 8
    */

//    b[0]   = f1[0]  ;  for(int i=1; i<n; i++)     b[i] = max(b[i-1], f1[i]);
//    b[n-1] = f2[n-1];  for(int i=n-2; i>=0; i--)  b[i] = max(b[i+1], f2[i]);
//
//    for(int i=0; i<n; i++) {
//        int x=0,y=0;
//        if(i) x = f1[i-1];
//        if(i<n-1) y = f2[i+1];
//        if(x+y)
//
//        if(f1[i]+f2[i]-1 < l) printf("1");
//        else if(f[i])
//
//    }
}
