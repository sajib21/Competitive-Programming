#include<bits/stdc++.h>
#define LIM 100005
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int n, a[LIM];
set<pii>ase, seg;
int sz[LIM], link[LIM], ok[LIM];

int findLink(int x) {
    while(x != link[x]) x = link[x];
    return x;
}
bool isSameLink(int a, int b) {
    return findLink(a) == findLink(b);
}
void unite(int a, int b) {
    a = findLink(a);
    b = findLink(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        ase.insert(pii(a[i], i));
    }

    while(!ase.empty()) {
        pii cur = *ase.begin();
        int v = cur.ff, in = cur.ss;
        set<pii>::iterator it = seg.find();
    }

}
