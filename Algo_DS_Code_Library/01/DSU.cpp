#include<bits/stdc++.h>
#define LIM 100005

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
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) sz[i] = 1, link[i] = i;

    while(m--) {
        int a,b,c;
        scanf("%d", &a);
        ///findLink
        if(a == 1) {
            scanf("%d", &b);
            cout << findLink(b) << endl;
        }
        ///check if same Link
        else if(a == 2) {
            scanf("%d %d", &b,&c);
            cout << isSameLink(b,c) << endl;
        }
        ///unite
        else {
            scanf("%d %d", &b,&c);
            unite(b,c);
        }
    }
}
