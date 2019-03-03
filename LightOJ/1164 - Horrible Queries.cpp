#include<bits/stdc++.h>
#define MX 100005
#define ll long long int

using namespace std;

struct info {

    ll sum, prop;
    info() {};
    info(ll s, ll p) {
        sum = s, prop = p;
    }
};

int n,q, c,x,y,v;
info tree[3*MX];

void update(int node, int st, int ed, int ql, int qr, ll v) {

    if(ed < ql || st > qr) return;
    if(st >= ql && ed <= qr) {
        tree[node].sum += (ed-st+1)*v;
        tree[node].prop += v;
        return;
    }

    int left = node << 1, right = (node << 1) + 1, mid = (st+ed)/2;
    update(left, st,mid, ql,qr, v);
    update(right, mid+1,ed, ql,qr, v);
    tree[node].sum = tree[left].sum +
        tree[right].sum + (ed-st+1)*tree[node].prop;
}

ll query(int node, int st, int ed, int ql, int qr, ll carry = 0) {

    if(ed < ql || st > qr) return 0;
    if(st >= ql && ed <= qr) return tree[node].sum + (ed-st+1)*carry;

    int left = node << 1 , right = (node << 1) + 1 , mid = (st+ed)/2;
    return query(left, st, mid, ql, qr, carry + tree[node].prop) +
        query(right, mid+1, ed, ql,qr, carry+tree[node].prop);
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        memset(tree, 0, sizeof(tree));
        scanf("%d %d", &n,&q);
//        printf("Case %d:\n", t);

//        cout << "FIRST Q " << q << endl;

        while(q--) {
            scanf("%d", &c);
            if(!c) {
                scanf("%d %d %d", &x,&y,&v); //x++, y++;
                update(1, 1,n, x,y, v);
            }
            else {
                scanf("%d %d", &x,&y); //x++,y++;
                if(x > y) swap(x,y);
                printf("%lld\n", query(1, 1,n, x,y));
            }
//            cout << "q is " << q << endl;
        }
//        cout << "q sesh " << endl;
    }

    return 0;
}
