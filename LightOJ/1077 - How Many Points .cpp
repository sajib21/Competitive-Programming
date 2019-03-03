#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

//    cout << __gcd(0,0) << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll a,b,c,d;
        scanf("%lld %lld %lld %lld", &a,&b,&c,&d);
//        cout << abs(a-c)
        printf("Case %d: %lld\n", t, __gcd( abs(a-c) , abs(b-d) ) + 1 );
    }

    return 0;

}
