#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n, s, x, a[200005];
int ans, mis;
vi pure;

int main() {

    set<int>ase;
    scanf("%d %d", &n, &s);

    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        if(i == s) {
            if(x) ans++;
        }
        else {
            if(x) pure.pb(x);
            else mis++;
        }
    }
    sort(pure.begin(), pure.end());
//    while(mis--) pure.pb(0);

//    for(auto it : pure) cout << it << ' '; cout  << endl;

    int i=0, j = pure.size()-1, last = 0;

    while(i <= j) {
        if(pure[i] == last) i++;
        else if(pure[i] == last+1) {
            last++;
            i++;
        }
        else {
            if(mis) {
                mis--;
                ans++;
                last++;
            }
            else {
                j--;
                ans++;
                last++;
            }
        }
    }

    cout << ans+mis << endl;

//    main();
}
