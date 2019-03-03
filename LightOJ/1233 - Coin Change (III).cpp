#include<bits/stdc++.h>
#define MX 10000000
using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int n,m, coins[110], units[110], used[100005];
        bool DPMade[100005];
        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) scanf("%d", &coins[i]);
        for(int i=0; i<n; i++) scanf("%d", &units[i]);


        for(int i=0; i<=m; i++) used[i] = 0, DPMade[i] = false;
        DPMade[0] = true;

        int ans = 0;

        for(int i=0; i<n; i++) {
            int val = coins[i], num = units[i];
            for(int make=val; make <=m; make++) {
                if(!DPMade[make] && DPMade[make-val]) {
                    //cout << "1st if " << val << ' ' << make << endl;
                    if(used[make-val] + 1 <= num) {
                        //cout << "2nd if " << val << ' ' << make << endl;
                        DPMade[make] = true;
                        ans++;
                        used[make] = used[make-val] + 1;
                    }
                }
            }
            for(int j=0; j<=m; j++) used[j] = 0;
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
