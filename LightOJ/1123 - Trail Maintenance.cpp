#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)

using namespace std;

struct info {
    int u, v, key;
    info() {}
    info(int uu, int vv, int kk) {
        u = uu; v = vv; key = kk;
    }

};

bool cmp (info a, info b) {
        return a.key < b.key;
    }

int n,w;
info edge[220];
int par[220];
int sz;

int findPar(int u) {
    if(par[u] == u) return u;
    return par[u] = findPar(par[u]);
}

inline bool isSorted(info arr[]) {
    for(int i=1; i<sz; i++) {
        if(arr[i].key < arr[i-1].key) return false;
    }
    return true;
}

inline void print() {
    for(int i=0; i<sz; i++) {
        cout << edge[i].key << " ";
    }
    puts("");
}

int mst(int root) {
//    print();
    for(int i=sz-1; i>0; i--) {
        if(edge[i].key < edge[i-1].key) swap(edge[i], edge[i-1]);
    }
//    sort(edge, edge+sz, cmp);
//    print();
//    assert(isSorted(edge));
    for(int i=1; i<=n; i++) par[i] = i;

    int mst=0, cnt=1, flag[220] = {0};

    int l = sz;
    for(int i=0; i<l; i++) {
        info e = edge[i];
        int u = e.u , v = e.v , k = e.key;
        if(findPar(u) != findPar(v)) {
            par[par[u]] = par[v];
            mst += k;
            cnt++;
//            flag[u] = flag[v] = 1;
        }
    }
    if(sz > n-1) sz--;
//    print();
    if(cnt == n) return mst;
    return -1;
}

int main() {
//    freopen("test.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &w);

        printf("Case %d:\n", t);
        sz = 0;

        for(int i=0; i<w; i++) {

            int u,v,c;
            scanf("%d %d %d", &u,&v,&c);
//            edge.pb(info(u,v,c));
            edge[sz++] = info(u,v,c);
//            cout << edge[sz-1].key << endl;
//            sz++;
//            sort(edge, edge+sz, cmp);

            printf("%d\n", mst(1));
        }
    }
    return 0;
}
