#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int n, x;
ll dp[25][160];

ll power(ll n, int pow) {

    ll a = 1;
    while(pow--) {
        a *= n;
    }
    return a;
}

ll getPro(int indx, ll cur) {


    if(cur == x-1) {
        if(indx >= n) return 1;
        else return 0;
    }
    if(indx >= n) return 1;

    if(dp[indx][cur] != -1) return dp[indx][cur];

    ll temp = cur+1, ans = 0;
    for(int i=0; i<6 && temp < x; i++, temp++) {
//        cout << t << '\t' << temp << endl;
        ans += getPro(indx+1, temp);
//        cout << t << " ans " << ans << endl;
    }
    return dp[indx][cur] = ans;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d %d", &n, &x);
        ll q = power(6, n); //cout << q << endl;
        ll p = q - getPro(0, 0); //cout << p << endl;
        ll g = __gcd(p,q); //cout << g << endl;
        if(g == q) //cout << "Case " << t << ": " << p/g << endl;
            printf("Case %d: %lld\n",t, p/g);
        else //cout << "Case " << t << ": " << p/g << '/' << q/g << endl;
            printf("Case %d: %lld/%lld\n",t, p/g, q/g);
    }

    return 0;
}
