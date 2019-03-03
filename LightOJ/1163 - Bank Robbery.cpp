#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ll dif;
        scanf("%lld", &dif);

        ll amid = dif/9 * 10;

        ll lo = max(0LL, amid - 50 ), hi = amid + 50;

        printf("Case %d:", t);
        while(lo <= hi) {

            if(lo - lo/10 == dif) printf(" %lld", lo);
            lo++;
        }
        printf("\n");
    }
    return 0;
}
