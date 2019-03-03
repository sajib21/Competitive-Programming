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

int n,g;
ll a[LIM], S[LIM], dp[808][LIM], P[808][LIM];
/// dp[g][i] mane g ta group diya i er ag porjonto

ll cost(int i, int j) {
    return i>j? 0 : (S[j]-S[i-1])*(j-i+1);
}

void f(int g, int st, int ed, int l, int r) {
    if(st >= ed) return;

    int md = (st+ed)/2;
    dp[g][md] = MAX;
    P[g][md]  = -1;

    for(int i=l; i<=min(md,r); i++) {
        ll temp = cost(i,md) + dp[g-1][i-1];
        if(temp < dp[g][md]) {
            dp[g][md] = temp;
            P[g][md] = i;
        }
    }

    f(g, st,md,   l, P[g][md]);
    f(g, md+1,ed, P[g][md], r);
}

int main() {
    scanf("%d %d", &n,&g);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=n; i++) S[i] = S[i-1] + a[i];
//    memset(dp, -1, sizeof dp);

    for(int i=1; i<=n; i++) dp[1][i] = cost(1, i);

    for(int k=2; k<=g; k++) f(k, 1,n+1, 1,n);

    printf("%lld\n", dp[g][n] );
}
