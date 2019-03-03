#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define LIM 110

using namespace std;

int n, xi[LIM], yi[LIM], zi[LIM], xs[LIM], ys[LIM], zs[LIM], x[LIM], y[LIM], z[LIM];
vii X,Y,Z;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d %d %d %d %d", &xi[i], &yi[i], &zi[i], &xs[i], &ys[i], &zs[i]);
        for(int i=0; i<n; i++) {
            x[2*i] = xi[i]; x[2*i+1] = xi[i] + xs[i];
            y[2*i] = yi[i]; y[2*i+1] = yi[i] + ys[i];
            z[2*i] = zi[i]; z[2*i+1] = zi[i] + zs[i];
        }
        sort(x, x+2*n); sort(y, y+2*n); sort(z, z+2*n);
        X.pb(x[0]); Y.pb(y[0]); Z.pb(z[0]);
        for(int i=1; i<2*n; i++) if(x[i] != x[i-1]) X.pb(x[i]);
        for(int i=1; i<2*n; i++) if(y[i] != y[i-1]) Y.pb(y[i]);
        for(int i=1; i<2*n; i++) if(z[i] != z[i-1]) Z.pbzy[i]);

    }
}
