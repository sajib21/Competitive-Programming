#include<bits/stdc++.h>
#define IM 100005
using namespace std;

int sack[IM], totl[IM*3];

void init(int node, int st, int ed) {

    if(st==ed) {
        totl[node] = sack[st];
        return;
    }

    int left = node*2, right = left+1;
    int mid = (st+ed)/2;
    init(left, st, mid); init(right, mid+1, ed);
    totl[node] = totl[left] + totl[right];
}

int query(int node, int st, int ed, int a, int b) {

    if(a > ed || b < st) {
        return 0;
    }
    else if(st >= a && ed <= b) {
        return totl[node];
    }

    int left = node*2, right = left+1;
    int mid = (st+ed)/2;
    return query(left, st,mid, a,b) + query(right, mid+1,ed, a,b);
}

void update(int node, int st, int ed, int a, int upValue) {

    if(a > ed || a < st) {
        return;
    }
    else if(st >= a && ed <=a) {
        totl[node] = upValue;
        return;
    }

    int left = node*2, right = left+1;
    int mid = (st+ed)/2;
    update(left, st, mid, a, upValue);
    update(right, mid+1, ed, a, upValue);
    totl[node] = totl[left] + totl[right];
}

int main() {

    int T,t;
    cin >> T;
    for(t=1; t<=T; t++) {
        int n,q;
        scanf("%d %d", &n,&q);
        for(int i=1; i<=n; i++) {
            scanf("%d", &sack[i]);
        }
        init(1, 1,n);

        printf("Case %d:\n", t);
        for(int i=0; i<q; i++) {
            int sn, c1, c2;
            scanf("%d", &sn);
            if(sn == 1) {
                scanf("%d", &c1);
                printf("%d\n", query(1, 1,n, c1+1, c1+1));
                update(1, 1,n, c1+1,0);
            }
            else if(sn == 2) {
                scanf("%d %d", &c1, &c2);
                int pr = query(1, 1,n, c1+1, c1+1);
                update(1, 1,n, c1+1, pr+c2);
            }
            else {
                scanf("%d %d", &c1, &c2);
                printf("%d\n", query(1, 1,n, c1+1, c2+1));
            }
        }
    }

    return 0;
}
