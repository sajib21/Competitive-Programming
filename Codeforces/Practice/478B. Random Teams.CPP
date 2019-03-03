#include<bits/stdc++.h>

using namespace std;

int main() {

    long long int n,m;
    scanf("%I64d %I64d", &n, &m);

    long long int tm1 = n%m;
    long long int div = n/m;

    long long int minimum = (m-tm1) * div*(div-1)/2 + tm1 * div*(div+1)/2;
    long long int maximum = (n - m + 1)*(n-m)/2;

    printf("%I64d %I64d\n", minimum, maximum);

    return 0;
}
