#include<bits/stdc++.h>
#define LIM 200005
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,m, u[LIM], v[LIM];
vi g[LIM];
int in[LIM], koyta;

bool f(int x) {
    memset(in, 0, sizeof in);
    memset(g, NULL, sizeof g);
    koyta = 0;
    for(int i=0; i<x; i++) {
        g[ u[i] ].pb( v[i] );
        in[ v[i] ]++;
    }

    queue<int>q;
    for(int u=1; u<=n; u++) if(!in[u]) {
        q.push(u);
        koyta++;
    }

    while(koyta < 2 && !q.empty()) {
        int u = q.front();
        q.pop();
        koyta--;

        for(auto v : g[u]) {
            in[v]--;
            if(!in[v]) {
                q.push(v);
                koyta++;
            }
        }

    }

    return koyta < 2;

}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    int lo=0, hi=m+1, md;

//    cout << f(m) << endl;

    while(lo < hi) {
        md = (lo+hi)/2;
//        cout << md << ' ' << f(md) << endl;
        if(f(md)) hi = md;
        else lo = md+1;
    }

    if(hi == m+1) printf("-1\n");
    else printf("%d\n", hi);

}
/*
5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

5 10
2 1
1 4
2 5
2 3
5 4
3 4
3 1
3 5
2 4
1 5
*/
