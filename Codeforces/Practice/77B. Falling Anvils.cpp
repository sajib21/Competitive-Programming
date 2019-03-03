#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll a,b;
        scanf("%lld %lld", &a,&b);
        if(!b) printf("1\n");
        else if(!a) printf("0.5\n");
        else if(1.0*a/4 <= b) printf("%.8f\n", 1.0*(a+8*b)/(16*b));
        else printf("%.8f\n", 1.0*(a-b)/a);
    }
}
