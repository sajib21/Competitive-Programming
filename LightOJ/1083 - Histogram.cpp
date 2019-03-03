#include<bits/stdc++.h>
#define MX 30009
//#define ll long long int

using namespace std;

int n, heights[MX];
int minTree[3*MX];
//int areaTree[10*MX];


void initMinTree(int node, int st, int ed) {

    if(st > ed) return;
    if(st == ed) {
        minTree[node] = st;
        return;
    }

    int left = node << 1, right = (node << 1) + 1, mid = (st+ed)/2;

    initMinTree(left, st,mid);
    initMinTree(right, mid+1, ed);
    if( heights[ minTree[left] ] <= heights[ minTree[right] ] ) minTree[node] = minTree[left];
    else minTree[node] = minTree[right];
}

int query(int node, int st, int ed, int l, int r) {

    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return minTree[node];

    int left = node << 1, right = (node << 1) + 1, mid = (st+ed) / 2;
    int a = query(left, st,mid, l,r);
    int b = query(right, mid+1, ed, l,r);

    if(heights[a] <= heights[b]) return a;
    else return b;
}

int initAreaTree(int st, int ed) {

    if(st < 1 || ed < 1 || st > n || ed > n || st > ed) return 0;
    if(st > ed) return 0;
    if(st == ed) {
//        areaTree[node] = heights[st];
        return heights[st];
    }

//    ll left = node << 1, right = (node << 1) + 1,
    int mid = query(1, 1,n, st, ed);
    int p = initAreaTree(st, mid - 1);
    int q = initAreaTree(mid + 1, ed);

    int temp = (ed-st+1) * heights[mid];
    if( p > temp ) temp = p;
    if( q > temp ) temp = q;

    return temp;
}

int main() {

    int T;
//    cin >> T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(minTree, 0, sizeof(minTree));
//        memset(areaTree, 0, sizeof(areaTree));
        scanf("%d", &n);
        heights[0] = heights[n+1] = heights[n+2] = heights[n+3] = MX;
//        for(int i=n+1; i<2*n; i++) heights[i] = MX;

        for(int i=1; i<=n; i++) scanf("%d", &heights[i]);
        initMinTree(1, 1,n);


        printf("Case %d: %d\n", t, initAreaTree(1,n) );
    }

    return 0;

}
