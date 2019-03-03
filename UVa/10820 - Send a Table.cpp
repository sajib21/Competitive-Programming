#include<bits/stdc++.h>
#define LIM 50000
#define ll long long int

using namespace std;

ll phi[LIM+100];
ll cum[LIM+100];

void phiSieve() {
    phi[1]= 0;
//    phi[2] = 1;
    for(int i=2; i<=LIM; i++) {
        if(phi[i] == 0) {
            phi[i] = i-1;
            for(int j=i*2; j<=LIM; j+=i) {
                if(phi[j] == 0) phi[j] = j;
                phi[j] /= i ;
                phi[j] *= (i-1) ;
            }
        }
    }
}

int n;

int main() {
//    freopen("10820i.txt", "r", stdin);
//    freopen("10820o.txt", "w", stdout);
    phiSieve();
//    for(int i=1; i<=20; i++) cout << i << ' ' << phi[i] << endl;

    for(int i=2; i<=LIM; i++) cum[i] = cum[i-1] + phi[i];
    while(scanf("%d", &n) && n) {
        printf("%lld\n", cum[n]*2 + 1);
    }
    return 0;
}
