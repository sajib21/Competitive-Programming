#include<bits/stdc++.h>
#define ll long long int
#define MX 1000000
using namespace std;

int n;
ll num, t;

bool notPrime[1000006];

void sv() {

    notPrime[1] = true;
    for(int i=4; i<=MX; i+=2) notPrime[i] = true;
    for(int i=3; i<=1003; i+=2) {
        for(int j=i+i; j<=MX; j+=i) {
            notPrime[j] = true;
        }
    }
}

int main() {

    sv();

    scanf("%d", &n);
    while(n--) {

        scanf("%lld", &num);
        t = sqrt(num);
        if(!notPrime[t] && t*t==num) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
