#include<bits/stdc++.h>
#define LIM 1000000
#define ll long long int
using namespace std;

double harm[LIM+10];
double gama = 0.5772156649;

int main() {

    harm[1] = 1;
    for(ll i=2; i<=LIM; i++) harm[i] = harm[i-1] + 1.0 / i ;

//    for(int i=1; i<=20; i++) cout << harm[i] << " : " << log(i) + gama << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll n;
        scanf("%lld", &n);
        if(n <= LIM) printf("Case %d: %.10lf\n", t, harm[n]);
        else printf("Case %d: %.10lf\n", t, log(n) + gama + 1.0/(2*n) - 1.0/(12*n*n) );
    }

    return 0;

}
