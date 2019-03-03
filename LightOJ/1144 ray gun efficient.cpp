#include <stdio.h>

#define MAX 2000100

#define ll long long

ll po(ll a,ll b)
{
    ll ans=1;
    while(b--) ans*=a;
    return ans;
}
ll prime(ll a)
{
    for(int i=1; i*i<=a; i++)
    {
        if(a%i==0) return 1;
    }
    return 0;
}

ll phi(long long int n)
{
    ll i,mul=1,holder,fre=0;
    if(prime(n)==0) mul=n-1;
    else
    {
        for(i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                    holder=i;
                    fre++;

                }
                mul*=(po(holder,fre-1)*(holder-1));
                fre=0;
            }
        }
        if(n!=1) mul*=(n-1);
    }
    //cout << mul << endl;
    return mul;
}

int phiv[MAX] ;
void sievePHI(){
    long long int i,j;
    for( i=2;i<=MAX;i++){
        if( phiv[i]==0){
            phiv[i] = i-1;
            for( j = i*2; j<MAX; j+=i){
                if( phiv[j] == 0 )phiv[j] = j;
                phiv[j] /= i ;
                phiv[j] *= (i-1) ;
            }
        }
    }
}

int totient (int i) {
    int ans; /* Result */
    int j;

    if (i==1) return 1;
        ans=i;
        if (i%2==0) {
        ans -= ans/2;
        while (i%2==0) {
            i/=2;
        }
    }
    for (j=3; j*j<=i; j+=2) {
        if (i%j==0) {
            ans-=ans/j;
            while (i%j==0) {
                i/=j;
            }
        }
    }
    if (i>1) ans -= ans/i;
    return ans;
}

long long int shot(long long int n, long long int m)
{
    long long int sum=0, i;
    if(m==1 && n==1) return 3;
    if(n>m)
    {
        if(n>MAX)
        {
            for(i=n; i>MAX; i--) sum+=phi(i);
            for(i=MAX; i>m; i--) sum+=phiv[i];
        }
        else for(i=n; i>m; i--) sum+=phiv[i];
        return shot(m, m) + sum;
    }

    else
    {
        if(n>MAX)
        {
            for(i=n; i>MAX; i--) sum+=phi(i);
            for(i=MAX; i>=3; i--) sum+=phiv[i];
        }
        else for(i=n; i>=3; i--) sum+=phiv[i];
        return 5 + 2*(sum);
    }
}

int main()
{
    long long int t, i, m,n;
    sievePHI();
    scanf("%lld", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld", &m, &n);
        if(n>m) printf("Case :%lld %lld\n", i, shot(n,m));
        else printf("Case :%lld %lld\n", i, shot(m,n));
    }
    return 0;
}
