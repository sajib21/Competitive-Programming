#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k, ara[100005];
ll ans =0;

void bnsrch(ll nn, ll hi)
{

    ll lo=nn+2, mid =(lo+hi)/2, d= ara[mid]-ara[nn];

    if(lo>hi) return;

    ll ansIn = -1, din=0;

    while(lo <= hi) {

        mid = (lo+hi)/2;
        d = ara[mid] - ara[nn];

        if(d == k) {
            ansIn = mid;
            din = d;
            break;
        }
        if(d < k) {
            if(d > din) din = d, ansIn = mid;
            lo = mid+1;
        }
        else if(d > k) {
            hi = mid-1;
        }

        if(lo == mid) break;
    }

//    cout << nn << ' ' <<  ansIn << ' ' << din << endl;

    ansIn = ansIn - nn -1;
    if(din) ans += ansIn*(ansIn+1)/2;
    return;
}

int main()
{

    scanf("%I64d %I64d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%I64d", &ara[i]);

    for(ll i=0; i<n; i++)
    {
        bnsrch(i, n-1);
        //cout << ans << endl;
    }

    cout << ans << endl;

}
