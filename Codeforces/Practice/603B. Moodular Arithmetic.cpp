#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define LIM 1000006

using namespace std;

int p,k, a[LIM], sz[LIM], link[LIM], ok[LIM];

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
//    scanf("%d %d", &p, &k);
    cin >> p >> k;
    for(int i=0; i<p; i++) sz[i] = 1, link[i] = i;

    if(k < 2) { ///do something
        ll ans = 1;
        for(int i=0; i<p-1; i++) {
            ans *= p;
            ans %= MOD;
        }
        if(k == 1) {
            ans *= p;
            ans %= MOD;
        }
        cout << ans << endl;
        return 0;
    }

    for(int i=0; i<p; i++) {
        int j = (1LL* k*i)%p;
        unite(i,j);
//        cout << "UNITE " << i << ' ' << j << endl;
    }

    ll ans = 1;

    for(int i=0; i<p; i++) {
        int u = findLink(i);
//        cout << i << ' ' << u << ' ' << sz[u] << endl;
        if(sz[u] == 1 || ok[u]) continue;
        ok[u] = 1;
        ans *= p;
        ans %= MOD;
    }
    cout << ans << endl;
}
