#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

int n,m,k;
int strict, left, taken[1010];

int combination(int indx) {

    int ans = 0;
    for(int i=1; i<=left; i++) {
        if(!taken[i]) {
            taken[i] = 1;
            ans += combination(indx+1);
            taken[i] = 0;
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d %d", &n,&m,&k);

        strict = m-k; left = n-k;
        memset(taken, 0, sizeof(taken));

        printf("%lld\n", combination(0));
    }
}
