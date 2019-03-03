#include<bits/stdc++.h>
#define LIM 200005

using namespace std;

int n,m, a,b, sz[LIM], link[LIM];

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
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++) sz[i] = 1, link[i] = i, sz2[i] = 0;
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);

    while(m--) {
        int u,v;
        scanf("%d %d", &u, &v);
        if()
    }
}

