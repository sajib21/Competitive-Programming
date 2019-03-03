#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define LIM 1000000
#define pb push_back

 //Compiler version g++ 4.9

bool prime[LIM+100];
vector<int>prm;

void sv() {
    prm.pb(2);
    for(int i=4; i<=LIM; i+=2) prime[i] = true;
    for(int i=3; i<=LIM; i+=2) {
        if(!prime[i]){
            prm.pb(i);
            for(ll j=1ll*i*i; j<=LIM; j+=i) {
                prime[j] = true;
            }
        }
    }
}


 int main()
 {
    sv();
    cout << prm.size() << endl;
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        ll n;
        scanf("%lld", &n);
        if(n==1) {
            printf("Case %d: 0\n", t);
            continue;
        }
        int i =0;
        ll ans =1;
        ll st= sqrt(n);
        while(n > 1 && prm[i]<=st) {
            ll cnt = 0;
            while(n % prm[i] == 0) {
                cnt++;
                n /= prm[i];
            }
            i++;
            ans *= cnt+1;
        }
        if(n > 1) ans *=2;
        printf("Case %d: %lld\n", t, ans-1);

    }

    return 0;
 }
