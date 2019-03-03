#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll a,d,m, i = 1e7;
    scanf("%lld %lld", &a, &m);

    do {
        d = a%m;
        a += d;
//        cout << a << ' ' << d << endl; getchar();
    } while(d && i--);

    if(d) printf("No\n");
    else printf("Yes\n");
}
