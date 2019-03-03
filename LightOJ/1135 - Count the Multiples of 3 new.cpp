#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

struct info {

    int cnt[4] ;
    int prop;
    info() {
//        zero = one = two = prop = 0;
        cnt[0] = cnt[1] = cnt[2] = prop = 0;
    }
    info(int ii, int nn, int mm, int pp) {
        cnt[0] = ii; cnt[1] = nn; cnt[2] = mm; prop = pp;
    }
};

int n, q;
int ara[LIM+10];
info segTree[4*LIM+10];

void init(int node, int st, int ed) {
    if(st == ed) {
        int op = ara[st] % 3;
        segTree[node].cnt[op]++;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    init(lft, st,  md);
    init(rgt, md+1, ed);
    segTree[node].cnt[0] = segTree[lft].cnt[0] + segTree[rgt].cnt[0];
    segTree[node].cnt[1] = segTree[lft].cnt[1] + segTree[rgt].cnt[1];
    segTree[node].cnt[2] = segTree[lft].cnt[2] + segTree[rgt].cnt[2];
}

int query(int node, int st, int ed, int l, int r, int carry) {
//    cout << "IN Q " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << carry << endl;
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) {
        info tempo = segTree[node];
        if(carry%3 > 0) {
            int temp = tempo.cnt[0];
            tempo.cnt[0] = tempo.cnt[2];
            tempo.cnt[2] = tempo.cnt[1];
            tempo.cnt[1] = temp;
        }
        if(carry%3 > 1) {
            int temp = tempo.cnt[0];
            tempo.cnt[0] = tempo.cnt[2];
            tempo.cnt[2] = tempo.cnt[1];
            tempo.cnt[1] = temp;
        }



        return tempo.cnt[ 0 ];
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    int a,b;
    a = query(lft, st, md, l, r, carry+segTree[node].prop);
    b = query(rgt, md+1, ed, l, r, carry+segTree[node].prop);
    return a + b;
}

void update(int node, int st, int ed, int l, int r) {
//    cout << "INSIDE UP " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << segTree[node].prop <<endl;

    if(ed < l || st > r ) return;
    if(st >= l && ed <= r) {
        int temp = segTree[node].cnt[0];
        segTree[node].cnt[0] = segTree[node].cnt[2];
        segTree[node].cnt[2] = segTree[node].cnt[1];
        segTree[node].cnt[1] = temp;

        segTree[node].prop++;
//        segTree[node].prop++;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update(lft, st,  md, l,r);
    update(rgt, md+1,ed, l,r);
//    int pp = segTree[node].prop;
    segTree[node].cnt[0] = segTree[lft].cnt[0] + segTree[rgt].cnt[0];
    segTree[node].cnt[1] = segTree[lft].cnt[1] + segTree[rgt].cnt[1];
    segTree[node].cnt[2] = segTree[lft].cnt[2] + segTree[rgt].cnt[2];

    if(segTree[node].prop%3 > 0) {
        int temp = segTree[node].cnt[0];
        segTree[node].cnt[0] = segTree[node].cnt[2];
        segTree[node].cnt[2] = segTree[node].cnt[1];
        segTree[node].cnt[1] = temp;
    }
    if(segTree[node].prop%3 > 1) {
        int temp = segTree[node].cnt[0];
        segTree[node].cnt[0] = segTree[node].cnt[2];
        segTree[node].cnt[2] = segTree[node].cnt[1];
        segTree[node].cnt[1] = temp;
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) ara[i] = 0 ;

        memset(segTree, 0, sizeof(segTree));
        init(1, 1, n);
//for(int i=1; i<=4*n; i++) cout << i << " : " << segTree[i].zero << ' ' << segTree[i].one << ' ' << segTree[i].two << endl;
        printf("Case %d:\n", t);
        for(int qq=1; qq<=q; qq++) {
            int c,i,j;
            scanf("%d %d %d", &c,&i,&j);
            if(!c) {
                update(1, 1,n, i+1, j+1);
//                cout << "FULL UP " << segTree[1].zero << ' ' << segTree[1].one << ' ' << segTree[1].two << endl;
//                for(int i=1; i<=4*n; i++) cout << segTree[i]
            }
            else {
                int an = query(1, 1,n, i+1,j+1, 0);
//                cout << "NOW " << an.zero << ' ' << an.one << ' ' << an.two << endl;
                printf("%d\n", an);
//                cout << "FULL Q  " << segTree[1].zero << ' ' << segTree[1].one << ' ' << segTree[1].two << endl;
            }

//            for(int i=1; i<=4*n; i++) cout << i << " : " << segTree[i].zero << ' ' << segTree[i].one << ' ' << segTree[i].two << endl;


        }
//        printf("Case %d: %d\n", t, segTree[1] );



    }
    return 0;

}


