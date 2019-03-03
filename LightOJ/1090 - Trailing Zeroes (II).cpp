#include<bits/stdc++.h>
#define LIM 1000000
#define ll long long int

using namespace std;

struct info {

    int two,five;
    info() {}
    info(int tt, int ff) {
        two = tt; five = ff;
    }
};

info pr[LIM+100];
info fact[LIM+100];

int main() {

    memset(pr, 0, sizeof(pr));
    memset(fact, 0, sizeof(fact));

    fact[0] = info(0,0);
    for(int i=1; i<=LIM; i++) {
        int a=0, b=0;
        int x = i;
        while(x%2==0) {
            a++;
            x /= 2;
        }
        while(x%5==0) {
            b++;
            x /= 5;
        }
        fact[i] = info( fact[i-1].two + a , fact[i-1].five + b );
        pr[i] = info(a,b);
    }


    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll n,r,p,q;
        scanf("%lld %lld %lld %lld", &n,&r,&p,&q);

        ll w,x,y,z;
        w = fact[n].five - fact[n-r].five - fact[r].five;
        x = fact[n].two - fact[n-r].two - fact[r].two;
        y = pr[p].five*q;
        z = pr[p].two*q;

//        cout << w << ' ' << x << ' ' << y << ' ' << z << endl;

        ll ans =  min( w + y , x + z ) ;
        printf("Case %d: %lld\n",t, ans);
    }
    return 0;
}
