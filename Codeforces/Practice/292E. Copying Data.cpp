#include<btis/stdc++.h>
#define LIM 100005

using namespace std;

int n, a[LIM], b[LIM], segTree[4*LIM];

void update(int node, int st, int ed, int l, int r, int x, int k) {
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node] = l - st + x;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) scanf("%d", &b[i]);

    while(m--) {
        scanf("%d", &c);
        if(c == 1) {
            scanf("%d %d %d", &x,&y,&k);
            update(1, 1,n, y, y+k, x,k);
        }
        else {

        }
    }
}
