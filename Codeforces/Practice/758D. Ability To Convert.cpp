#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n, num;
string k;

ll val(int i, int j) {
    ll ans = 0;
    while(i <= j) {
        ans = ans * 10 + k[i]-'0';
        i++;
    }
    return ans;
}

int main() {
    cin >> n;
    cin >> k;

    string temp, sol;
    ll mul = 1;
    ll ans = 0;
    ll bas = 1;
    ll num = 0;

    for(int i=k.size()-1; i>=0; ) {
//        cout << "IN " << i << endl; getchar();
        for(int j=max(0, i-10); j<=i; j++) {
            ll v = val(j,i);
//            cout << "VITRE " << j << ' ' << v << endl; getchar();
            if( i == j || (k[j] != '0' && v < n) ) {
                ans += v*bas;
                bas *= n;
                i = j-1;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;

    for(int i=k.size()-1; i>=0; i--) {
        if(mul < n && (k[i]-'0')*mul + num < n) {
            num = num + (k[i]-'0')*mul;
            mul *= 10;
        }
        else {
            ans += num*bas;
            bas *= n;
            num = k[i]-'0';
            mul = 10;

        }
        cout << num << endl;
    }

    ans += num*bas;
    cout << ans << endl;
}
