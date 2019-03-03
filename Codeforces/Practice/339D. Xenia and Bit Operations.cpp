#include<bits/stdc++.h>
#define XOR 0
#define OR 1
#define MX 132000

using namespace std;

int nn, n,m, p,b;
int ara[MX], tree[3*MX];

void init(int node, int b, int e, int what) {

    if(b == e) {
        tree[node] = ara[b];
        return;
    }

    int left = node*2, right = left+1;
    int mid = (b+e)/2;
    init(left, b,mid, !what);
    init(right, mid+1, e, !what);

    if(what == XOR) tree[node] = tree[left] ^ tree[right];
    else tree[node] = tree[left] | tree[right];

    return;
}

void update(int node, int b, int e, int pos, int newVal, int what) {

    if(b > pos || e < pos) return ;

    if(b == e && b == pos) {
        tree[node] = newVal;
        return;
    }

    int left = node*2, right = left+1;
    int mid = (b+e)/2;
    update(left, b,mid, pos,newVal, !what);
    update(right, mid+1, e, pos,newVal, !what);

    if(what == XOR) tree[node] = tree[left] ^ tree[right];
    else tree[node] = tree[left] | tree[right];

    return;
}

int main() {

    scanf("%d %d", &nn, &m);
    n = 1<<nn;
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);

    int w = nn%2==0? XOR : OR;
    init(1, 1,n, w);

    for(int i=0; i<m; i++) {
        scanf("%d %d", &p, &b);
        update(1, 1,n, p, b, w);
        printf("%d\n", tree[1]);
    }

    return 0;
}
