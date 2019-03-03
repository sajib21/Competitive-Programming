int n, w[105], all, lim;
ll dp[MAX/2 + 10];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        all = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &w[i]);
            all += w[i];
        }
        lim = (all+1) / 2;
        ll c1 = (n+1) / 2;
        ll c2 = (n) / 2;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1LL;
        for(int in=1; in<=n; in++) {
            for(int make=lim; make>=w[in]; make--) {
                dp[make] |= (dp[ make - w[in] ] << 1LL);
            }
        }
        for(int make=lim; make>=0; make--) {
            if( (dp[make] & (1LL << c1)) ) {
                printf("Case %d: %d %d\n", t, min(make, all-make), max(make, all-make));
                break;
            }
        }
    }
    return 0;
}

