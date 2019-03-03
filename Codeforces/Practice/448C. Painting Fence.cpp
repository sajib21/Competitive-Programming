#include<bits/stdc++.h>
#define LIM 5005
#define LOG 13
using namespace std;

int n, a[LIM], mini[LIM][15], mid[LIM][15], dp[LIM][LIM];

void gen() {
    memset(mini, 127, sizeof mini);
    for(int i=0; i<n; i++) mini[i][0] = a[i], mid[i][0] = i;
    int log = log2(n+100)+1;
    for(int j=1, sz=1; j<=log; j++, sz*=2) {
        for(int i=0; i<=n-sz; i++) {
            int ta = mini[i][j-1], tb = mini[i+sz][j-1];
            if(ta < tb) mid[i][j] = mid[i][j-1];
            else mid[i][j] = mid[i+sz][j-1];
            mini[i][j] = min(mini[i][j-1] , mini[i+sz][j-1]);
        }
    }
//    for(int j=0, sz=1; j<=log; j++, sz*=2) {
//        cout << j << " : ";
//        for(int i=0; i<=n-sz; i++) cout << mid[i][j] << ' ' ;
//        cout << endl;
//    }
}

int g(int i, int j) {
    j++;
    int log = log2(j-i+1) + 1;
    int ma = INT_MAX, mi = -1;
    while(log >= 0) {
        if((1 << log) +  i <= j) {
            if(mini[i][log] < ma) {
                ma = mini[i][log];
                mi = mid[i][log];
            }
            i += (1 << log);
        }
        log--;
    }
    return mi;
}

int f(int i, int j, int h) {

//    if(i == j) return 1;
    if(i > j) return 0;
    int md = g(i,j);
//    cout << i << ' ' << j << ' ' << h << ' ' << md << endl; getchar();
//    cout << a[md]-h)+f(i,md-1, a[md]) << ' ' << f(md+1,j, a[md]) << endl; getchar();
    return min((j-i+1), (a[md]-h)+f(i,md-1, a[md])+f(md+1,j, a[md]) );
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    gen();
    printf("%d\n", f(0, n-1, 0));

//    while(true) {
//        int u,v;
//        cin >> u >> v;
//        cout << g(u,v) << endl;
//        cout << f(u,v, min(u? a[u-1]:INT_MAX , a[v+1]) ) << endl;
//    }

}
