#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

struct info {

    int val;
    int prop;
    info() {
        val = prop = 0;
    }
    info(int vv, int pp) {
        val = vv; prop = pp;
    }
};

int n, q;
int ara[LIM+10];
info segTree[4*LIM+10];

int query(int node, int st, int ed, int l, int r, int pre=-1) {
//    cout << "IN Q " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << carry << endl;
    info temp = segTree[node];
    if(pre != -1) {
        temp.val = pre*(ed-st+1);
        temp.prop = pre;
    }
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) {
        return temp.val;
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    int a,b;
    a = query(lft, st, md, l, r, temp.prop);
    b = query(rgt, md+1, ed, l, r, temp.prop);

    return a + b;
}

void update(int node, int st, int ed, int l, int r, int v, int pre = -1) {
//    cout << "INSIDE UP " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << v << ' ' << pre <<endl;
    if(pre != -1) {
        segTree[node].val = pre*(ed-st+1);
        segTree[node].prop = pre;
    }
    if(ed < l || st > r ) return;
    if(st >= l && ed <= r) {
        segTree[node].val = v*(ed-st+1);
        segTree[node].prop = v;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update(lft, st,  md, l,r, v, segTree[node].prop);
    update(rgt, md+1,ed, l,r, v, segTree[node].prop);
    segTree[node].val = segTree[lft].val + segTree[rgt].val;
    segTree[node].prop = -1;

}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &q);
        memset(segTree, 0, sizeof(segTree));
        for(int i=1; i<=4*n; i++) segTree[i].prop = -1;

        printf("Case %d:\n", t);
        for(int qq=1; qq<=q; qq++) {
            int c,i,j, v;
            scanf("%d", &c);

            if(c==1) {
                scanf("%d %d %d", &i,&j, &v);
                update(1, 1,n, i+1, j+1, v, -1);
//                cout << "AGTER UP " << segTree[1].val << ' ' << segTree[2].val << ' ' << segTree[3].val << ' ' << segTree[4].val << ' ' << segTree[6].val << endl;
//                cout << "FULL UP " << segTree[1].zero << ' ' << segTree[1].one << ' ' << segTree[1].two << endl;
//                for(int i=1; i<=4*n; i++) cout << segTree[i]
            }
            else {
                scanf("%d %d", &i,&j);
                int an = query(1, 1,n, i+1,j+1);
//                cout << "NOW " << an.zero << ' ' << an.one << ' ' << an.two << endl;
                int d = j-i+1;
                int g = __gcd(an, d);
                printf("%d", an/g);
                if(d/g != 1) printf("/%d\n", d/g);
                else printf("\n");
//                cout << "FULL Q  " << segTree[1].zero << ' ' << segTree[1].one << ' ' << segTree[1].two << endl;
            }

//            for(int i=1; i<=4*n; i++) cout << i << " : " << segTree[i].zero << ' ' << segTree[i].one << ' ' << segTree[i].two << endl;


        }
//        printf("Case %d: %d\n", t, segTree[1] );



    }
    return 0;

}



