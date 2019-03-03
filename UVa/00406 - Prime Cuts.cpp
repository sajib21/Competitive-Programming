#include <bits/stdc++.h>

using namespace std;

bool isNotPrime[1111];

void sieve() {

    for(int i=4; i<1010; i+=2) {
        isPrime[i] = true;
    }

    for(int i=3; i<33; i++) {
        for(int j=i+i; j<1111; j+=i) {

        }
    }
}

int main() {

    int n,c;

    sieve();

    while(scanf("%d %d", &n,&c)) {


    }
}
