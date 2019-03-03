#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000009

using namespace std;

ll power(ll a, ll b) {

    if(b==1) return a;

    if(b%2==0) {
        ll temp = power(a, b/2);
        return (temp * temp) % MOD;
    }
    else return (a * power(a, b-1) ) % MOD;
}

int main() {

    ll n,m,k;
    scanf("%lld %lld %lld", &n,&m,&k);

    ll g = (n+k-1)/k, com = n/k, ex = n%k;
    ll lim = com * (k-1) + ex;

    if(m <= lim) printf("%lld\n", m);
    else {
        ll var = m - lim;
        ll res = ( (2*k * (power(2, var) - 1)) % MOD + ((k-1) * (com-var)) % MOD + ex ) % MOD;
        printf("%lld\n", (res+MOD)%MOD );
    }

    return 0;
}
