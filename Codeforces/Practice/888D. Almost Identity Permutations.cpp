#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k;

int main() {
    scanf("%lld %lld", &n,&k);

    ll ans = 1;
    if(k >= 2) ans += n*(n-1)/2;
    if(k >= 3) ans += n*(n-1)*(n-2)/6 * 2;
    if(k >= 4) ans += n*(n-1)*(n-2)*(n-3)/24  * 9;

//    memset(dp, -1, sizeof dp);
    cout << ans << endl;

//    main();

}

/*
4 1
1

4 2
7

5 3
31

5 4
76
*/
