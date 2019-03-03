
struct info{
    ll x,y;
    info() {}
    info(ll xx, ll yy) {
        x = xx; y = yy;
    }
};

int n;
info pnt[10005];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%lld %lld", &pnt[i].x, &pnt[i].y);
        pnt[n] = pnt[0];

        double area = 0;
        for(int i=0; i< n; i++) area += pnt[i].x*pnt[i+1].y;
        for(int i=1; i<=n; i++) area -= pnt[i].x*pnt[i-1].y;
        area = fabs(area);

        ll out = 0;
        for(int i=0; i<n; i++) out += __gcd( abs(pnt[i].x-pnt[i+1].x) , abs(pnt[i].y-pnt[i+1].y) );

        ll ans = (area - out)/2 + 1;

        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}

