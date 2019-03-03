#include<bits/stdc++.h>
#define ll unsigned long long int
#define MOD 1000000007
#define MX 1000006

using namespace std;

ll a,b, n;
ll low, high;

ll nCr[MX];

ll po(ll a,ll b)
{
    if(b==0) return 1LL;
    if(b%2)
    {
        return (a%MOD * po(a,b-1)%MOD)%MOD;
    }
    ll temp=po(a,b/2)%MOD;
    return (temp%MOD*temp%MOD)%MOD;

}

int comb()
{

    nCr[n] = nCr[0] = 1;
    for(ll i=1, j=n; i <= n/2 && j >= n/2; i++, j--)
    {
        nCr[n-i] = nCr[i] = (nCr[i-1]%MOD*j%MOD*po(i,MOD-2)%MOD) % MOD;
//        cout << i << ' ' << nCr[i] << endl;
    }

}

int main()
{

    scanf("%llu %llu %llu", &a,&b,&n);
    if(b>a) swap(a,b);
    low = b*n;
    high = a*n;
    comb();

//    cout << "done" << endl;

    ll div = a-b;
    ll ans = 0;

    queue<ll>q;
    q.push(b);
    q.push(a);


    while(!q.empty())
    {

        ll cur = q.front();
        q.pop();


        if(cur > high) break;
        if(cur >= low)
        {
            if( (cur-low) % div == 0 )
            {
                ll x = (cur-low)/div;
                ans = (ans + nCr[x]) % MOD ;
            }
        }
        q.push(cur*10 + b);
        q.push(cur*10 + a);
    }
    printf("%llu\n", ans);

    return 0;

}
