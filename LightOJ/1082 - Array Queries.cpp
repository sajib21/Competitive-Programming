#include<bits/stdc++.h>
#define IM 100005
using namespace std;

int nums[IM], segTree[IM*3];

void init(int node, int st, int ed) {

    if(st==ed) {
        segTree[node] = nums[st];
        return;
    }

    int left = node*2, right = left+1;
    int mid = (st+ed)/2;

    init(left, st,mid);
    init(right, mid+1,ed);
    segTree[node] = min( segTree[left], segTree[right] );
}

int query(int node, int st, int ed, int a, int b) {

    if(a > ed || b < st) {
        return INT_MAX;
    }
    else if(st >= a && ed <= b) {
        return segTree[node];
    }

    int left = node*2, right = left+1;
    int mid = (st+ed)/2;
    return min( query(left, st,mid, a,b), query(right, mid+1,ed, a,b) );
}



int main() {

    int T,t;
    cin >> T;
    for(t=1; t<=T; t++) {
        int n,q;
        scanf("%d %d", &n, &q);

        for(int i=1; i<=n; i++) {
            scanf("%d", &nums[i]);
        }
        init(1, 1,n);

        //cout << "debug" << endl;

        printf("Case %d:\n", t);
        for(int i=0; i<q; i++) {
            int a,b;
            scanf("%d %d", &a,&b);
            printf("%d\n", query(1, 1,n, a,b));
        }
    }

    return 0;
}
