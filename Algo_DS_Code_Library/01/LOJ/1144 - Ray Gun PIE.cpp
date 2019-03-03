int primeDivCnt[LIM+10];
bool ignore[LIM+10];
ll a,b;

ll f(int x) {
    if(primeDivCnt[x] & 1) return - (a/x) * (b/x);
    else return (a/x) * (b/x);
}

int main() {

    for(int i=2; i<=LIM; i++) if(!primeDivCnt[i]) for(int j=i; j<=LIM; j+=i) primeDivCnt[j]++;
    for(int i=2; i<=1000; i++) for(int j=i*i; j<=LIM; j += i*i) ignore[j] = true;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld %lld", &a,&b);
        if(b < a) swap(a,b);

        if(a == 0) {
            if(b == 0) printf("Case %d: 0\n", t);
            else printf("Case %d: 1\n", t);
            continue;
        }

        ll ans = 0;
        for(int i=1; i<=a; i++) if(!ignore[i]) ans += f(i);
        printf("Case %d: %lld\n", t, ans+2);
    }
    return 0;
}
