#include<bits/stdc++.h>
#define ll long long int

using namespace std;


int main() {

    ll n,m, x, xorSum = 0;
    while(scanf("%lld %lld", &n, &m)) {
        xorSum = 0;
        if(!n && !m) return 0;
        if(m > n) swap(n,m);

        while(1) {
            x = n/m;
            if(n%m==0) {
//                xorSum ^= 1;
                break;
            }
            xorSum ^= x;
            x = m;
            m = n%m;
            n = x;
        }
        if(xorSum) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}




