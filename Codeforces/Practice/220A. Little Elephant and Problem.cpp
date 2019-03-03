#include<bits/stdc++.h>

using namespace std;

int n;
int ara[100005];

int main() {

    int t, keep, keep2;
    bool flag1 = false; // flag2 = false;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);

    for(int i=1; i<=n; i++) {
        //scanf("%d", &t);
        //ara[i] = t;
        if(ara[i] >= ara[i-1]) {
            //ara[i] = t;
        }
        else {
            if(flag1 == false) {
//                if(i<=n) {
//                    //scanf("%d", &ara[i+1]);
//                }
                flag1 = true;
                keep = i-1;
                keep2 = i;
            }
            else {
                flag1 = false;
                swap(ara[i], ara[keep]);
                break;
            }
        }
    }

    if(flag1) swap(ara[keep], ara[keep2]);

    for(int i=2; i<=n; i++) if(ara[i] < ara[i-1]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;

}
