#include<bits/stdc++.h>
#define LIM 1000000
#define ll long long

using namespace std;

ll n,q,k;
ll ara[LIM+10];

bool cmp(ll a, ll b)
{
    return a > b;
}

int main()
{

    scanf("%I64d", &n);
    for(ll i=0; i<n; i++) scanf("%I64d", &ara[i]);
    sort(ara, ara+n, cmp);
    ara[0] = 0;
    ll xtra = 0;
    for(ll i=1; i<n; i++) {
        xtra += ara[i]*i;
        ara[i] += ara[i-1];

    }
//    for(ll i=1; i<n; i++) cout << ara[i] << ' '; cout << endl;
//    initTree(1, 1, n-1);
    scanf("%I64d", &q);
    while(q--)
    {
        scanf("%I64d", &k);

        if(k==1) {
            if(q) printf("%I64d ", xtra);
            else printf("%I64d\n", xtra);
            continue;
        }

        k = min(n-1, k);
        ll lft = 0 , rgt = min(k, n-1), mul = 1;
        ll dif = k;
        ll ans = 0;
        while(lft < n-1)
        {
//            cout << rgt << ' ' << ara[rgt] << ' ' << lft << ' ' << ara[lft] << endl;
            ans += (ara[rgt] - ara[lft])*mul;
            mul++;
            lft = rgt;
            dif *= k;
            rgt += dif;
            rgt = min(rgt, n-1);
//            cout << ans << endl;
        }
        if(q) printf("%I64d ", ans);
        else printf("%I64d\n", ans);
    }

    return 0;
}
