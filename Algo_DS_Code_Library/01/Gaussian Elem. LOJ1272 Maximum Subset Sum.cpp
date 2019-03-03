int n;
ll ara[110];
vector< vii > co;

ll gauss() {
    int row = co.size(), col = co[0].size();
    for(int r=0, c=0; c<col-1 && r<row; c++) {
        int cur = r;
        for(int i=r; i<row; i++) if(co[i][c] > co[cur][c]) {
            cur = i;
        }
        if(!co[cur][c]) continue;
        if(cur != r) swap(co[cur], co[r]);

        for(int i=0; i<row; i++) if(i != r && co[i][c]) {
            for(int j=c; j<col-1; j++) co[i][j] ^= co[r][j];
        }
        r++;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        co.clear();
        for(int i=0; i<n; i++) scanf("%lld", &ara[i]);

        for(int i=0; i<n; i++) {
            vii temp(64);
            for(int j=0; j<63; j++) {
                temp[63-j-1] = ara[i] & 1;
                ara[i] >>= 1;
            }
            co.pb(temp);
        }
        printf("Case %d: %lld\n", t, gauss());
    }

    return 0;
}
