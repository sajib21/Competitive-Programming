#include<bits/stdc++.h>
#define LIM 50000
#define ll long long int

using namespace std;

struct node {

    ll total, bestSum, prefixSum, suffixSum;

    node() {
        total = INT_MIN, bestSum = INT_MIN, prefixSum = INT_MIN, suffixSum = INT_MIN;
    }
    node(ll t, ll b, ll p, ll s) {
        total = t, bestSum = b, prefixSum = p, suffixSum = s;
    }
};

int n,m, ara[LIM + 10];
node segTree[6*LIM + 100];

void initMax(int indx, int st, int ed) {

    if(st == ed) {
        segTree[indx] = node(ara[st], ara[st], ara[st], ara[st]);
        return;
    }

    int lft = indx << 1 , rgt = (indx << 1) + 1 , mid = (st+ed)/2;
    initMax(lft, st,mid);
    initMax(rgt, mid+1, ed);

    segTree[indx].total = segTree[lft].total + segTree[rgt].total;
    segTree[indx].prefixSum = max(segTree[lft].prefixSum , segTree[lft].total + segTree[rgt].prefixSum);
    segTree[indx].suffixSum = max(segTree[rgt].suffixSum , segTree[rgt].total + segTree[lft].suffixSum);
    segTree[indx].bestSum   = max(segTree[lft].suffixSum + segTree[rgt].prefixSum , max(segTree[lft].bestSum , segTree[rgt].bestSum));
}

void update(int indx, int st, int ed, int pos, int val) {

    if(ed < pos || st > pos) return;
    if(st == ed && st == pos) {
        segTree[indx] = node(val, val, val, val);
        return;
    }

    int lft = indx << 1 , rgt = (indx << 1) + 1 , mid = (st+ed)/2;
    update(lft, st,mid, pos, val);
    update(rgt, mid+1, ed, pos, val);

    segTree[indx].total = segTree[lft].total + segTree[rgt].total;
    segTree[indx].prefixSum = max(segTree[lft].prefixSum , segTree[lft].total + segTree[rgt].prefixSum);
    segTree[indx].suffixSum = max(segTree[rgt].suffixSum , segTree[rgt].total + segTree[lft].suffixSum);
    segTree[indx].bestSum   = max(segTree[lft].suffixSum + segTree[rgt].prefixSum , max(segTree[lft].bestSum , segTree[rgt].bestSum));
}

node queryMax(int indx, int st, int ed, int l, int r) {

    if(ed < l || st > r) return node();
    if(st >= l && ed <= r) return segTree[indx];

    int lft = indx << 1 , rgt = (indx << 1) + 1 , mid = (st+ed)/2;
    node left = queryMax(lft, st,mid, l,r) , right = queryMax(rgt, mid+1, ed, l,r);

    node temp;
    temp.total = left.total + right.total;
    temp.prefixSum = max(left.prefixSum , left.total + right.prefixSum);
    temp.suffixSum = max(right.suffixSum , right.total + left.suffixSum);
    temp.bestSum   = max(left.suffixSum + right.prefixSum , max(left.bestSum , right.bestSum));
    return temp;
}

int main() {

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
    initMax(1, 1,n);
    scanf("%d", &m);
    while(m--) {
        int c, l,r;
        scanf("%d %d %d",&c, &l,&r);
        if(c == 0) update(1, 1,n, l, r);
        else printf("%lld\n", queryMax(1, 1,n, l,r).bestSum);
    }

    return 0;
}

