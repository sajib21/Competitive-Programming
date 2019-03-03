#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        string a;
        ll b, sz;
        ll c = 0;

        cin >> a; sz = a.size();
        scanf("%lld", &b);

        b = abs(b);
        int i = 0; if(a[i] == '-') i++;

        for(; i<sz; i++) {
            c = (10*c + a[i]-'0') % b;
        }

        if(!c) printf("Case %d: divisible\n", t);
        else printf("Case %d: not divisible\n", t);
    }

    return 0;
}
