/*
problem: Optimize the innermost loop
for(k=1; k<=g; k++) {
    for(i=k; i<=n; i++) {
        for(j=k; j<=i; j++) {
            dp[k][i] = min(dp[k][i], cost(j,i)+dp[k-1][j-1]);
        }
    }
}

say, P[k][i] is the first j value for which,
dp[k][i] = cost(j,i)+dp[k-1][j-1]
if for fixed k, P[k][0] <= P[k][1] <= P[k][2] .... (monotone)
then

*/

#include<bits/stdc++.h>
#define LIM 4004
#define MAX 1000000000
#define ll long long int

using namespace std;

int n,g;
int x[LIM];
ll f[LIM][LIM], b[LIM][LIM], S[LIM][LIM];
ll dp[808][LIM], P[808][LIM];
/// dp[g][i] mane g ta group diya i er ag porjonto

void makeSparse() {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            b[i][j] = b[i][j-1] + (x[j] == 1);
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            S[i][j] = b[i][j]*(j-i+1-b[i][j]);
        }
    }
//    cout << "COST " << endl;
//    for(int i=1; i<=n; i++) {
//        for(int j=i; j<=n; j++) cout << S[i][j] << ' ';
//        cout << endl;
//    }
}

ll cost(int i, int j) {
    return S[i][j] ;
}

void fn(int g, int st, int ed, int l, int r) {
//    cout << "IN: " << g << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << endl;
//    getchar();
    if(st > ed) return;
    int md = (st+ed)/2;
    dp[g][md] = MAX;

//    cout << "CALC " << g << ' ' << md << endl; getchar();
    for(int i=l; i<=min(md-1,r); i++) {
//        cout << "TEST: " << i << ' ' << cost(i+1,md) << ' ' << dp[g-1][i] << endl; getchar();
        ll temp = cost(i+1,md) + dp[g-1][i];
        if(i==l || temp < dp[g][md]) {
            dp[g][md] = temp;
            P[g][md] = i;
        }
    }

//    cout << "GOT: " << g << ' ' << md << ' ' << dp[g][md] << endl; getchar();

    fn(g, st,md-1,   l, P[g][md]);
    fn(g, md+1,ed, P[g][md], r);
}

int main() {
    scanf("%d %d", &n,&g);
    for(int i=1; i<=n; i++) scanf("%lld", &x[i]);
    makeSparse();

    for(int i=1; i<=n; i++) dp[1][i] = cost(1,i);

    for(int k=2; k<=g; k++) fn(k, 1,n+1, 1,n);

    printf("%d\n", dp[g][n] );

//    main();

}

