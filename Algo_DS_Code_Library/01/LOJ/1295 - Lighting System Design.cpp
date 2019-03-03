int n;
info sob[LIM+10];
int cum[LIM+10], dp[1003][1003];

int getMin(int in, int pre) {
    if(pre == n) return 0;
    if(in  > n) return MAX;
    if(dp[in][pre] != -1) return dp[in][pre];
    return dp[in][pre] = min( (cum[in]-cum[pre])*sob[in].c + sob[in].k + getMin(in+1, in) , getMin(in+1, pre) );
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d %d %d %d", &sob[i].v, &sob[i].k, &sob[i].c, &sob[i].l );
        sort(sob+1, sob+n+1, cmp);
        for(int i=1; i<=n; i++) cum[i] = cum[i-1] + sob[i].l;
//        for(int i=1; i<=n; i++) cout << cum[i] << ' ' ; cout << endl;
        printf("Case %d: %d\n", t, getMin(1, 0));
    }

    return 0;
}

