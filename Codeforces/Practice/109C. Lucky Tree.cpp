#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define LIM 100005
#define ll long long int

using namespace std;

int n, link[LIM], sz[LIM];
vi root;

int findLink(int x) {
    while(x != link[x]) x = link[x];
    return x;
}
int isSameLink(int a, int b) {
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
bool isLucky(int x) {
    while(x) {
        int p = x%10;
        if(p != 4 && p != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) link[i] = i, sz[i] = 1;

    for(int i=1; i<n; i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);
        if(!isLucky(w)) {
            unite(u,v);
        }
    }
    for(int i=1; i<=n; i++) if(i == findLink(i)) root.pb(i);

    ll ans = 0;

    for(int i=0; i<root.size(); i++) {
        int u = root[i];
        ans += 1LL * sz[u] * (n - sz[u])*(n-sz[u]-1);
    }

    printf("%I64d\n", ans);
}
