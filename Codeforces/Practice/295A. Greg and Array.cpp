#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int

using namespace std;

ll n,m,k, a[LIM], l[LIM], r[LIM], d[LIM], mul[LIM], add[LIM];


int main() {
    scanf("%lld %lld %lld", &n,&m,&k);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=m; i++) scanf("%lld %lld %lld", &l[i],&r[i],&d[i]);
    for(int i=1; i<=k; i++) {
        int x,y;
        scanf("%d %d", &x,&y);
        mul[x]++; mul[y+1]--;
    }
    for(int i=1; i<LIM; i++) mul[i] += mul[i-1];

    for(int i=1; i<=m; i++) {
        add[ l[i] ] += d[i]*mul[i];
        add[ r[i]+1 ] -= d[i]*mul[i];
    } //for(int i=0; i<5; i++) cout << "IN " << i << ' ' << add[i] << endl;
    for(int i=1; i<LIM; i++) add[i] += add[i-1];



    for(int i=1; i<=n; i++) {
        if(i > 1) printf(" ");
        printf("%I64d", a[i]+add[i]);
    }
    printf("\n");
}
