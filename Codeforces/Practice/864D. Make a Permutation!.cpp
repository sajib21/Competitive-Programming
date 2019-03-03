#include<bits/stdc++.h>
#define LIM 200005

using namespace std;

int n, a[LIM], f[LIM], c[LIM], g[LIM];

int main() {
    int ans  = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if(c[ a[i] ]) ans++;
        c[ a[i] ]++;
        g[ a[i] ] = 1;

    }
//    for(int i=1; i<=n; i++) if(c[i] == 1) f[i] = 2;

    int cur = 1;
    int i=0;
//    int ans = 0;
    while(i < n) {
        if(c[ a[i] ] == 1 && !f[ a[i] ]) {
            f[ a[i] ] = 1;
//            i++;
        }
        else {
//            ans++;
            if(cur > a[i] && !f[ a[i] ]) {
                c[ a[i] ]--;
                f[ a[i] ] = 1;
                i++;
                continue;
            }
            while(cur < n) {
                if(f[cur]) cur++;
                else if(g[ cur ] == 1 && a[i] != cur) cur++;
                else break;
            }
            if(!f[ cur ]) {
                c[ a[i] ]--;
                a[i] = cur;
//                c[cur] = 1;
                f[cur] = 1;
                cur++;
            }
            else {

            }

        }
        i++;
    }

    cout << ans << endl;
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    cout << endl;
}
