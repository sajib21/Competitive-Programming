#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int n,x,ans=0, flag[1000006] = {0};
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &x); x++;
//            if(!x) ans++;
            if(!flag[x]) ans += x;
            flag[x]++;
            if(flag[x] == x) flag[x] = 0;
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;

}
