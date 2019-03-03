#include<bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int main() {
//    freopen("1648i.txt", "r", stdin);
//    freopen("1648o.txt", "w", stdout);
    int n,m;
    while(scanf("%d %d", &n,&m) != EOF) {
        int ans = INT_MAX;
        for(int i=0; i<m; i++) {
            int u,d;
            scanf("%d %d", &u,&d); if(!u && !d) break;
            int x = (d*n+u+d)/(u+d);
            int y = u*x - (n-x)*d;
            if(y >= 0) ans = min(ans, y);
//            cout << y << endl;
        }
        printf("%d\n", ans);
    }
    return 0;
}
