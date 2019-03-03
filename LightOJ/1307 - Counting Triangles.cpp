#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n, ara[2020];
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &ara[i]);
        sort(ara, ara+n);

        ll cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int f = ara[i] + ara[j];
                int in = lower_bound(ara+j+1, ara+n, f) - ara;
//                cout << in << endl;
                cnt += in - j - 1;
            }
        }
        printf("Case %d: %lld\n", t, cnt);
    }
    return 0;
}
