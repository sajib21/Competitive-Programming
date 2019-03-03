#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int n, x, ara[100005], a, maxx = 0;
    vector<int>num;
    memset(ara, 0, sizeof(ara));

    scanf("%d %d", &n,&x);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        if(!ara[a]) num.push_back(a);
        ara[a]++;
        maxx = max(maxx, a);
    }

    ll ans = 0;

    int sz = num.size();
    for(int i=0; i<sz; i++) {
        int chk1 = num[i];
        int chk2 = x ^ chk1;
        if(chk2 <= maxx && ara[chk1] && ara[chk2]) {
            if(chk1 == chk2) ans = ans + 1ll * ( 1ll * ara[chk1] * (ara[chk1]-1) / 2);
            else ans = ans + 1ll * ara[chk1] * ara[chk2];
            ara[chk1] = ara[chk2] = 0;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
