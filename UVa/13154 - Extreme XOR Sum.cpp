#include<bits/stdc++.h>
#define LIM 10000
#define LOG 512
using namespace std;

int n,q, a[LIM+100];
int sum[LOG+10][LIM+100];

int f(int x, int y, int po = 1073741824) {
    int m = y-x;
    while(po/2 >= m) po /= 2;
    int gap = po-m;
    int sz = (m-gap)/2;

    if(m <= LOG) return sum[m][x];

    return f(x, x+sz , po ) ^ f(y-sz, y, po);
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        for(int i=0; i<n; i++) sum[1][i] = a[i];

        for(int p=2; p<=min(n,LOG); p++) {
            for(int i=0; i<n-p+1; i++) sum[p][i] = sum[p-1][i] ^ sum[p-1][i+1];
        }

//        for(int p=1; p<=n; p++) {
//            printf("%3d: ", p);
//            for(int i=0; i<n; i++) printf("%3d ", sum[p][i]);
//            cout << endl;
//        }

        scanf("%d", &q);
        printf("Case %d:\n", t);

        while(q--) {
            int x,y;
            scanf("%d %d", &x,&y);
            printf("%d\n", f(x,y+1) );
        }
    }
}
