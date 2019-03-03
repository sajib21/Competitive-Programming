#include<bits/stdc++.h>

using namespace std;

int n, ara[1000006];

int main() {

    int T;
    bool des;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        des = true;
        memset(ara, 0, sizeof(ara));
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            ara[x]++;
        }
        for(int i=0; i<n; i++) {
            if( ara[i] ) ara[i]--;
            else if( ara[n-i-1] ) ara[n-i-1]--;
            else {
                des = false;
                break;
            }
        }
        if(des == false) printf("Case %d: no\n", t);
        else printf("Case %d: yes\n", t);

    }

    return 0;

}
