#include<bits/stdc++.h>
#define COMPLETE 2
#define SINGLE 1

using namespace std;

int n,m;
int ara[100005];

int inDp[100005];
int deDp[100005];

int increasing(int indx) {

//    cout << indx << endl;

    if(indx == n) return inDp[indx] = indx;

    if(inDp[indx] != 0) return inDp[indx];

    if(ara[indx+1] >= ara[indx] ) inDp[indx] = increasing(indx+1);
    else inDp[indx] = indx;

    return inDp[indx];
}

int decreasing(int indx) {

    if(indx == 1) return deDp[indx] = indx;

    if(deDp[indx] != 0) return deDp[indx];

    if(ara[indx-1] >= ara[indx] ) deDp[indx] = decreasing(indx-1);
    else deDp[indx] = indx;
    return deDp[indx];
}

int main() {

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);

    int l,r;
    for(int i=0; i<m; i++) {
        scanf("%d %d", &l,&r);
        int ll = increasing(l), rr = decreasing(r);
//        cout << ll << ' ' << rr << endl;
        if(ll >= rr) printf("Yes\n");
        else printf("No\n");

    }

    return 0;
}
