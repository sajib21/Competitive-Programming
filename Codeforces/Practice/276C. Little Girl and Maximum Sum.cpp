#include<bits/stdc++.h>
#define MX 200005
#define ll long long int
using namespace std;

struct info{

    ll sum, prop;
};

int n,q;
ll ara[MX], freq[MX];
info tree[3*MX];

void update(int node, int st, int ed, int l, int r) {

    if(r < st || l > ed) return;
    if(st >= l && ed <= r) {
        tree[node].prop++;
        tree[node].sum += (ed - st + 1);
        return;
    }

    int left = node*2, right = left+1, mid = (st+ed)/2;
    update(left, st,mid, l,r);
    update(right, mid+1,ed, l,r);
    tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop * (ed - st + 1);

    return;
}

ll query(int node, int st, int ed, int n, ll carry) {

    if(n < st || n > ed) return 0;

    if(st == n && ed == n) return tree[node].sum + carry;

    int left = node*2, right = left+1, mid = (st+ed)/2;

    return query(left, st,mid, n, carry + tree[node].prop) + query(right, mid+1,ed, n, carry + tree[node].prop);
}

int main() {

    scanf("%d %d", &n,&q);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
    sort(ara+1, ara+n+1);

    for(int i=0; i<q; i++) {
        int l,r;
        scanf("%d %d", &l,&r);
        update(1, 1,n, l,r);
    }

//    cout << "bug" << endl;

    for(int i=1; i<=n; i++) freq[i] = query(1, 1,n, i, 0);
    sort(freq+1, freq+n+1);

    ll res = 0;
    for(int i=1; i<=n; i++) res += (ll) ara[i]*freq[i];

    printf("%lld\n", res);

    return 0;
}
