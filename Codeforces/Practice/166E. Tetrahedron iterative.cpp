#include<bits/stdc++.h>
#define MOD 1000000007
#define LIM 10000007
#define ll long long int

using namespace std;

int n;
ll temp, takeD, takeO;

int main() {

    scanf("%d", &n);

    takeD = 0;
    takeO = 1;

    for(int i=2; i<=n; i++) {
        temp = takeD;
        takeD = 3*takeO;
        takeO = 2*takeO + temp;


        while(takeD >= MOD) takeD -= MOD;
        while(takeO >= MOD) takeO -= MOD;
    }

    printf("%lld\n", takeD);

    return 0;

}
