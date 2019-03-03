#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

int main() {

    int n,m;
    scanf("%d %d", &n,&m);

    string names[102];
    for(int i=0; i<n; i++) cin >> names[i];

    int alpha[100];

    ll ans = 1;
    for(int i=0; i<m; i++) {
        memset(alpha, 0, sizeof(alpha));
        ll tmp = 0;
        for(int j=0; j<n; j++) {
            if(!alpha[ names[j][i] ]) {
                tmp++;
                alpha[names[j][i]] = 1;
            }
        }
        ans = (ans * tmp%MOD) % MOD;
    }

    printf("%I64d\n", ans);

    return 0;
}
