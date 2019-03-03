#include<bits/stdc++.h>
#define MX 100005

using namespace std;

struct maxMin {
    int mx, mn;
    maxMin() {};
    maxMin(int _mx, int _mn) {
        mx = _mx, mn = _mn;
    }
};

int n, d, num[MX];
maxMin tree[3*MX];

void init(int node, int st, int ed) {

//    cout << "beg " << node << endl;

    if(st == ed) {
        tree[node].mx = tree[node].mn = num[st];
        return;
    }

    int left = 2*node, right = left+1, mid = (st+ed)/2;
    init(left, st, mid);
    init(right, mid+1, ed);
    tree[node].mx = max(tree[left].mx , tree[right].mx);
    tree[node].mn = min(tree[left].mn , tree[right].mn);
//    cout << node << endl;
}

maxMin query(int node, int st, int ed, int l, int r) {

//    cout << "beg " << node << endl;
//    getchar();
    if(ed < l || st > r) return maxMin(INT_MIN, INT_MAX);
    if(st >= l && ed <= r) return tree[node];

    int left = 2*node, right = 2*node+1, mid = (st+ed)/2;
    maxMin q1 = query(left, st,mid, l,r), q2 = query(right, mid+1, ed, l,r);

    return maxMin( max(q1.mx, q2.mx) , min(q1.mn, q2.mn) );
//    cout << node << endl;
}

int main() {

    int t,T;
    cin >> T;
    for(t=1; t<=T; t++){

        cin >> n >> d;
        for(int i=1; i<=n; i++) scanf("%d", &num[i]);
        init(1, 1,n);

//        cout << "done 1" << endl;

        int ans = INT_MIN;
        maxMin temp;
        for(int i=d; i<=n; i++) {
            temp = query(1, 1,n, i-d+1, i);
            ans = max(ans, temp.mx - temp.mn );

        }

        printf("Case %d: %d\n", t, ans);

    }

    return 0;
}
