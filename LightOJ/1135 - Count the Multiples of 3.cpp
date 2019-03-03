#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

struct info {

    int zero, one, two;
    int prop;
    info() {
        zero = one = two = prop = 0;
    }
    info(int ii, int nn, int mm, int pp) {
        zero = ii; one = nn; two = mm; prop = pp;
    }
};

int n, q;
int ara[LIM+10];
info segTree[4*LIM+10];

void init(int node, int st, int ed) {
    if(st == ed) {
        int op = ara[st] % 3;
        if(op==0) segTree[node].zero++;
        else if(op==1) segTree[node].one++;
        else segTree[node].two++;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    init(lft, st,  md);
    init(rgt, md+1, ed);
    segTree[node].zero = segTree[lft].zero + segTree[rgt].zero;
    segTree[node].one = segTree[lft].one + segTree[rgt].one;
    segTree[node].two = segTree[lft].two + segTree[rgt].two;
}

info query(int node, int st, int ed, int l, int r, int carry=0) {
//    cout << "IN Q " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << carry << endl;
    if(ed < l || st > r) return info();
    if(st >= l && ed <= r) {
        carry %= 3;
        if(carry==0) return segTree[node];
        else if(carry==1) return info(segTree[node].two, segTree[node].zero, segTree[node].one, 0);
        else return info(segTree[node].one, segTree[node].two, segTree[node].zero, 0);
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    info a,b;
    a = query(lft, st, md, l, r, carry+segTree[node].prop);
    b = query(rgt, md+1, ed, l, r, carry+segTree[node].prop);
    return info( a.zero+b.zero , a.one+b.one , a.two+b.two, 0);
}

void update(int node, int st, int ed, int l, int r) {
    cout << "INSIDE UP " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << segTree[node].prop <<endl;

    if(ed < l || st > r ) return;
    if(st >= l && ed <= r) {
        segTree[node] = info(segTree[node].two , segTree[node].zero, segTree[node].one, segTree[node].prop);
        segTree[node].prop++;
//        segTree[node].prop++;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update(lft, st,  md, l,r);
    update(rgt, md+1,ed, l,r);
//    int pp = segTree[node].prop;
    segTree[node].zero = segTree[lft].zero + segTree[rgt].zero ;
    segTree[node].one = segTree[lft].one + segTree[rgt].one ;
    segTree[node].two = segTree[lft].two + segTree[rgt].two ;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) ara[i] = i-1 ;

        memset(segTree, 0, sizeof(segTree));
        init(1, 1, n);
//for(int i=1; i<=4*n; i++) cout << i << " : " << segTree[i].zero << ' ' << segTree[i].one << ' ' << segTree[i].two << endl;
        printf("Case %d:\n", t);
        for(int qq=1; qq<=q; qq++) {
            int c,i,j;
            scanf("%d %d %d", &c,&i,&j);
            if(!c) {
                update(1, 1,n, i+1, j+1);
                cout << "FULL UP " << segTree[1].zero << ' ' << segTree[1].one << ' ' << segTree[1].two << endl;
//                for(int i=1; i<=4*n; i++) cout << segTree[i]
            }
            else {
                info an = query(1, 1,n, i+1,j+1, 0);
                cout << "NOW " << an.zero << ' ' << an.one << ' ' << an.two << endl;
                printf("%d\n", an.zero);
                cout << "FULL Q  " << segTree[1].zero << ' ' << segTree[1].one << ' ' << segTree[1].two << endl;
            }

            for(int i=1; i<=4*n; i++) cout << i << " : " << segTree[i].zero << ' ' << segTree[i].one << ' ' << segTree[i].two << endl;


        }
//        printf("Case %d: %d\n", t, segTree[1] );



    }
    return 0;

}


