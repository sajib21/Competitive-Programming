#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll ar,ac, br,bc;
    while(scanf("%lld %lld %lld %lld", &ar,&ac,&br,&bc)) {
        if(!ar) return 0;

        ll dr,dc, ans = 0;
        dr = br - ar;
        dc = bc - ac;

        if(abs(dr) <= abs(dc)) ans = abs(dr) + abs(dc);
        else {
            ans = 2*abs(dc);
            if(dr > 0) ar = ar + abs(dc);
            else       ar = ar - abs(dc);
            ac = bc;
            dr = br - ar;

//            cout << ar << ' ' << ac << ' ' << br << ' ' << bc << ' ' << ans << endl;

            if(ar > br) swap(ar,br);

            if(ac&1 && ar&1) {
                if(abs(dr)&1) ans += 2*abs(dr) - 1;
                else          ans += 2*abs(dr);
            }
            else if(ac&1 && (ar&1)==0) {
                if(abs(dr)&1) ans += 2*abs(dr) + 1;
                else          ans += 2*abs(dr);
            }
            else if(!(ac&1) && ar&1) {
                if(abs(dr)&1) ans += 2*abs(dr) + 1;
                else          ans += 2*abs(dr);
            }
            else {
                if(abs(dr)&1) ans += 2*abs(dr) - 1;
                else          ans += 2*abs(dr);
            }
        }
        printf("%lld\n", ans);
    }
}
