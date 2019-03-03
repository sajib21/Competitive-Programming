#include<bits/stdc++.h>
#define LIM 3030
#define vi vector<int>
#define pb(x) push_back(x)
#define sqr(x) ( (x) * (x) )

using namespace std;

int n,q, x[LIM], y[LIM], r;
vi dis;

int dist(int i, int j) {
    return sqr(x[i]-x[j]) + sqr(y[i]-y[j]);
}

int main() {
    while(true) {
        scanf("%d %d", &n,&q);
        if(!n && !q) return 0;

        dis.clear();

        for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) dis.pb( dist(i,j) );
        }
        sort(dis.begin(), dis.end());

//        for(int i=0; i<dis.size(); i++) cout << dis[i] << ' '; cout << endl;

        int ans = 0;

        while(q--) {
            scanf("%d", &r);
            int x = upper_bound(dis.begin(), dis.end(), r*r) - dis.begin();
            printf("%.2f\n", 1.0*x/n );
        }
        printf("\n");
    }
}
