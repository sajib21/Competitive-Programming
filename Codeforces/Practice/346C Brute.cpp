#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

int n, x[LIM], a,b;
map<int,int>vis, par;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> x[i];
    cin >> a >> b;

    queue<int>q;
    q.push(a);
//    vis[a] = tr;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << "POP: " << u << ' ' << vis[u] << endl; getchar();

        if(u == b) break;

        if(!vis[u-1]) {
            vis[u-1] = vis[u]+1;
            q.push(u-1);
            par[u-1] = u;
            cout << "PUSH: " << u-1 << ' ' << vis[u-1] << endl; getchar();
        }

        for(int i=0; i<n; i++) {
            int v = u - u%x[i];
            if(v == u || v < b || vis[v]) continue;

            vis[v] = vis[u]+1;
            par[v] = u;
            q.push(v);
            cout << "PUSH: " << v << ' ' << vis[v] << endl; getchar();
        }
    }

    cout << "Path: " << endl;
    while(b != a) {
        cout << b << " ";
        b = par[b];
    }
    cout << b << endl;
}
