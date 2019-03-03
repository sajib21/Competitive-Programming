#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll n, n1, n2, ara[100005];
    cin >> n >> n1 >> n2;
    for(int i=0; i<n; i++) scanf("%lld", &ara[i]);
    sort(ara, ara+n);

    if(n1 > n2) swap(n1, n2);

    ll a=ara[n-1],b=ara[n-2];

    ll sa=1, sb=1;

    for(int i=n-3; i>=0; i--) {
        double t1 = abs( 1.0*(a+ara[i])/(sa+1) - 1.0*a/sa  ), t2 = abs( 1.0*(b+ara[i])/(sb+1) - 1.0*b/sb );
//        if(sa) t1 = 1.0*a/sa;
//        if(sb) t2 = 1.0*b/sb;
        if((t1 <= t2 || sb >= n2) && sa < n1) {
            a += ara[i];
            sa++;
        }
        else if(sb < n2){
            b += ara[i];
            sb++;
        }
    }

    printf("%.10lf\n", (1.0*a/sa) + (1.0*b/sb) );

    return 0;
}
